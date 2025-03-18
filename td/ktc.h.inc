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
#include <iostream>

class Add {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Alloc {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Arith {
public:

    RcSymIdx Lhs;
	ArithOp Rhs;
	;

    void get_string(std::ostream& os) const {
        os << "Arith : {Lhs} , {Rhs}";
		os << "{";
		this->Lhs.get_string(os);
		os << "}";
		os << "{";
		this->Rhs.get_string(os);
		os << "}";
		;
    }
};

class Array {
public:

    std::vector<std::optional<RcSymIdx>> Dims;
	std::shared_ptr<Type> EleTy;
	;

    void get_string(std::ostream& os) const {
        os << "Array : {Dims}, {EleTy}";
		os << "{";
		for (auto arg : Dims){
			arg.value().get_string(os);
		}os << "}";
		os << "{";
		this->EleTy.get()->get_string(os);
		os << "}";
		;
    }
};

class BBLabel {
public:

    RcSymIdx LabelSymidx;
	;

    void get_string(std::ostream& os) const {
        os << "BBlabel : {LabelSymidx}";
		os << "{";
		this->LabelSymidx.get_string(os);
		os << "}";
		;
    }
};

class Bitcast {
public:

    RcSymIdx RptrSymIdx;
	Type RptrType;
	Type CastType;
	;

    void get_string(std::ostream& os) const {
        os << "Bitcast : {RptrSymIdx}, {RptrType}, {CastType}";
		os << "{";
		this->RptrSymIdx.get_string(os);
		os << "}";
		os << "{";
		this->RptrType.get_string(os);
		os << "}";
		os << "{";
		this->CastType.get_string(os);
		os << "}";
		;
    }
};

class Br {
public:

    RcSymIdx cond;
	RcSymIdx t1;
	RcSymIdx t2;
	;

    void get_string(std::ostream& os) const {
        os << "Br : {cond}, {t1}, {t2}";
		os << "{";
		this->cond.get_string(os);
		os << "}";
		os << "{";
		this->t1.get_string(os);
		os << "}";
		os << "{";
		this->t2.get_string(os);
		os << "}";
		;
    }
};

class BreakPoint {
public:

    RcSymIdx SymIdx;
	std::vector<BreakPointArg> BreakpointArgs;
	;

    void get_string(std::ostream& os) const {
        os << "BreakPoint : {SymIdx}, {BreakpointArgs}";
		os << "{";
		this->SymIdx.get_string(os);
		os << "}";
		os << "{";
		for (auto arg : BreakpointArgs){
			arg.get_string(os);
		}os << "}";
		;
    }
};

class BreakPointArg {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Call {
public:

    std::optional<RcSymIdx> OpLhs;
	FuncOp Runc;
	;

    void get_string(std::ostream& os) const {
        os << "Call : {OpLhs}, {Runc}";
		os << "{";
		if (OpLhs.has_value()){
			OpLhs.value().get_string(os);
		}os << "}";
		os << "{";
		this->Runc.get_string(os);
		os << "}";
		;
    }
};

class Chi {
public:

    RcSymIdx Lhs;
	RcSymIdx Rhs;
	int MayUseInstr;
	;

    void get_string(std::ostream& os) const {
        os << "Chi : {Lhs}, {Rhs}, {MayUseInstr}";
		os << "{";
		this->Lhs.get_string(os);
		os << "}";
		os << "{";
		this->Rhs.get_string(os);
		os << "}";
		os << "{";
		os <<MayUseInstr
		;os << "}";
		;
    }
};

class ComparedPair {
public:

    RcSymIdx Compared;
	RcSymIdx Label;
	;

    void get_string(std::ostream& os) const {
        os << "ComparedPair : {Compared} , {Label}";
		os << "{";
		this->Compared.get_string(os);
		os << "}";
		os << "{";
		this->Label.get_string(os);
		os << "}";
		;
    }
};

class DefineFunc {
public:

    RcSymIdx func_symidx;
	RcSymIdx ret_symidx;
	std::vector<RcSymIdx> args;
	;

    void get_string(std::ostream& os) const {
        os << "DefineFunc : {func_symidx}, {ret_symidx}, {args}";
		os << "{";
		this->func_symidx.get_string(os);
		os << "}";
		os << "{";
		this->ret_symidx.get_string(os);
		os << "}";
		os << "{";
		for (auto arg : args){
			arg.get_string(os);
		}os << "}";
		;
    }
};

class DefineVar {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class DirectJump {
public:

