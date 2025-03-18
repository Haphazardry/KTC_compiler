#include "ast2cfg.h"

#include <vector>

#include "SysYParser.h"
#include "symtab.h"
#include "SysYBaseVisitor.h"
namespace KTC {
SymTab generateSymTab(SysYParser::VarDeclContext *ctx){
    std::vector<Scope> Scopes;
    SymTab symtab;
    
    std::string varName = ctx->bType()->getText();//获取类型
    // Identifier()->getText();  // 获取变量名
    // std::string varType = ctx->type()->getText();        // 获取变量类型

     // 获取变量类型（假设你的语法里有 type 规则）
    return symtab;
}

}