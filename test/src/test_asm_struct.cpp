#include <iostream>
#include "asm_struct.h"  

int main() {
    using namespace KTC;
    
    // 创建一个汇编代码段
    AsmSection text_section(".text");
    RcSymIdx label=std::make_shared<std::string>(".main");
    // 添加全局标签
    Imm global_label = Imm::new_global_label(label);
    text_section.addGlobal(global_label);
    
    // 添加数据段
    text_section.addData();
    
    // 添加一个对齐属性
    text_section.addAlign(4);
    
    // 添加一个 Word 立即数（例如 42）
    Imm word_imm = Imm::new_literal_isize(42);
    text_section.addWord(word_imm);
    
    // 添加一个 Zero 指令
    text_section.addZero(8);
    
    // 添加标签
    Imm label_imm = Imm::new_local_label(label);
    text_section.addLabel(label_imm);
    
    //指令
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
    text_section.addInstruction(instr1);
    text_section.addInstruction(instr2);
    text_section.addInstruction(instr3);
    text_section.addInstruction(instr4);
    text_section.addInstruction(instr5);
    text_section.addInstruction(instr6);
    text_section.addInstruction(instr7);
    text_section.addInstruction(instr8);
    text_section.addInstruction(instr9);
    text_section.addInstruction(instr10);
    text_section.addInstruction(instr);
    // 打印汇编代码
    std::cout << text_section.dump(true) << std::endl;
    
    return 0;
}
