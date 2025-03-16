/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* KTC Declarations                                                           *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: ktc.td                                                               *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#include <optional>
#include <variant>
#include <vector>
#include <memory>

class Add {
    RcSymIdx Lhs;
    RcSymIdx Rhs;
    Type VarType;
};

class Alloc {
};

class Arith {
    RcSymIdx Lhs;
    ArithOp Rhs;
};

class Array {
    std::vector<std::optional<RcSymIdx>> Dims;
    std::shared_ptr<Type> EleTy;
};

class BBLabel {
    RcSymIdx LabelSymidx;
};

class Bitcast {
    RcSymIdx RptrSymIdx;
    Type RptrType;
    Type CastType;
};

class Br {
    RcSymIdx cond;
    RcSymIdx t1;
    RcSymIdx t2;
};

class BreakPoint {
    RcSymIdx SymIdx;
    std::vector<BreakPointArg> BreakpointArgs;
};

class BreakPointArg {
    RcSymIdx SymIdx;
    std::optional<std::string> OpFieldName;
};

class Call {
    std::optional<RcSymIdx> OpLhs;
    FuncOp Runc;
};

class Chi {
    RcSymIdx Lhs;
    RcSymIdx Rhs;
    int MayUseInstr;
};

class ComparedPair {
    RcSymIdx Compared;
    RcSymIdx Label;
};

class DefineFunc {
    RcSymIdx func_symidx;
    RcSymIdx ret_symidx;
    std::vector<RcSymIdx> args;
};

class DefineVar {
};

class DirectJump {
    RcSymIdx LabelSymIdx;
};

class Div {
    RcSymIdx Lhs;
    RcSymIdx Rhs;
    Type VarType;
};

class F32 {
};

class Fcmp {
    FcmpPlan Plan;
    RcSymIdx Lhs;
    RcSymIdx Rhs;
    Type VarType;
};

class Fn {
    std::vector<RcSymIdx> ArgSyms;
    RcSymIdx RetSym;
};

class Fptosi {
    RcSymIdx FloatSymIdx;
};

class FuncOp {
    RcSymIdx RcFuncSymIdx;
    std::vector<RcSymIdx> ActualArgSymIdxVec;
    Type RetType;
};

class GetElementPtr {
    RcSymIdx Lhs;
    RcSymIdx PtrSymIdx;
    Type ArrayTy;
    std::vector<std::optional<RcSymIdx>> IdxVec;
};

class Globl {
};

class I1 {
};

class I32 {
};

class Icmp {
    IcmpPlan Plan;
    RcSymIdx Lhs;
    RcSymIdx Rhs;
    Type VarType;
};

class Jump {
    std::optional<RcSymIdx> OpLhs;
    JumpOp Runc;
};

class Label {
};

class Load {
};

class LogicAnd {
    RcSymIdx Lhs;
    RcSymIdx Rhs;
    Type VarType;
};

class LogicNot {
    RcSymIdx Lhs;
    Type VarType;
};

class LogicOr {
    RcSymIdx Lhs;
    RcSymIdx Rhs;
    Type VarType;
};

class Mod {
    RcSymIdx Lhs;
    RcSymIdx Rhs;
    Type VarType;
};

class Mu {
    RcSymIdx Mu;
    int MayUseInstr;
};

class Mul {
    RcSymIdx Lhs;
    RcSymIdx Rhs;
    Type VarType;
};

class Nope {
};

class Phi {
    RcSymIdx Lhs;
    PhiOp Rhs;
};

class PhiOp {
    std::vector<PhiPair> PhiPairs;
};

class PhiPair {
    RcSymIdx SymIdx;
    int DefInstr;
    int CommingCfgNode;
};

class Ptr64 {
    Type Ty;
};

class RcSymIdx {
    std::shared_ptr<SymIdx> RcSymIdx;
};

class Ref {
};

class Ret {
    std::optional<RcSymIdx> OpRetSym;
};

class SimpleAssign {
    RcSymIdx Lhs;
    RcSymIdx Rhs;
    Type VarType;
};

class SitoFp {
    RcSymIdx IntSymIdx;
};

class Store {
};

class Sub {
    RcSymIdx Lhs;
    RcSymIdx Rhs;
    Type VarType;
};

class Switch {
    RcSymIdx Cond;
    RcSymIdx Default;
    std::vector<ComparedPair> compared;
};

class SymIdx {
    int Value;
};

class TranType {
    RcSymIdx Lhs;
    Trans Op;
};

class Unknown {
};

class Untrack {
    RcSymIdx SymIdx;
};

class Void {
};

class Zext {
    RcSymIdx BoolSymIdx;
};

using ArithOp=std::variant<Add,Mul,Sub,Div,Mod,Icmp,Fcmp,LogicAnd,LogicOr,LogicNot>;
using JumpOp=std::variant<Ret,Br,Switch,DirectJump>;
using KtcInst=std::variant<BBLabel,DefineVar,DefineFunc,Alloc,Store,GetElementPtr,Arith,SimpleAssign,Call,Jump,Phi,Mu,Chi,Untrack,TranType,BreakPoint,Nope>;
using Trans=std::variant<Fptosi,SitoFp,Zext,Bitcast>;
using Type=std::variant<I32,F32,I1,Void,Label,Ref,Ptr64,Array,Fn,Unknown>;
enum class FcmpPlan {
    OEQ, // Ordered and equal
    ONE, // Ordered and not equal
    OGT, // Ordered and greater than
    OGE, // Ordered and greater than or equal
    OLT, // Ordered and less than
    OLE, // Ordered and less than or equal
};

enum class IcmpPlan {
    EQ, // Equal
    NE, // Not equal
    UGT, // Unsigned greater than
    UGE, // Unsigned greater than or equal
    ULT, // Unsigned less than
    ULE, // Unsigned less than or equal
    SGT, // Signed greater than
    SGE, // Signed greater than or equal
    SLT, // Signed less than
    SLE, // Signed less than or equal
};

