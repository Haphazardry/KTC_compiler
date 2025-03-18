#pragma once
#include <optional>
#include <vector>
#include "tree/ParseTree.h"
#include "symtab.h"
namespace KTC {
//变量名 蛇形命名法
//函数名 小驼峰
//类名 大驼峰
//常量 全大写加下划线
class Scope{
public:
    unsigned int uid=0;
    std::vector<SymIdx>  local_symbols;
    Scope(){}
    void addSymbol(SymIdx symbol);
    std::optional<SymIdx> findSymbol();

};
SymTab generateSymTab(antlr4::tree::ParseTree *tree);
}
