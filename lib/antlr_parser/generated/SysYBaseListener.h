
// Generated from SysY.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "SysYListener.h"


/**
 * This class provides an empty implementation of SysYListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SysYBaseListener : public SysYListener {
public:

  virtual void enterCompUnit(SysYParser::CompUnitContext * /*ctx*/) override { }
  virtual void exitCompUnit(SysYParser::CompUnitContext * /*ctx*/) override { }

  virtual void enterDecl(SysYParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(SysYParser::DeclContext * /*ctx*/) override { }

  virtual void enterConstDecl(SysYParser::ConstDeclContext * /*ctx*/) override { }
  virtual void exitConstDecl(SysYParser::ConstDeclContext * /*ctx*/) override { }

  virtual void enterBType(SysYParser::BTypeContext * /*ctx*/) override { }
  virtual void exitBType(SysYParser::BTypeContext * /*ctx*/) override { }

  virtual void enterConstDef(SysYParser::ConstDefContext * /*ctx*/) override { }
  virtual void exitConstDef(SysYParser::ConstDefContext * /*ctx*/) override { }

  virtual void enterConstInitVal(SysYParser::ConstInitValContext * /*ctx*/) override { }
  virtual void exitConstInitVal(SysYParser::ConstInitValContext * /*ctx*/) override { }

  virtual void enterVarDecl(SysYParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(SysYParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterVarDef(SysYParser::VarDefContext * /*ctx*/) override { }
  virtual void exitVarDef(SysYParser::VarDefContext * /*ctx*/) override { }

  virtual void enterInitVal(SysYParser::InitValContext * /*ctx*/) override { }
  virtual void exitInitVal(SysYParser::InitValContext * /*ctx*/) override { }

  virtual void enterFuncDef(SysYParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(SysYParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterFuncType(SysYParser::FuncTypeContext * /*ctx*/) override { }
  virtual void exitFuncType(SysYParser::FuncTypeContext * /*ctx*/) override { }

  virtual void enterFuncFParams(SysYParser::FuncFParamsContext * /*ctx*/) override { }
  virtual void exitFuncFParams(SysYParser::FuncFParamsContext * /*ctx*/) override { }

  virtual void enterFuncFParam(SysYParser::FuncFParamContext * /*ctx*/) override { }
  virtual void exitFuncFParam(SysYParser::FuncFParamContext * /*ctx*/) override { }

  virtual void enterBlock(SysYParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(SysYParser::BlockContext * /*ctx*/) override { }

  virtual void enterBlockItem(SysYParser::BlockItemContext * /*ctx*/) override { }
  virtual void exitBlockItem(SysYParser::BlockItemContext * /*ctx*/) override { }

  virtual void enterAssignStat(SysYParser::AssignStatContext * /*ctx*/) override { }
  virtual void exitAssignStat(SysYParser::AssignStatContext * /*ctx*/) override { }

  virtual void enterSemiStat(SysYParser::SemiStatContext * /*ctx*/) override { }
  virtual void exitSemiStat(SysYParser::SemiStatContext * /*ctx*/) override { }

  virtual void enterBlockStat(SysYParser::BlockStatContext * /*ctx*/) override { }
  virtual void exitBlockStat(SysYParser::BlockStatContext * /*ctx*/) override { }

  virtual void enterIfStat(SysYParser::IfStatContext * /*ctx*/) override { }
  virtual void exitIfStat(SysYParser::IfStatContext * /*ctx*/) override { }

  virtual void enterWhileStat(SysYParser::WhileStatContext * /*ctx*/) override { }
  virtual void exitWhileStat(SysYParser::WhileStatContext * /*ctx*/) override { }

  virtual void enterBreakStat(SysYParser::BreakStatContext * /*ctx*/) override { }
  virtual void exitBreakStat(SysYParser::BreakStatContext * /*ctx*/) override { }

  virtual void enterContinueStat(SysYParser::ContinueStatContext * /*ctx*/) override { }
  virtual void exitContinueStat(SysYParser::ContinueStatContext * /*ctx*/) override { }

  virtual void enterReturnStat(SysYParser::ReturnStatContext * /*ctx*/) override { }
  virtual void exitReturnStat(SysYParser::ReturnStatContext * /*ctx*/) override { }

  virtual void enterExp(SysYParser::ExpContext * /*ctx*/) override { }
  virtual void exitExp(SysYParser::ExpContext * /*ctx*/) override { }

  virtual void enterCond(SysYParser::CondContext * /*ctx*/) override { }
  virtual void exitCond(SysYParser::CondContext * /*ctx*/) override { }

  virtual void enterLVal(SysYParser::LValContext * /*ctx*/) override { }
  virtual void exitLVal(SysYParser::LValContext * /*ctx*/) override { }

  virtual void enterPrimaryExp(SysYParser::PrimaryExpContext * /*ctx*/) override { }
  virtual void exitPrimaryExp(SysYParser::PrimaryExpContext * /*ctx*/) override { }

  virtual void enterPrimaryExpr(SysYParser::PrimaryExprContext * /*ctx*/) override { }
  virtual void exitPrimaryExpr(SysYParser::PrimaryExprContext * /*ctx*/) override { }

  virtual void enterFunctionExpr(SysYParser::FunctionExprContext * /*ctx*/) override { }
  virtual void exitFunctionExpr(SysYParser::FunctionExprContext * /*ctx*/) override { }

  virtual void enterSignExpr(SysYParser::SignExprContext * /*ctx*/) override { }
  virtual void exitSignExpr(SysYParser::SignExprContext * /*ctx*/) override { }

  virtual void enterFuncRParams(SysYParser::FuncRParamsContext * /*ctx*/) override { }
  virtual void exitFuncRParams(SysYParser::FuncRParamsContext * /*ctx*/) override { }

  virtual void enterMulExp(SysYParser::MulExpContext * /*ctx*/) override { }
  virtual void exitMulExp(SysYParser::MulExpContext * /*ctx*/) override { }

  virtual void enterAddExp(SysYParser::AddExpContext * /*ctx*/) override { }
  virtual void exitAddExp(SysYParser::AddExpContext * /*ctx*/) override { }

  virtual void enterRelExp(SysYParser::RelExpContext * /*ctx*/) override { }
  virtual void exitRelExp(SysYParser::RelExpContext * /*ctx*/) override { }

  virtual void enterEqExp(SysYParser::EqExpContext * /*ctx*/) override { }
  virtual void exitEqExp(SysYParser::EqExpContext * /*ctx*/) override { }

  virtual void enterLAndExp(SysYParser::LAndExpContext * /*ctx*/) override { }
  virtual void exitLAndExp(SysYParser::LAndExpContext * /*ctx*/) override { }

  virtual void enterLOrExp(SysYParser::LOrExpContext * /*ctx*/) override { }
  virtual void exitLOrExp(SysYParser::LOrExpContext * /*ctx*/) override { }

  virtual void enterConstExp(SysYParser::ConstExpContext * /*ctx*/) override { }
  virtual void exitConstExp(SysYParser::ConstExpContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

