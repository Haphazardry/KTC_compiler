#include "rv64_instr.h"
#include <iostream>
#include <sstream>
int main() {
    using namespace KTC;
    Register sp = Register::new_sp();
    Register s0 = Register::new_s(0);
    Register a5 = Register::new_a(5);
    Imm immn32 = Imm::new_literal_isize(-32);
    Imm imm24 = Imm::new_literal_isize(24);
    Imm imm7 = Imm::new_literal_isize(7);
    Imm immn20 = Imm::new_literal_isize(-20);
    // BaseIntInstr instr(::Type::ADDI, sp, sp, immn32);
    // PseudoInstr instr(PseudoInstr::Type::);
    // PseudoInstr instr(PseudoInstr::Type::);
    // PseudoInstr instr(PseudoInstr::Type::);
    // PseudoInstr instr(PseudoInstr::Type::);
    // PseudoInstr instr(PseudoInstr::Type::);
    // PseudoInstr instr(PseudoInstr::Type::);
    // PseudoInstr instr(PseudoInstr::Type::);
    // PseudoInstr instr(PseudoInstr::Type::);
    // PseudoInstr instr(PseudoInstr::Type::);
    // PseudoInstr instr(PseudoInstr::Type::);

    // std::cout << instr << std::endl;
    // std::cout << "结束\n";

    // 此处输出
    std::ostringstream oss;
    oss.str();
    std::cout << oss.str() << std::endl;

    return 0;

}