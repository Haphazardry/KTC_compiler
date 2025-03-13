#pragma  once
#include "builder.h"
#include <optional>
#include <ostream>
#include <unordered_map>
#include <algorithm>

#include "log.h"
#include "asm_struct.h"
#include "register.h"
#include "rv64_instr.h"
#include "symtab.h"
//寄存器哈希函数定义
namespace std {
    using KTC::Register;
    template <>
    struct hash<Register> {
        size_t operator()(const Register& reg) const {
            size_t h1 = std::hash<int>()(static_cast<int>(reg.type)); // 计算 type 的哈希值
            size_t h2 = std::hash<int>()(reg.reg_idx);                 // 计算 reg_idx 的哈希值
            return h1 ^ (h2 << 1); // 合并哈希值
        }
    };
}
//ir 的register查找先查找occupied 再查找freed 
// 定义寄存器枚举
namespace KTC{
    // 追踪寄存器状态的枚举
    enum class RegStateType{ 
        Occupied,//占用
        Freed, //其他ir复用
        Released //空
    };
    inline std::ostream& operator << (std::ostream& os , const RegStateType& type){
        switch(type){
            case RegStateType::Occupied: os <<"Occupied"; break;
            case RegStateType::Freed: os <<"Freed";break;
            case RegStateType::Released: os<<"Released";break;
        }
        return os;
    }

    // RegState 
    class RegState {
    public:
        RegStateType state;
        std::optional<SymIdx> symidx;
        std::optional<bool> tracked;//替换是否需要spill
        std::optional<size_t> occupy_count;

        // 构造函数初始化列表顺序与成员声明顺序保持一致
        RegState(){
            //regtab 的map中 在创建新的新时需要创建一个默认的值 如 
            //reg_symidx_map[reg] = RegState::new_released();中如果没有reg就先创建reg 和默认生成的state然后再给他重新赋值 
        }
        RegState(RegStateType state, std::optional<SymIdx> symidx, std::optional<bool>  tracked, std::optional<size_t> count)
            : state(state), symidx(symidx), tracked(tracked), occupy_count(count) {}
    
        // 工厂方法
        static RegState new_occupied(SymIdx symidx, bool tracked, unsigned int count) {
            return RegState(RegStateType::Occupied, symidx, tracked, count);
        }
    
        static RegState new_freed(SymIdx symidx, bool tracked) {
            return RegState(RegStateType::Freed, symidx, tracked, std::nullopt);
        }
    
        static RegState new_released() {
            return RegState(RegStateType::Released, std::nullopt, false, std::nullopt);
        }
        void occupied2freed(){
            occupy_count=std::nullopt;
            state=RegStateType::Freed;
        }
        // 状态转换方法
        bool free_once() {
            switch (state) {
            case RegStateType::Occupied:
                if(occupy_count.has_value()){
                    if (*occupy_count == 1) occupied2freed();
                    else *occupy_count -=1;
                    return true;
                }else ASSERT_LOG(false, "Invalid occupied");
                break;
            
            case RegStateType::Freed:
                ASSERT_LOG(false, "Cannot free a released register");
                break;
    
            case RegStateType::Released:
                ASSERT_LOG(false, "Cannot free a released register");
                break;
            default:
                ASSERT_LOG(false, "Invalid register state");
                break;
            }
            return false;
        }
    
        // 友元输出操作符
        friend std::ostream& operator<<(std::ostream& os, const RegState& rs){
            switch(rs.state){
                case RegStateType::Occupied:
                    os << "{state:"<<rs.state
                       << ", symidx:" << *rs.symidx
                       << ", tracked:" << (*rs.tracked ? "true" : "false")
                       << ", count:" << *rs.occupy_count << "}";
                    break;
                case RegStateType::Freed:
                    os << "{state:"<<rs.state
                    << ", symidx:" << *rs.symidx
                    << ", tracked:" << (*rs.tracked ? "true" : "false")<<"}";
                    break;
                case RegStateType::Released:
                    os << "{state:"<<rs.state<<"}";
                    break;
            }
            return os;
        };
    };
    // RegTab 结构体
    class RegTab {
        private:
            std::unordered_map<Register, RegState > reg_symidx_map;
            size_t gpr_released_reg_count;
            size_t fpr_released_reg_count;
        