    RcSymIdx LabelSymIdx;
	;

    void get_string(std::ostream& os) const {
        os << "DirectJump : {LabelSymIdx}";
		os << "{";
		this->LabelSymIdx.get_string(os);
		os << "}";
		;
    }
};

class Div {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class F32 {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Fcmp {
public:

    FcmpPlan Plan;
	RcSymIdx Lhs;
	RcSymIdx Rhs;
	Type VarType;
	;

    void get_string(std::ostream& os) const {
        os << "Fcmp : {Plan}, {Lhs}, {Rhs}, {VarType}";
		os << "{";
		this->Plan.get_string(os);
		os << "}";
		os << "{";
		this->Lhs.get_string(os);
		os << "}";
		os << "{";
		this->Rhs.get_string(os);
		os << "}";
		os << "{";
		this->VarType.get_string(os);
		os << "}";
		;
    }
};

class Fn {
public:

    std::vector<RcSymIdx> ArgSyms;
	RcSymIdx RetSym;
	;

    void get_string(std::ostream& os) const {
        os << "Fn : {ArgSyms}, {RetSym}";
		os << "{";
		for (auto arg : ArgSyms){
			arg.get_string(os);
		}os << "}";
		os << "{";
		this->RetSym.get_string(os);
		os << "}";
		;
    }
};

class Fptosi {
public:

    RcSymIdx FloatSymIdx;
	;

    void get_string(std::ostream& os) const {
        os << "Fptosi : {FloatSymIdx}";
		os << "{";
		this->FloatSymIdx.get_string(os);
		os << "}";
		;
    }
};

class FuncOp {
public:

    RcSymIdx RcFuncSymIdx;
	std::vector<RcSymIdx> ActualArgSymIdxVec;
	Type RetType;
	;

    void get_string(std::ostream& os) const {
        os << "FuncOp : {RcFuncSymIdx}, {ActualArgSymIdxVec}, {RetType}";
		os << "{";
		this->RcFuncSymIdx.get_string(os);
		os << "}";
		os << "{";
		for (auto arg : ActualArgSymIdxVec){
			arg.get_string(os);
		}os << "}";
		os << "{";
		this->RetType.get_string(os);
		os << "}";
		;
    }
};

class GetElementPtr {
public:

    RcSymIdx Lhs;
	RcSymIdx PtrSymIdx;
	Type ArrayTy;
	std::vector<std::optional<RcSymIdx>> IdxVec;
	;

    void get_string(std::ostream& os) const {
        os << "GetElementPtr : {Lhs}, {PtrSymIdx}, {ArrayTy}, {IdxVec}";
		os << "{";
		this->Lhs.get_string(os);
		os << "}";
		os << "{";
		this->PtrSymIdx.get_string(os);
		os << "}";
		os << "{";
		this->ArrayTy.get_string(os);
		os << "}";
		os << "{";
		for (auto arg : IdxVec){
			arg.value().get_string(os);
		}os << "}";
		;
    }
};

class Globl {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class I1 {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class I32 {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Icmp {
public:

    IcmpPlan Plan;
	RcSymIdx Lhs;
	RcSymIdx Rhs;
	Type VarType;
	;

    void get_string(std::ostream& os) const {
        os << "Icmp : {Plan}, {Lhs}, {Rhs}, {VarType}";
		os << "{";
		this->Plan.get_string(os);
		os << "}";
		os << "{";
		this->Lhs.get_string(os);
		os << "}";
		os << "{";
		this->Rhs.get_string(os);
		os << "}";
		os << "{";
		this->VarType.get_string(os);
		os << "}";
		;
    }
};

class Jump {
public:

    std::optional<RcSymIdx> OpLhs;
	JumpOp Runc;
	;

    void get_string(std::ostream& os) const {
        os << "Jump : {OpLhs}, {Runc}";
		os << "{";
		if (OpLhs.has_value()){
			OpLhs.value().get_string(os);
		}os << "}";
		os << "{";
		this->Runc.get_string(os);
		os << "}";
		;
    }
};

class Label {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Load {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class LogicAnd {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class LogicNot {
public:

    RcSymIdx Lhs;
	Type VarType;
	;

