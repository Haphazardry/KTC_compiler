#pragma once
#include "SysYParser.h"
#include "SysYVisitor.h"
#include "regtab.h"
#include "tree/ParseTree.h"
#include <any>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>
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
    //:%s/a/b/g 全局a替换为b
    class MyVisitor:SysYVisitor{
    public:
        std::ofstream dot;
        int nodeId =0;
        std::vector<std::string> ruleNames;
    MyVisitor(const std::string& filename,const std::vector<std::string>& ruleNames_):dot(),ruleNames(ruleNames_){
        dot.open(filename);
        if (!dot.is_open()) {
            std::cerr << "Failed to open file for writing!" << std::endl;
            exit(1);
        }
        dot << "digraph AST{\n";
        dot << "    node [shape=record];\n";
    }
    ~MyVisitor(){
        dot << "}\n";
        dot.close();
    }
    int generateNodeId() {
        return nodeId++;
    }

     /**
     *  递归遍历 AST 并生成 DOT 代码
     */
    std::string escapeLabel(const std::string& label) {
        //把 label 中的 所有双引号 " 替换成单引号 '以 避免 DOT 解析错误。
        std::string escaped = label;
        std::replace(escaped.begin(), escaped.end(), '"', '\'');  // 替换所有 " 为 '
        return escaped;
    }
    int visitNode(antlr4::tree::ParseTree* node) {
    if (!node) return -1;
    
    int currentNodeId = nodeId++;
    std::string label = escapeLabel(node->getText());

    std::string ruleName = "";
    if (auto* ctx = dynamic_cast<antlr4::ParserRuleContext*>(node)) {
        int ruleIndex = ctx->getRuleIndex();
        if (ruleIndex >= 0 && ruleIndex < ruleNames.size()) {
            ruleName = ruleNames[ruleIndex];
        }
    }

    // 输出节点的 DOT 描述，显示规则名称和节点文本
    dot << currentNodeId <<" [label=\"" << currentNodeId << " " << ruleName << ": " << label << "\", shape=record];\n";

    for (size_t i = 0; i < node->children.size(); ++i) {
        int childId = visitNode(node->children[i]);
        if (childId != -1) {
            dot << currentNodeId << " -> " << childId << ";\n";
        }
    }

    return currentNodeId;
}
    // int visitNode(antlr4::tree::ParseTree* node) {
    //     if (!node) return -1;  // 空节点返回

    //     int currentNodeId = nodeId++;  // 生成唯一 ID
    //     std::string label = escapeLabel(node->getText());

    //     // 输出 DOT 代码
    //     dot << "    " << currentNodeId << " [label=\"" << label << "\", shape=record];\n";

    //     // 遍历子节点
    //     for (size_t i = 0; i < node->children.size(); ++i) {
    //         int childId = visitNode(node->children[i]);  // 递归访问
    //         if (childId != -1) {
    //             dot << "    " << currentNodeId << " -> " << childId << ";\n";  // 连接边
    //         }
    //     }

    //     return currentNodeId;
    // }
    std::any visit(antlr4::tree::ParseTree* ctx) override {
        visitNode(ctx);  // 调用自定义的 visitNode
        return nullptr;
    }
    void visitTree(antlr4::tree::ParseTree *tree) {
        this->visit(tree);  
    }
    virtual std::any visitCompUnit(SysYParser::CompUnitContext *context){
        dot << context->getText() << std::endl;
        return visitChildren(context);
    }

    virtual std::any visitDecl(SysYParser::DeclContext *context) {
        dot << context->getText();
        return visitChildren(context);
    }
    

    virtual std::any visitConstDecl(SysYParser::ConstDeclContext *context) {
        dot << context->getText();
        return visitChildren(context);
    }

    virtual std::any visitBType(SysYParser::BTypeContext *context) {
        dot << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitConstDef(SysYParser::ConstDefContext *context) {
        dot << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitConstInitVal(SysYParser::ConstInitValContext *context) {
        dot << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitVarDecl(SysYParser::VarDeclContext *context) {
        dot << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitVarDef(SysYParser::VarDefContext *context) {
        dot << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitInitVal(SysYParser::InitValContext *context) {
        dot << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitFuncDef(SysYParser::FuncDefContext *context) {
        dot << context->getText();
        return visitChildren(context);
    }


    virtual std::any visitFuncType(SysYParser::FuncTypeContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitFuncFParams(SysYParser::FuncFParamsContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitFuncFParam(SysYParser::FuncFParamContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitBlock(SysYParser::BlockContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitBlockItem(SysYParser::BlockItemContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitAssignStat(SysYParser::AssignStatContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitSemiStat(SysYParser::SemiStatContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitBlockStat(SysYParser::BlockStatContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitIfStat(SysYParser::IfStatContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitWhileStat(SysYParser::WhileStatContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitBreakStat(SysYParser::BreakStatContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitContinueStat(SysYParser::ContinueStatContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitReturnStat(SysYParser::ReturnStatContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitExp(SysYParser::ExpContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitCond(SysYParser::CondContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitLVal(SysYParser::LValContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitPrimaryExp(SysYParser::PrimaryExpContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitPrimaryExpr(SysYParser::PrimaryExprContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitFunctionExpr(SysYParser::FunctionExprContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitSignExpr(SysYParser::SignExprContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitFuncRParams(SysYParser::FuncRParamsContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitMulExp(SysYParser::MulExpContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitAddExp(SysYParser::AddExpContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitRelExp(SysYParser::RelExpContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitEqExp(SysYParser::EqExpContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitLAndExp(SysYParser::LAndExpContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitLOrExp(SysYParser::LOrExpContext *context){
        dot << context->getText();
        return visitChildren(context);
    }
 

    virtual std::any visitConstExp(SysYParser::ConstExpContext *context){
        dot << context->getText();
        return visitChildren(context);
    }

}; 
    
}
