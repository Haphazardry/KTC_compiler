
// Generated from SysY.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SysYParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SysYParser.
 */
class  SysYVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SysYParser.
   */
    virtual std::any visitCompUnit(SysYParser::CompUnitContext *context) = 0;

    virtual std::any visitDecl(SysYParser::DeclContext *context) = 0;

    virtual std::any visitConstDecl(SysYParser::ConstDeclContext *context) = 0;

    virtual std::any visitBType(SysYParser::BTypeContext *context) = 0;

    virtual std::any visitConstDef(SysYParser::ConstDefContext *context) = 0;

    virtual std::any visitConstInitVal(SysYParser::ConstInitValContext *context) = 0;

    virtual std::any visitVarDecl(SysYParser::VarDeclContext *context) = 0;

    virtual std::any visitVarDef(SysYParser::VarDefContext *context) = 0;

    virtual std::any visitInitVal(SysYParser::InitValContext *context) = 0;

    virtual std::any visitFuncDef(SysYParser::FuncDefContext *context) = 0;

    virtual std::any visitFuncType(SysYParser::FuncTypeContext *context) = 0;

    virtual std::any visitFuncFParams(SysYParser::FuncFParamsContext *context) = 0;

    virtual std::any visitFuncFParam(SysYParser::FuncFParamContext *context) = 0;

    virtual std::any visitBlock(SysYParser::BlockContext *context) = 0;

    virtual std::any visitBlockItem(SysYParser::BlockItemContext *context) = 0;

    virtual std::any visitAssignStat(SysYParser::AssignStatContext *context) = 0;

    virtual std::any visitSemiStat(SysYParser::SemiStatContext *context) = 0;

    virtual std::any visitBlockStat(SysYParser::BlockStatContext *context) = 0;

    virtual std::any visitIfStat(SysYParser::IfStatContext *context) = 0;

    virtual std::any visitWhileStat(SysYParser::WhileStatContext *context) = 0;

    virtual std::any visitBreakStat(SysYParser::BreakStatContext *context) = 0;

    virtual std::any visitContinueStat(SysYParser::ContinueStatContext *context) = 0;

    virtual std::any visitReturnStat(SysYParser::ReturnStatContext *context) = 0;

    virtual std::any visitExp(SysYParser::ExpContext *context) = 0;

    virtual std::any visitCond(SysYParser::CondContext *context) = 0;

    virtual std::any visitLVal(SysYParser::LValContext *context) = 0;

    virtual std::any visitPrimaryExp(SysYParser::PrimaryExpContext *context) = 0;

    virtual std::any visitPrimaryExpr(SysYParser::PrimaryExprContext *context) = 0;

    virtual std::any visitFunctionExpr(SysYParser::FunctionExprContext *context) = 0;

    virtual std::any visitSignExpr(SysYParser::SignExprContext *context) = 0;

    virtual std::any visitFuncRParams(SysYParser::FuncRParamsContext *context) = 0;

    virtual std::any visitMulExp(SysYParser::MulExpContext *context) = 0;

    virtual std::any visitAddExp(SysYParser::AddExpContext *context) = 0;

    virtual std::any visitRelExp(SysYParser::RelExpContext *context) = 0;

    virtual std::any visitEqExp(SysYParser::EqExpContext *context) = 0;

    virtual std::any visitLAndExp(SysYParser::LAndExpContext *context) = 0;

    virtual std::any visitLOrExp(SysYParser::LOrExpContext *context) = 0;

    virtual std::any visitConstExp(SysYParser::ConstExpContext *context) = 0;


};

