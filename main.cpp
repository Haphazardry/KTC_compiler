#include "rv64_instr.h"
int main() {
    using namespace KTC;
    Register rd = Register::new_a(0);
    Register rs1 = Register::new_s(1);
    Register rs2 = Register::new_t(2);
    Imm imm = Imm::new_literal_isize(42);

    PseudoInstr instr(PseudoInstr::Type::Ble, rd, rs1, imm);
    std::cout << instr << std::endl;
    std::cout << "结束\n";
    return 0;
}