    void get_string(std::ostream& os) const {
        os << "LogicNot : {Lhs}, {VarType}";
		os << "{";
		this->Lhs.get_string(os);
		os << "}";
		os << "{";
		this->VarType.get_string(os);
		os << "}";
		;
    }
};

class LogicOr {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Mod {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Mu {
public:

    RcSymIdx Mu;
	int MayUseInstr;
	;

    void get_string(std::ostream& os) const {
        os << "Mu : {Mu}, {MayUseInstr}";
		os << "{";
		this->Mu.get_string(os);
		os << "}";
		os << "{";
		os <<MayUseInstr
		;os << "}";
		;
    }
};

class Mul {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Nope {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Phi {
public:

    RcSymIdx Lhs;
	PhiOp Rhs;
	;

    void get_string(std::ostream& os) const {
        os << "Phi : {Lhs}, {Rhs}";
		os << "{";
		this->Lhs.get_string(os);
		os << "}";
		os << "{";
		this->Rhs.get_string(os);
		os << "}";
		;
    }
};

class PhiOp {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class PhiPair {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Ptr64 {
public:

    Type Ty;
	;

    void get_string(std::ostream& os) const {
        os << "Ptr64 : {Ty}";
		os << "{";
		this->Ty.get_string(os);
		os << "}";
		;
    }
};

class RcSymIdx {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Ref {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Ret {
public:

    std::optional<RcSymIdx> OpRetSym;
	;

    void get_string(std::ostream& os) const {
        os << "Ret : {OpRetSym}";
		os << "{";
		if (OpRetSym.has_value()){
			OpRetSym.value().get_string(os);
		}os << "}";
		;
    }
};

class SimpleAssign {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class SitoFp {
public:

    RcSymIdx IntSymIdx;
	;

    void get_string(std::ostream& os) const {
        os << "SitoFp : {IntSymIdx}";
		os << "{";
		this->IntSymIdx.get_string(os);
		os << "}";
		;
    }
};

class Store {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Sub {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Switch {
public:

    RcSymIdx Cond;
	RcSymIdx Default;
	std::vector<ComparedPair> compared;
	;

    void get_string(std::ostream& os) const {
        os << "Switchs : {Cond}, {Default}, {compared}";
		os << "{";
		this->Cond.get_string(os);
		os << "}";
		os << "{";
		this->Default.get_string(os);
		os << "}";
		os << "{";
		for (auto arg : compared){
			arg.get_string(os);
		}os << "}";
		;
    }
};

class SymIdx {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class TranType {
public:

    RcSymIdx Lhs;
	Trans Op;
	;

    void get_string(std::ostream& os) const {
        os << "TranType : {Lhs}, {Op}";
		os << "{";
		this->Lhs.get_string(os);
		os << "}";
		os << "{";
		this->Op.get_string(os);
		os << "}";
		;
    }
};

class Unknown {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Untrack {
public:

    RcSymIdx SymIdx;
	;

    void get_string(std::ostream& os) const {
        os << "Untrack : {SymIdx}";
		os << "{";
		this->SymIdx.get_string(os);
		os << "}";
		;
    }
};

class Void {
public:

    ;

    void get_string(std::ostream& os) const {
        ;
    }
};

class Zext {
public:

    RcSymIdx BoolSymIdx;
	;

