include "base.td"
// //不带注释
// class Enumeration {
//     list<string> values = []; // 枚举值列表
// }
// 二元运算符
class BinaryOp : VariantMember<(ListOp "RcSymIdx" : $Lhs, "RcSymIdx" : $Rhs, "Type" : $VarType)>{}

// 定义一个通用的 Variant 类

// class Variant<dag records> {
//     dag variant_records = records;
// }


def SymIdx : Struct<(ListOp "int":$Value )>{}

// 定义 RcSymIdx 结构体
// Rc<RefCell<SymIdx>> 的 C++ 等价物是 std::shared_ptr<std::unique_ptr<SymIdx>>
// 这里我们直接使用 std::shared_ptr<SymIdx> 来简化
def RcSymIdx : Struct<(ListOp "std::shared_ptr<SymIdx>" : $RcSymIdx) > {}

// cppcode 负责写函数
// fields 负责定义类型字段

def BBLabel : VariantMember<(ListOp "RcSymIdx" : $LabelSymidx), "BBlabel : $LabelSymidx">{}
def DefineFunc : VariantMember<(ListOp "RcSymIdx" : $func_symidx, "RcSymIdx" : $ret_symidx, "std::vector<RcSymIdx>" : $args ),
                                "DefineFunc : $func_symidx, $ret_symidx, $args">{}


/// 开始定义Type
def I32 : VariantMember<>;
def F32 : VariantMember<>;
def I1 : VariantMember<>;
def Void    : VariantMember<>;
def Label : VariantMember<>;
def Ref : VariantMember<>;
def Unknown : VariantMember<>;
def Ptr64 : VariantMember<(ListOp "Type" : $Ty) , "Ptr64 : $Ty">{}
def Array : VariantMember<(ListOp "std::vector<std::optional<RcSymIdx>>" : $Dims,
                         "std::shared_ptr<Type>" : $EleTy) , "Array : $Dims, $EleTy">{}
def Fn : VariantMember<(ListOp "std::vector<RcSymIdx>" : $ArgSyms,
                        "RcSymIdx" : $RetSym) , "Fn : $ArgSyms, $RetSym">{}
// def Type : Variant<(ListOp I32, F32, I1, Void, Label, Ref, Ptr64, Array, Fn, Unknown)>;
def Type : Variant<[I32, F32, I1, Void, Label, Ref, Ptr64, Array, Fn, Unknown]>{
    // ????是否需要
    // dag fields = (ListOp "")
}

/// 定义Type结束

def DefineVar : VariantMember<>{ }

def Alloc : VariantMember<> { }

def Globl : VariantMember<>{ }

def Load  : VariantMember<>{ }

def Store : VariantMember<>{ }

def GetElementPtr : VariantMember<(ListOp "RcSymIdx" : $Lhs, "RcSymIdx" : $PtrSymIdx, "Type" : $ArrayTy, "std::vector<std::optional<RcSymIdx>>" : $IdxVec) , 
                                    "GetElementPtr : $Lhs, $PtrSymIdx, $ArrayTy, $IdxVec">{ }

def EQ : EnumMember<"EQ", "Equal">;
def NE : EnumMember<"NE", "Not equal">;
def UGT : EnumMember<"UGT", "Unsigned greater than">;
def UGE : EnumMember<"UGE", "Unsigned greater than or equal">;
def ULT : EnumMember<"ULT", "Unsigned less than">;
def ULE : EnumMember<"ULE", "Unsigned less than or equal">;
def SGT : EnumMember<"SGT", "Signed greater than">;
def SGE : EnumMember<"SGE", "Signed greater than or equal">;
def SLT : EnumMember<"SLT", "Signed less than">;
def SLE : EnumMember<"SLE", "Signed less than or equal">;

// ArithOp定义开始
// 有注释
def IcmpPlan : Enumeration {
    list<EnumMember> values = [
        EQ,
        NE,
        UGT,
        UGE,
        ULT,
        ULE,
        SGT,
        SGE,
        SLT,
        SLE
    ];
}
def OEQ : EnumMember<"OEQ", "Ordered and equal">;
def ONE : EnumMember<"ONE", "Ordered and not equal">;
def OGT : EnumMember<"OGT", "Ordered and greater than">;
def OGE : EnumMember<"OGE", "Ordered and greater than or equal">;
def OLT : EnumMember<"OLT", "Ordered and less than">;
def OLE : EnumMember<"OLE", "Ordered and less than or equal">;
// ArithOp定义结束

// FcmpPlan定义开始
def FcmpPlan : Enumeration {
    list<EnumMember> values = [
        OEQ,
        ONE,
        OGT,
        OGE,
        OLT,
        OLE
    ];
}

// // 无注释
// def IcmpPlan : Enumeration{
//     list<string> values = ["Eq","Ne","Ugt","Uge","Ult","Ule","Sgt","Sge","Slt","Sle"];
// }
// def FcmpPlan : Enumeration{
//     list<string> values = ["Oeq","One","Ogt","Oge","Olt","Ole"];
// }

def Add : BinaryOp;
def Mul : BinaryOp;
def Sub : BinaryOp;
def Div : BinaryOp;
def Mod : BinaryOp;

def Icmp : VariantMember<(ListOp "IcmpPlan" : $Plan,
                        "RcSymIdx" : $Lhs,
                        "RcSymIdx" : $Rhs,
                        "Type" : $VarType) , "Icmp : $Plan, $Lhs, $Rhs, $VarType">{ }
