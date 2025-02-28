#include "rv64_instr.h"
// #include "include/rv64_instr.h"
#include <iostream>
#include <sstream>
#include <vector>
int main() {
    using namespace KTC;
    Register sp = Register::new_sp();
    Register s0 = Register::new_s0();
    Register ra = Register::new_ra();
    Register a0 = Register::new_a(0);
    Register a5 = Register::new_a(5);
    Register nouse = Register::new_t(0); // 不使用
    Imm immn32 = Imm::new_literal_isize(-32);
    Imm imm24 = Imm::new_literal_isize(24);
    Imm imm7 = Imm::new_literal_isize(7);
    Imm immn20 = Imm::new_literal_isize(-20);

    // 此处定义指令
    RV64Instr instr1(Arithmetic(Arithmetic::Type::ADDI, sp, sp, immn32));
    RV64Instr instr2(Stores(Stores::Type::SD, s0, sp, imm24));
    RV64Instr instr3(Arithmetic(Arithmetic::Type::ADDI, s0, sp,immn32));
    RV64Instr instr4(PseudoInstr(PseudoInstr::Type::Li, a5, imm7));
    RV64Instr instr5(Stores(Stores::Type::SW, s0, a5, immn20));
    RV64Instr instr6(Loads(Loads::Type::LW, s0, a5, immn20));
    RV64Instr instr7(PseudoInstr(PseudoInstr::Type::Mv, a0, a5));
    RV64Instr instr8(Loads(Loads::Type::LD, sp, s0, imm24));
    RV64Instr instr9(Arithmetic(Arithmetic::Type::ADDI, sp, sp, immn32));
    RV64Instr instr10(PseudoInstr(PseudoInstr::Type::Jr, ra));

    RV64Instr instr(Shifts(Shifts::Type::Slli, sp, sp,  immn32));

    std::vector<RV64Instr> instr_vec = 
        {instr1, instr2, instr3, instr4, instr5, instr6, instr7, instr8, instr9, instr10};
    
    std::ostringstream oss; 

    for (auto& instr : instr_vec) {
        instr.get_string(oss);
    }
    // 此处输出
    std::cout << oss.str() << std::endl;

    return 0;

}