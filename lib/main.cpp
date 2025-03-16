// #include "rv64_instr.h"
// // #include "include/rv64_instr.h"
// #include <iostream>
// #include <sstream>
// #include <vector>
// int main() {
//     using namespace KTC;
//     Register sp = Register::new_sp();
//     Register s0 = Register::new_s0();
//     Register ra = Register::new_ra();
//     Register a0 = Register::new_a(0);
//     Register a5 = Register::new_a(5);
//     Register nouse = Register::new_t(0); // 不使用
//     Imm immn32 = Imm::new_literal_isize(-32);
//     Imm imm24 = Imm::new_literal_isize(24);
//     Imm imm7 = Imm::new_literal_isize(7);
//     Imm immn20 = Imm::new_literal_isize(-20);

//     // 此处定义指令
//     RV64Instr instr1(Arithmetic(Arithmetic::Type::ADDI, sp, sp, immn32));
//     RV64Instr instr2(Stores(Stores::Type::SD, s0, sp, imm24));
//     RV64Instr instr3(Arithmetic(Arithmetic::Type::ADDI, s0, sp,immn32));
//     RV64Instr instr4(PseudoInstr(PseudoInstr::Type::Li, a5, imm7));
//     RV64Instr instr5(Stores(Stores::Type::SW, s0, a5, immn20));
//     RV64Instr instr6(Loads(Loads::Type::LW, s0, a5, immn20));
//     RV64Instr instr7(PseudoInstr(PseudoInstr::Type::Mv, a0, a5));
//     RV64Instr instr8(Loads(Loads::Type::LD, sp, s0, imm24));
//     RV64Instr instr9(Arithmetic(Arithmetic::Type::ADDI, sp, sp, immn32));
//     RV64Instr instr10(PseudoInstr(PseudoInstr::Type::Jr, ra));

//     RV64Instr instr(Shifts(Shifts::Type::Slli, sp, sp,  immn32));

//     std::vector<RV64Instr> instr_vec = 
//         {instr1, instr2, instr3, instr4, instr5, instr6, instr7, instr8, instr9, instr10};
    
//     std::ostringstream oss; 

//     for (auto& instr : instr_vec) {
//         instr.get_string(oss);
//     }
//     // 此处输出
//     std::cout << oss.str() << std::endl;

//     return 0;

// }
#include <iostream>
#include <fstream>
#include "SysYParser.h"
#include "antlr4-runtime.h"
#include "SysYLexer.h"
#include "SysYParser.h"
#include "dot_gen.h"
#include "rv64_instr.h"
using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[]) {
    // 确保提供了输入文件
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input file>" << endl;
        return 1;
    }

    // 打开输入文件
    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << argv[1] << endl;
        return 1;
    }

    // 将输入文件内容传递给 ANTLR 输入流
    ANTLRInputStream input(inputFile);

    // 创建词法分析器
    SysYLexer lexer(&input);

    // 生成令牌流
    CommonTokenStream tokens(&lexer);

    // 创建语法分析器
    SysYParser parser(&tokens);

    // 解析源代码
    tree::ParseTree* tree = parser.compUnit(); // 假设 'program' 是 C 语法中的入口规则

    // 输出解析树（用于调试）`
    cout << "Parse Tree: " << endl;
    cout << tree->toStringTree(&parser) << endl;
    std::vector<std::string> ruleNames = parser.getRuleNames();
    cout << "My Visitor:";
    KTC::MyVisitor visitor("AST.dot",ruleNames);
    visitor.visitTree(tree);
    return 0;
}
