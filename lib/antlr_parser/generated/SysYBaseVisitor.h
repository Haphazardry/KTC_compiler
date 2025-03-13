
// Generated from SysY.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SysYVisitor.h"


/**
 * This class provides an empty implementation of SysYVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SysYBaseVisitor : public SysYVisitor {
public:

  virtual std::any visitCompUnit(SysYParser::CompUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl(SysYParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDecl(SysYParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBType(SysYParser::BTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDef(SysYParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstInitVal(SysYParser::ConstInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(SysYParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDef(SysYParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitVal(SysYParser::InitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(SysYParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncType(SysYParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFParams(SysYParser::FuncFParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFParam(SysYParser::FuncFParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(SysYParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItem(SysYParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignStat(SysYParser::AssignStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSemiStat(SysYParser::SemiStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockStat(SysYParser::BlockStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStat(SysYParser::IfStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStat(SysYParser::WhileStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStat(SysYParser::BreakStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStat(SysYParser::ContinueStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStat(SysYParser::ReturnStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp(SysYParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCond(SysYParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLVal(SysYParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExp(SysYParser::PrimaryExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimaryExpr(SysYParser::PrimaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionExpr(SysYParser::FunctionExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSignExpr(SysYParser::SignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncRParams(SysYParser::FuncRParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulExp(SysYParser::MulExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExp(SysYParser::AddExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelExp(SysYParser::RelExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqExp(SysYParser::EqExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLAndExp(SysYParser::LAndExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLOrExp(SysYParser::LOrExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExp(SysYParser::ConstExpContext *ctx) override {
    return visitChildren(ctx);
  }


};