def Fcmp : VariantMember<(ListOp "FcmpPlan" : $Plan,
                        "RcSymIdx" : $Lhs,
                        "RcSymIdx" : $Rhs,
                        "Type" : $VarType) , "Fcmp : $Plan, $Lhs, $Rhs, $VarType">{ }

def LogicAnd : BinaryOp;
def LogicOr  : BinaryOp;
def LogicNot : VariantMember<(ListOp "RcSymIdx" : $Lhs, "Type" : $VarType), 
                            "LogicNot : $Lhs, $VarType"> { }
// def ArithOp : Variant<(ListOp Add, Mul, Sub, Div, Mod, Icmp, Fcmp, LogicAnd, LogicOr, LogicNot)>;
def ArithOp: Variant<[Add, Mul, Sub, Div, Mod, Icmp, Fcmp, LogicAnd, LogicOr, LogicNot]>{}
def Arith : VariantMember<(ListOp "RcSymIdx" : $Lhs, "ArithOp" : $Rhs), 
                            "Arith : $Lhs , $Rhs">{ }
def SimpleAssign : BinaryOp;
// FunOp定义
def FuncOp : VariantMember<(ListOp "RcSymIdx" : $RcFuncSymIdx,
                        "std::vector<RcSymIdx>" : $ActualArgSymIdxVec,
                        "Type" : $RetType),
                        "FuncOp : $RcFuncSymIdx, $ActualArgSymIdxVec, $RetType"> { }
def Call  : VariantMember<(ListOp "std::optional<RcSymIdx>" : $OpLhs,
                        "FuncOp" : $Runc),
                        "Call : $OpLhs, $Runc">{ }
// FuncOp定义结束
// JumOp定义
def Ret : VariantMember<(ListOp "std::optional<RcSymIdx>" : $OpRetSym),
                        "Ret : $OpRetSym"> { }

def Br : VariantMember<(ListOp "RcSymIdx" : $cond,
                        "RcSymIdx" : $t1,
                        "RcSymIdx" : $t2),
                        "Br : $cond, $t1, $t2"> { }
def ComparedPair : Struct<(ListOp "RcSymIdx" : $Compared,
                                "RcSymIdx" : $Label) ,
                                "ComparedPair : $Compared , $Label">{}
def Switch  : VariantMember<(ListOp "RcSymIdx" : $Cond,
                        "RcSymIdx" : $Default,
                        "std::vector<ComparedPair>" : $compared),
                        "Switchs : $Cond, $Default, $compared"> { }
def DirectJump : VariantMember<(ListOp "RcSymIdx" : $LabelSymIdx),
                                "DirectJump : $LabelSymIdx"> { }
def JumpOp : Variant<[Ret, Br, Switch, DirectJump]>;
/// JumpOp定义结束

def Jump : VariantMember<(ListOp "std::optional<RcSymIdx>" : $OpLhs,
                        "JumpOp" : $Runc),
                        "Jump : $OpLhs, $Runc"> { }
// PhiPair定义
def PhiPair : Struct<(ListOp "RcSymIdx" : $SymIdx,
                                "int" : $DefInstr,
                                "int" : $CommingCfgNode)>{}
// PhiOp定义
def PhiOp : Struct<(ListOp "std::vector<PhiPair>" : $PhiPairs)> { }

def Phi : VariantMember<(ListOp "RcSymIdx" : $Lhs,
                        "PhiOp" : $Rhs),
                        "Phi : $Lhs, $Rhs"> { }

def Mu : VariantMember<(ListOp "RcSymIdx" : $Mu,
                        "int" : $MayUseInstr),
                        "Mu : $Mu, $MayUseInstr"> { }

def Chi : VariantMember<(ListOp "RcSymIdx" : $Lhs,
                        "RcSymIdx" : $Rhs,
                        "int" : $MayUseInstr),
                        "Chi : $Lhs, $Rhs, $MayUseInstr"> { }

def Untrack : VariantMember<(ListOp "RcSymIdx" : $SymIdx),
                            "Untrack : $SymIdx"> { }

// Trans定义
def Fptosi : VariantMember<(ListOp "RcSymIdx" : $FloatSymIdx),
                            "Fptosi : $FloatSymIdx"> { }

def SitoFp : VariantMember<(ListOp "RcSymIdx" : $IntSymIdx),
                            "SitoFp : $IntSymIdx"> { }

def Zext : VariantMember<(ListOp "RcSymIdx" : $BoolSymIdx),
                        "Zext : $BoolSymIdx"> { }

def Bitcast : VariantMember<(ListOp "RcSymIdx" : $RptrSymIdx,
                        "Type" : $RptrType,
                        "Type" : $CastType),
                        "Bitcast : $RptrSymIdx, $RptrType, $CastType"> { }

def Trans : Variant<[Fptosi, SitoFp, Zext, Bitcast]>;

def TranType : VariantMember<(ListOp "RcSymIdx" : $Lhs,
                        "Trans" : $Op),
                        "TranType : $Lhs, $Op"> { }

// Breakpoint定义
def BreakPointArg : Struct<(ListOp "RcSymIdx" : $SymIdx,
        "std::optional<std::string>" : $OpFieldName)> { }

def BreakPoint : VariantMember<(ListOp "RcSymIdx" : $SymIdx,
                        "std::vector<BreakPointArg>" : $BreakpointArgs),
                        "BreakPoint : $SymIdx, $BreakpointArgs"> { }

def Nope : VariantMember<> { }

def KtcInst : Variant<[BBLabel , DefineVar , DefineFunc, Alloc, Store,
                              GetElementPtr, Arith, SimpleAssign, Call, Jump, Phi, Mu, Chi, Untrack, TranType,
                              BreakPoint, Nope]>;
