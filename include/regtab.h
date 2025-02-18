#pragma  once
#include <unordered_map>
#include <algorithm>

#include "log.h"
#include "rv64_instr.h"
#include "asm_struct.h"
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

// 定义寄存器枚举
namespace KTC{
    // 追踪寄存器状态的枚举
    enum class RegStateType{ 
        Occupied,//占用
        Freed, //使用时需条件（）
        Released 
    };
    // RegState 结构体
    struct RegState {
        RegStateType state;
        SymIdx symidx;
        bool tracked;
        size_t occupy_count;

        static RegState new_occupied(SymIdx symidx, bool tracked, unsigned int count) {
            return {RegStateType::Occupied, symidx, tracked, count};
        }

        static RegState new_freed(SymIdx symidx, bool tracked) {
            return {RegStateType::Freed, symidx, tracked, 0};
        }

        static RegState new_released() {
            return {RegStateType::Released, std::make_shared<std::string>("None"), false, 0};
        }

        bool free_once() {
            if (state == RegStateType::Occupied) {
                if (occupy_count > 1) {
                    occupy_count--;
                    return true;
                } else if (occupy_count == 1) {
                    state = RegStateType::Freed;
                    return true;
                }
            }
            throw std::runtime_error("Cannot free a non-occupied register");
        }
    
        friend std::ostream& operator<<(std::ostream& os, const RegState& RegState);
        
    };
    std::ostream& operator<<(std::ostream& os, const RegState& RegState){
        os<< "这里是regstate流入符号的重载";
        return os;
    }
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
                        !(regstat.symidx != symidx || regstat.tracked!= tracked),
                        "you can't occupy " << regstat << " by " << symidx << " is_temp: " << tracked);
                    regstat.occupy_count+=1;
                    break;
                case RegStateType::Freed:
                    ASSERT_LOG(!(regstat.symidx != symidx || regstat.tracked!= tracked),"you can't occupy " << regstat );
                    regstat = RegState::new_occupied(symidx, tracked, 1);
                    break;
                }

            }

            // 查找一个可用的寄存器并占用
            Register find_and_anonymous_occupy(SymIdx symidx,SymTab& symtab,AsmSection& asmsection) {
                // 先从 GPR 中查找
                if (!gpr_released_regs.empty()) {
                    Register reg = gpr_released_regs.back();
                    occupy_reg(reg, symidx, false);
                    return reg;
                }
                // 若 GPR 不足，再从 FPR 中查找
                if (!fpr_released_regs.empty()) {
                    Register reg = fpr_released_regs.back();
                    occupy_reg(reg, symidx, false);
                    return reg;
                }
                throw std::runtime_error("No available registers");
            
                };
        };


}