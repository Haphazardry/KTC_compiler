#pragma  once
#include <unordered_map>
#include "rv64_instr.h"
#include <algorithm>
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
    using SymIdx = std::shared_ptr<std::string>;
    
    // 追踪寄存器状态的枚举
    enum class RegStateType{ Occupied, Freed, Released };
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
    };
    // RegTab 结构体
    class RegTab {
        private:
            std::unordered_map<Register, RegState > reg_symidx_map;
            std::vector<Register> gpr_released_regs;//存指针性能更好，但需要调整find
            std::vector<Register> fpr_released_regs;
        
        public:
            RegTab() {
                for (int i = 0; i < NUM_ARG; i++) {
                    Register reg = Register::new_a(i);
                    reg_symidx_map[reg] = RegState::new_released();
                    gpr_released_regs.push_back(reg);
                }
                // T 寄存器（临时寄存器），数量：NUM_T
                for (int i = 0; i < NUM_TEMP; i++) {
                    Register reg = Register::new_t(i);
                    reg_symidx_map[reg] = RegState::new_released();
                    gpr_released_regs.push_back(reg);
                }
                // S 寄存器（保存寄存器）：s0 单独处理，再 s1 到 s(NUM_S-1)
                {
                    Register reg = Register::new_s0();
                    reg_symidx_map[reg] = RegState::new_released();
                    gpr_released_regs.push_back(reg);
                }
                for (int i = 1; i < NUM_SAVED; i++) {
                    Register reg = Register::new_s(i);
                    reg_symidx_map[reg] = RegState::new_released();
                    gpr_released_regs.push_back(reg);
                }
                // 初始化 FPR 寄存器：FArg 和 FSaved
                // FA 寄存器（浮点参数寄存器），数量：NUM_FA
                for (int i = 0; i < NUM_FARG; i++) {
                    Register reg = Register::new_fa(i);
                    reg_symidx_map[reg] = RegState::new_released();
                    fpr_released_regs.push_back(reg);
                }
                // FS 寄存器（浮点保存寄存器），数量：NUM_FS
                for (int i = 0; i < NUM_FSAVED; i++) {
                    Register reg = Register::new_fs(i);
                    reg_symidx_map[reg] = RegState::new_released();
                    fpr_released_regs.push_back(reg);
                }
            }
            // 占用寄存器：将寄存器状态置为 Occupied，并从 available vector 中移除
            bool occupy_reg(Register reg, SymIdx symidx, bool tracked) {
                auto it = reg_symidx_map.find(reg);
                if (it == reg_symidx_map.end())
                    throw std::runtime_error("Illegal register access");

                RegState& regstat = it->second;
                if (regstat.state == RegStateType::Released) {
                    regstat = RegState::new_occupied(symidx, tracked, 1);
                    // 根据寄存器类型，从对应的容器中移除该寄存器
                    if (reg.is_gpr()) {
                        auto pos = std::find(gpr_released_regs.begin(), gpr_released_regs.end(), reg);
                        if (pos != gpr_released_regs.end()) {
                            gpr_released_regs.erase(pos);
                        }
                    } else {
                        auto pos = std::find(fpr_released_regs.begin(), fpr_released_regs.end(), reg);
                        if (pos != fpr_released_regs.end()) {
                            fpr_released_regs.erase(pos);
                        }
                    }
                    return true;
                }
                return false;
            }

            // 查找一个可用的寄存器并占用
            Register find_and_anonymous_occupy(SymIdx symidx) {
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