    void get_string(std::ostream& os) const {
        os << "Zext : {BoolSymIdx}";
		os << "{";
		this->BoolSymIdx.get_string(os);
		os << "}";
		;
    }
};

using ArithOpVar=std::variant<Add,Mul,Sub,Div,Mod,Icmp,Fcmp,LogicAnd,LogicOr,LogicNot>;
class ArithOp{
public :
	ArithOp(ArithOpVar variant):variant( variant){}
    void get_string(std::ostream& os) const{
        std::visit(Visitor{os}, variant);
    }
private:
	ArithOpVar variant;
    struct Visitor {
        std::ostream& os;
    	void operator()(const Add& instr) const {
			instr.get_string(os);
		}
		void operator()(const Mul& instr) const {
			instr.get_string(os);
		}
		void operator()(const Sub& instr) const {
			instr.get_string(os);
		}
		void operator()(const Div& instr) const {
			instr.get_string(os);
		}
		void operator()(const Mod& instr) const {
			instr.get_string(os);
		}
		void operator()(const Icmp& instr) const {
			instr.get_string(os);
		}
		void operator()(const Fcmp& instr) const {
			instr.get_string(os);
		}
		void operator()(const LogicAnd& instr) const {
			instr.get_string(os);
		}
		void operator()(const LogicOr& instr) const {
			instr.get_string(os);
		}
		void operator()(const LogicNot& instr) const {
			instr.get_string(os);
		}
	
    };
};
using JumpOpVar=std::variant<Ret,Br,Switch,DirectJump>;
class JumpOp{
public :
	JumpOp(JumpOpVar variant):variant( variant){}
    void get_string(std::ostream& os) const{
        std::visit(Visitor{os}, variant);
    }
private:
	JumpOpVar variant;
    struct Visitor {
        std::ostream& os;
    	void operator()(const Ret& instr) const {
			instr.get_string(os);
		}
		void operator()(const Br& instr) const {
			instr.get_string(os);
		}
		void operator()(const Switch& instr) const {
			instr.get_string(os);
		}
		void operator()(const DirectJump& instr) const {
			instr.get_string(os);
		}
	
    };
};
using KtcInstVar=std::variant<BBLabel,DefineVar,DefineFunc,Alloc,Globl,Load,Store,GetElementPtr,Arith,SimpleAssign,Call,Jump,Phi,Mu,Chi,Untrack,TranType,BreakPoint,Nope>;
class KtcInst{
public :
	KtcInst(KtcInstVar variant):variant( variant){}
    void get_string(std::ostream& os) const{
        std::visit(Visitor{os}, variant);
    }
private:
	KtcInstVar variant;
    struct Visitor {
        std::ostream& os;
    	void operator()(const BBLabel& instr) const {
			instr.get_string(os);
		}
		void operator()(const DefineVar& instr) const {
			instr.get_string(os);
		}
		void operator()(const DefineFunc& instr) const {
			instr.get_string(os);
		}
		void operator()(const Alloc& instr) const {
			instr.get_string(os);
		}
		void operator()(const Globl& instr) const {
			instr.get_string(os);
		}
		void operator()(const Load& instr) const {
			instr.get_string(os);
		}
		void operator()(const Store& instr) const {
			instr.get_string(os);
		}
		void operator()(const GetElementPtr& instr) const {
			instr.get_string(os);
		}
		void operator()(const Arith& instr) const {
			instr.get_string(os);
		}
		void operator()(const SimpleAssign& instr) const {
			instr.get_string(os);
		}
		void operator()(const Call& instr) const {
			instr.get_string(os);
		}
		void operator()(const Jump& instr) const {
			instr.get_string(os);
		}
		void operator()(const Phi& instr) const {
			instr.get_string(os);
		}
		void operator()(const Mu& instr) const {
			instr.get_string(os);
		}
		void operator()(const Chi& instr) const {
			instr.get_string(os);
		}
		void operator()(const Untrack& instr) const {
			instr.get_string(os);
		}
		void operator()(const TranType& instr) const {
			instr.get_string(os);
		}
		void operator()(const BreakPoint& instr) const {
			instr.get_string(os);
		}
		void operator()(const Nope& instr) const {
			instr.get_string(os);
		}
	
    };
};
using TransVar=std::variant<Fptosi,SitoFp,Zext,Bitcast>;
class Trans{
public :
	Trans(TransVar variant):variant( variant){}
    void get_string(std::ostream& os) const{
        std::visit(Visitor{os}, variant);
    }
private:
	TransVar variant;
    struct Visitor {
        std::ostream& os;
    	void operator()(const Fptosi& instr) const {
			instr.get_string(os);
		}
		void operator()(const SitoFp& instr) const {
			instr.get_string(os);
		}
		void operator()(const Zext& instr) const {
			instr.get_string(os);
		}
		void operator()(const Bitcast& instr) const {
			instr.get_string(os);
		}
	
    };
};
using TypeVar=std::variant<I32,F32,I1,Void,Label,Ref,Ptr64,Array,Fn,Unknown>;
class Type{
public :
	Type(TypeVar variant):variant( variant){}
    void get_string(std::ostream& os) const{
        std::visit(Visitor{os}, variant);
    }
private:
	TypeVar variant;
    struct Visitor {
        std::ostream& os;
    	void operator()(const I32& instr) const {
			instr.get_string(os);
		}
		void operator()(const F32& instr) const {
			instr.get_string(os);
		}
		void operator()(const I1& instr) const {
			instr.get_string(os);
		}
		void operator()(const Void& instr) const {
			instr.get_string(os);
		}
		void operator()(const Label& instr) const {
			instr.get_string(os);
		}
		void operator()(const Ref& instr) const {
			instr.get_string(os);
		}
		void operator()(const Ptr64& instr) const {
			instr.get_string(os);
		}
		void operator()(const Array& instr) const {
			instr.get_string(os);
		}
		void operator()(const Fn& instr) const {
			instr.get_string(os);
		}
		void operator()(const Unknown& instr) const {
			instr.get_string(os);
		}
	
    };
};
class FcmpPlan {
public:
	enum class FcmpPlanType {
		OEQ,	// Ordered and equal
		ONE,	// Ordered and not equal
		OGT,	// Ordered and greater than
		OGE,	// Ordered and greater than or equal
		OLT,	// Ordered and less than
		OLE,	// Ordered and less than or equal}
	};

FcmpPlan(FcmpPlanType t) : t(t){}
FcmpPlanType t ;
FcmpPlan new_OEQ(){return FcmpPlan(FcmpPlanType::OEQ);}
FcmpPlan new_ONE(){return FcmpPlan(FcmpPlanType::ONE);}
FcmpPlan new_OGT(){return FcmpPlan(FcmpPlanType::OGT);}
FcmpPlan new_OGE(){return FcmpPlan(FcmpPlanType::OGE);}
FcmpPlan new_OLT(){return FcmpPlan(FcmpPlanType::OLT);}
FcmpPlan new_OLE(){return FcmpPlan(FcmpPlanType::OLE);}
void get_string(std::ostream& os) const{
switch (Type) {
case FcmpPlanType::OEQ:
		os<<"OEQ";
break;
case FcmpPlanType::ONE:
		os<<"ONE";
break;
case FcmpPlanType::OGT:
		os<<"OGT";
break;
case FcmpPlanType::OGE:
		os<<"OGE";
break;
case FcmpPlanType::OLT:
		os<<"OLT";
break;
case FcmpPlanType::OLE:
		os<<"OLE";
break;
}
}
private :
FcmpPlanType Type;
};class IcmpPlan {
public:
	enum class IcmpPlanType {
		EQ,	// Equal
		NE,	// Not equal
		UGT,	// Unsigned greater than
		UGE,	// Unsigned greater than or equal
		ULT,	// Unsigned less than
		ULE,	// Unsigned less than or equal
		SGT,	// Signed greater than
		SGE,	// Signed greater than or equal
		SLT,	// Signed less than
		SLE,	// Signed less than or equal}
	};

IcmpPlan(IcmpPlanType t) : t(t){}
IcmpPlanType t ;
IcmpPlan new_EQ(){return IcmpPlan(IcmpPlanType::EQ);}
IcmpPlan new_NE(){return IcmpPlan(IcmpPlanType::NE);}
IcmpPlan new_UGT(){return IcmpPlan(IcmpPlanType::UGT);}
IcmpPlan new_UGE(){return IcmpPlan(IcmpPlanType::UGE);}
IcmpPlan new_ULT(){return IcmpPlan(IcmpPlanType::ULT);}
IcmpPlan new_ULE(){return IcmpPlan(IcmpPlanType::ULE);}
IcmpPlan new_SGT(){return IcmpPlan(IcmpPlanType::SGT);}
IcmpPlan new_SGE(){return IcmpPlan(IcmpPlanType::SGE);}
IcmpPlan new_SLT(){return IcmpPlan(IcmpPlanType::SLT);}
IcmpPlan new_SLE(){return IcmpPlan(IcmpPlanType::SLE);}
void get_string(std::ostream& os) const{
switch (Type) {
case IcmpPlanType::EQ:
		os<<"EQ";
break;
case IcmpPlanType::NE:
		os<<"NE";
break;
case IcmpPlanType::UGT:
		os<<"UGT";
break;
case IcmpPlanType::UGE:
		os<<"UGE";
break;
case IcmpPlanType::ULT:
		os<<"ULT";
break;
case IcmpPlanType::ULE:
		os<<"ULE";
break;
case IcmpPlanType::SGT:
		os<<"SGT";
break;
case IcmpPlanType::SGE:
		os<<"SGE";
break;
case IcmpPlanType::SLT:
		os<<"SLT";
break;
case IcmpPlanType::SLE:
		os<<"SLE";
break;
}
}
private :
IcmpPlanType Type;
};