        public:
            RegTab():gpr_released_reg_count(NUM_ARG+NUM_TEMP+NUM_SAVED),fpr_released_reg_count(NUM_FARG+NUM_FSAVED) {
                for (int i = 0; i < NUM_ARG; i++) {
                    Register reg = Register::new_a(i);
                    reg_symidx_map[reg] = RegState::new_released();
                }
                // T 寄存器（临时寄存器），数量：NUM_T
                for (int i = 0; i < NUM_TEMP; i++) {
                    Register reg = Register::new_t(i);
                    reg_symidx_map[reg] = RegState::new_released();

                }
                for (int i = 1; i < NUM_SAVED; i++) {
                    Register reg = Register::new_s(i);
                    reg_symidx_map[reg] = RegState::new_released();

                }
                // 初始化 FPR 寄存器：FArg 和 FSaved
                // FA 寄存器（浮点参数寄存器），数量：NUM_FA
                for (int i = 0; i < NUM_FARG; i++) {
                    Register reg = Register::new_fa(i);
                    reg_symidx_map[reg] = RegState::new_released();

                }
                // FS 寄存器（浮点保存寄存器），数量：NUM_FS
                for (int i = 0; i < NUM_FSAVED; i++) {
                    Register reg = Register::new_fs(i);
                    reg_symidx_map[reg] = RegState::new_released();

                }

            }
            // 占用寄存器：将寄存器状态置为 Occupied，并从 available vector 中移除
            void occupy_reg(Register reg, SymIdx symidx, bool tracked,SymTab& symtab,AsmSection& asmsection) {
                auto it = reg_symidx_map.find(reg);
                ASSERT_LOG(it != reg_symidx_map.end(),"Illegal register access");
                RegState& regstat = it->second;
                switch (regstat.state)
                {
                case RegStateType::Released:
                    regstat = RegState::new_occupied(symidx, tracked, 1);
                    if (reg.is_gpr()) {
                        gpr_released_reg_count-=1;
                    } 
                    else {
                        fpr_released_reg_count-=1;
                    }
                    if (tracked){
                        symtab.get(symidx).add_cur_reg(reg); 
                    }
                    break;
                case RegStateType::Occupied:
                    ASSERT_LOG(
                        !(*regstat.symidx != symidx || *regstat.tracked!= tracked),
                        "you can't occupy " << regstat << " by " << symidx << " is_temp: " << tracked);
                    *regstat.occupy_count+=1;
                    break;
                case RegStateType::Freed:
                    ASSERT_LOG(!(*regstat.symidx != symidx || *regstat.tracked!= tracked),"you can't occupy " << regstat );
                    regstat = RegState::new_occupied(symidx, tracked, 1);
                    break;
                }

            }

            bool symidx_should_track(const SymIdx& symidx, const SymTab& symtab) {
                SymIdx src_symidx = symidx.to_src_symidx();

                return symtab.has_symbol(symidx) &&//符号存在
                       !src_symidx.is_literal() &&//不是字面量
                       !src_symidx.is_global_ptr() &&//不是全局指针
                       !(symtab.get(src_symidx).get_is_global());//不是全局变量
            }
            
            
            // Register find_and_occupy_reg(
            //     const SymIdx& symidx,
            //     const TypeDiscriminants& sym_ty,
            //     SymTab& symtab,
            //     AsmSection& asm_sect,
            //     std::function<void(SymIdx, Register, SymTab&, AsmSection&, RegTab&)> store_f,
            //     std::function<void(SymIdx, Register, SymTab&, AsmSection&, RegTab&)> load_f
            // ) {
            //     bool should_track = symidx_should_track(symidx, symtab);
        
            //     // 如果符号已经在寄存器中
            //     if (should_track && symtab.has_symbol(symidx)) {
            //         Register reg;  // 假设从符号表中获得
            //         asm_sect.addAnnotation("symidx already in regtab");
            //         return reg;
            //     }
                
            //     // 处理字面量
            //     if (!should_track && symidx.is_literal()) {
            //         for (const auto& [reg, sym] : reg_symidx_map) {
            //             if (sym.symidx == symidx) {
            //                 asm_sect.addAnnotation("Found existing register for literal");
            //                 return reg;
            //             }
            //         }
            //     }
        
            //     // 分配新寄存器
            //     Register reg = find_avail_reg_for_ty_and_try_release(sym_ty, symtab, asm_sect, store_f);
            //     occupy_reg(reg, symidx,  should_track,symtab, asm_sect);
            //     load_f(symidx, reg, symtab, asm_sect, *this);
            //     return reg;
            // }
        
           
            // // 查找一个可用的寄存器并占用
            // Register find_and_anonymous_occupy(SymIdx symidx,SymTab& symtab,AsmSection& asmsection) {
               
            // };
             // 重载 operator<<
            friend std::ostream& operator<<(std::ostream& os, const RegTab& regTab) {
                os << "GPR Released Count: " << regTab.gpr_released_reg_count << "\n";
                os << "FPR Released Count: " << regTab.fpr_released_reg_count << "\n";
                os << "Register to State Map:\n";
                
                for (const auto& pair : regTab.reg_symidx_map) {
                    os << pair.first << " => " << pair.second << "\n";
                }

                return os;
            }
            
        };


}