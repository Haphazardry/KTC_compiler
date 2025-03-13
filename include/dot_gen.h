#pragma once
#include "SysYVisitor.h"
#include "regtab.h"
#include <any>
#include <iostream>
#include <ostream>
namespace KTC{
    //vim 操作
    //q开始记录宏 --qq 开启绑定q为宏
    // --/  搜索   f 行内搜索单字符
    // --n 搜索到下一个(/)  --N 上
    // v选择模式
    // j 下 k 上 h左 l右
    // vaw 选择一个词  V 选中整行
    // a光标后输入 ，i 插入  o 下一行输入 shift i 行首 shift a 行末尾 $ 0
    // < , >可整行缩进
    // p 粘贴  y 复制
    // x删除
    // g行  gg首行 G末尾 3g 第三行 
    //@_ 调用宏  2@_  u撤销 
    // bb删除整行
    class MyVisitor:SysYVisitor{
    public:
    std::ostringstream oss;
    MyVisitor():oss(){}
    void visitTree(antlr4::tree::ParseTree *tree) {
        this->visit(tree);  // 这样保证外部可以调用
    }
    virtual std::any visitCompUnit(SysYParser::CompUnitContext *context){
        oss << context->getText() << std::endl;
        return visitChildren(context);
    }

    virtual std::any visitDecl(SysYParser::DeclContext *context) {
        oss << context->getText();
        return visitChildren(context);
    }
    

    virtual std::any visitConstDecl(SysYParser::ConstDeclContext *context) {
        oss << context->getText();
        return visitChildren(context);
    }

    virtual std::any visitBType(SysYParser::BTypeContext *context) {
        oss << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitConstDef(SysYParser::ConstDefContext *context) {
        oss << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitConstInitVal(SysYParser::ConstInitValContext *context) {
        oss << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitVarDecl(SysYParser::VarDeclContext *context) {
        oss << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitVarDef(SysYParser::VarDefContext *context) {
        oss << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitInitVal(SysYParser::InitValContext *context) {
        oss << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitFuncDef(SysYParser::FuncDefContext *context) {
        oss << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitFuncType(SysYParser::FuncTypeContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitFuncFParams(SysYParser::FuncFParamsContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitFuncFParam(SysYParser::FuncFParamContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitBlock(SysYParser::BlockContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitBlockItem(SysYParser::BlockItemContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitAssignStat(SysYParser::AssignStatContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitSemiStat(SysYParser::SemiStatContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitBlockStat(SysYParser::BlockStatContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitIfStat(SysYParser::IfStatContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitWhileStat(SysYParser::WhileStatContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitBreakStat(SysYParser::BreakStatContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitContinueStat(SysYParser::ContinueStatContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitReturnStat(SysYParser::ReturnStatContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitExp(SysYParser::ExpContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitCond(SysYParser::CondContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitLVal(SysYParser::LValContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitPrimaryExp(SysYParser::PrimaryExpContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitPrimaryExpr(SysYParser::PrimaryExprContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitFunctionExpr(SysYParser::FunctionExprContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitSignExpr(SysYParser::SignExprContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitFuncRParams(SysYParser::FuncRParamsContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitMulExp(SysYParser::MulExpContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitAddExp(SysYParser::AddExpContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitRelExp(SysYParser::RelExpContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitEqExp(SysYParser::EqExpContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitLAndExp(SysYParser::LAndExpContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitLOrExp(SysYParser::LOrExpContext *context){
        oss << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitConstExp(SysYParser::ConstExpContext *context){
        oss << context->getText();
        return visitChildren(context);
    }

}; 
    
}
