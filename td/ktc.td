<<<<<<< HEAD
def ListOp;
class GloblStruct<dag f=(ListOp ), string _fmt=""> {
    dag fields = f;
    string fmt = _fmt;
    code cppcode = [{}];
}
// "fmt" ÓÃÓÚÉú³Éµ÷ÊÔĞÅÏ¢
// a, b  " xxx $a $b  "  ==> xxx a.str  b.str  Êä³öµ½¿ØÖÆÌ¨,oss
class VariantMember<dag f=(ListOp), string fmt=""> : GloblStruct<f,fmt>{}

// ¶şÔªÔËËã·û
class BinaryOp : VariantMember<(ListOp "RcSymIdx" : $Lhs, "RcSymIdx" : $Rhs, "Type" : $VarType)>{}

// ¶¨ÒåÒ»¸öÍ¨ÓÃµÄ Variant Àà

// class Variant<dag records> {
//     dag variant_records = records;
// }

class Variant<list<VariantMember> lvm>{
    list<VariantMember> members = lvm;
}

// ¶¨ÒåÃ¶¾ÙÀà
//´ø×¢ÊÍ
class EnumMember<string name, string comment = ""> {
    string Name = name;
    string Comment = comment;
}
class Enumeration {
    list<EnumMember> values = [];
}

// //²»´ø×¢ÊÍ
// class Enumeration {
//     list<string> values = []; // Ã¶¾ÙÖµÁĞ±í
// }


def SymIdx : GloblStruct<(ListOp "int":$Value )>{}

// ¶¨Òå RcSymIdx ½á¹¹Ìå
// Rc<RefCell<SymIdx>> µÄ C++ µÈ¼ÛÎïÊÇ std::shared_ptr<std::unique_ptr<SymIdx>>
// ÕâÀïÎÒÃÇÖ±½ÓÊ¹ÓÃ std::shared_ptr<SymIdx> À´¼ò»¯
def RcSymIdx : GloblStruct<(ListOp "std::shared_ptr<SymIdx>" : $RcSymIdx) > {}

// cppcode ¸ºÔğĞ´º¯Êı
// fields ¸ºÔğ¶¨ÒåÀàĞÍ×Ö¶Î

def BBLabel : VariantMember<(ListOp "RcSymIdx" : $LabelSymidx), "BBlabel : $LabelSymidx">{}
def DefineFunc : VariantMember<(ListOp "RcSymIdx" : $func_symidx, "RcSymIdx" : $ret_symidx, "std::vector<RcSymIdx>" : $args ),
                                "DefineFunc : $func_symidx, $ret_symidx, $args">{}


/// ¿ªÊ¼¶¨ÒåType
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
    // ????ÊÇ·ñĞèÒª
    // dag fields = (ListOp "")
}

/// ¶¨ÒåType½áÊø

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

// ArithOp¶¨Òå¿ªÊ¼
// ÓĞ×¢ÊÍ
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
// ArithOp¶¨Òå½áÊø

// FcmpPlan¶¨Òå¿ªÊ¼
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

// // ÎŞ×¢ÊÍ
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
// FunOp¶¨Òå
def FuncOp : VariantMember<(ListOp "RcSymIdx" : $RcFuncSymIdx,
                        "std::vector<RcSymIdx>" : $ActualArgSymIdxVec,
                        "Type" : $RetType),
                        "FuncOp : $RcFuncSymIdx, $ActualArgSymIdxVec, $RetType"> { }
def Call  : VariantMember<(ListOp "std::optional<RcSymIdx>" : $OpLhs,
                        "FuncOp" : $Runc),
                        "Call : $OpLhs, $Runc">{ }
// FuncOp¶¨Òå½áÊø
// JumOp¶¨Òå
def Ret : VariantMember<(ListOp "std::optional<RcSymIdx>" : $OpRetSym),
                        "Ret : $OpRetSym"> { }

def Br : VariantMember<(ListOp "RcSymIdx" : $cond,
                        "RcSymIdx" : $t1,
                        "RcSymIdx" : $t2),
                        "Br : $cond, $t1, $t2"> { }
def ComparedPair : GloblStruct<(ListOp "RcSymIdx" : $Compared,
                                "RcSymIdx" : $Label) ,
                                "ComparedPair : $Compared , $Label">{}
def Switch  : VariantMember<(ListOp "RcSymIdx" : $Cond,
                        "RcSymIdx" : $Default,
                        "std::vector<ComparedPair>" : $compared),
                        "Switchs : $Cond, $Default, $compared"> { }
def DirectJump : VariantMember<(ListOp "RcSymIdx" : $LabelSymIdx),
                                "DirectJump : $LabelSymIdx"> { }
def JumpOp : Variant<[Ret, Br, Switch, DirectJump]>;
/// JumpOp¶¨Òå½áÊø

def Jump : VariantMember<(ListOp "std::optional<RcSymIdx>" : $OpLhs,
                        "JumpOp" : $Runc),
                        "Jump : $OpLhs, $Runc"> { }
// PhiPair¶¨Òå
def PhiPair : GloblStruct<(ListOp "RcSymIdx" : $SymIdx,
                                "int" : $DefInstr,
                                "int" : $CommingCfgNode)>{}
// PhiOp¶¨Òå
def PhiOp : GloblStruct<(ListOp "std::vector<PhiPair>" : $PhiPairs)> { }

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

// Trans¶¨Òå
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

// Breakpoint¶¨Òå
def BreakPointArg : GloblStruct<(ListOp "RcSymIdx" : $SymIdx,
        "std::optional<std::string>" : $OpFieldName)> { }

def BreakPoint : VariantMember<(ListOp "RcSymIdx" : $SymIdx,
                        "std::vector<BreakPointArg>" : $BreakpointArgs),
                        "BreakPoint : $SymIdx, $BreakpointArgs"> { }

def Nope : VariantMember<> { }

def KtcInst : Variant<[BBLabel , DefineVar , DefineFunc, Alloc, Globl, Load, Store,
                              GetElementPtr, Arith, SimpleAssign, Call, Jump, Phi, Mu, Chi, Untrack, TranType,
                              BreakPoint, Nope]>;


// getstring º¯Êı¶¨Òå
def get_string()
=======
include "base.td"
// //ä¸å¸¦æ³¨é‡Š
// class Enumeration {
//     list<string> values = []; // æšä¸¾å€¼åˆ—è¡¨
// }
// äºŒå…ƒè¿ç®—ç¬¦
class BinaryOp : VariantMember<(ListOp "RcSymIdx" : $Lhs, "RcSymIdx" : $Rhs, "Type" : $VarType)>{}

// å®šä¹‰ä¸€ä¸ªé€šç”¨çš„ Variant ç±»

// class Variant<dag records> {
//     dag variant_records = records;
// }


def SymIdx : Struct<(ListOp "int":$Value )>{}

// å®šä¹‰ RcSymIdx ç»“æ„ä½“
// Rc<RefCell<SymIdx>> çš„ C++ ç­‰ä»·ç‰©æ˜¯ std::shared_ptr<std::unique_ptr<SymIdx>>
// è¿™é‡Œæˆ‘ä»¬ç›´æ¥ä½¿ç”¨ std::shared_ptr<SymIdx> æ¥ç®€åŒ–
def RcSymIdx : Struct<(ListOp "std::shared_ptr<SymIdx>" : $RcSymIdx) > {}

// cppcode è´Ÿè´£å†™å‡½æ•°
// fields è´Ÿè´£å®šä¹‰ç±»å‹å­—æ®µ

def BBLabel : VariantMember<(ListOp "RcSymIdx" : $LabelSymidx), "BBlabel : $LabelSymidx">{}
def DefineFunc : VariantMember<(ListOp "RcSymIdx" : $func_symidx, "RcSymIdx" : $ret_symidx, "std::vector<RcSymIdx>" : $args ),
                                "DefineFunc : $func_symidx, $ret_symidx, $args">{}


/// å¼€å§‹å®šä¹‰Type
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
    // ????æ˜¯å¦éœ€è¦
    // dag fields = (ListOp "")
}

/// å®šä¹‰Typeç»“æŸ

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

// ArithOpå®šä¹‰å¼€å§‹
// æœ‰æ³¨é‡Š
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
// ArithOpå®šä¹‰ç»“æŸ

// FcmpPlanå®šä¹‰å¼€å§‹
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

// // æ— æ³¨é‡Š
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
// FunOpå®šä¹‰
def FuncOp : VariantMember<(ListOp "RcSymIdx" : $RcFuncSymIdx,
                        "std::vector<RcSymIdx>" : $ActualArgSymIdxVec,
                        "Type" : $RetType),
                        "FuncOp : $RcFuncSymIdx, $ActualArgSymIdxVec, $RetType"> { }
def Call  : VariantMember<(ListOp "std::optional<RcSymIdx>" : $OpLhs,
                        "FuncOp" : $Runc),
                        "Call : $OpLhs, $Runc">{ }
// FuncOpå®šä¹‰ç»“æŸ
// JumOpå®šä¹‰
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
/// JumpOpå®šä¹‰ç»“æŸ

def Jump : VariantMember<(ListOp "std::optional<RcSymIdx>" : $OpLhs,
                        "JumpOp" : $Runc),
                        "Jump : $OpLhs, $Runc"> { }
// PhiPairå®šä¹‰
def PhiPair : Struct<(ListOp "RcSymIdx" : $SymIdx,
                                "int" : $DefInstr,
                                "int" : $CommingCfgNode)>{}
// PhiOpå®šä¹‰
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

// Transå®šä¹‰
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

// Breakpointå®šä¹‰
def BreakPointArg : Struct<(ListOp "RcSymIdx" : $SymIdx,
        "std::optional<std::string>" : $OpFieldName)> { }

def BreakPoint : VariantMember<(ListOp "RcSymIdx" : $SymIdx,
                        "std::vector<BreakPointArg>" : $BreakpointArgs),
                        "BreakPoint : $SymIdx, $BreakpointArgs"> { }

def Nope : VariantMember<> { }

def KtcInst : Variant<[BBLabel , DefineVar , DefineFunc, Alloc, Store,
                              GetElementPtr, Arith, SimpleAssign, Call, Jump, Phi, Mu, Chi, Untrack, TranType,
                              BreakPoint, Nope]>;
>>>>>>> fd272d2af98b7bbdb1ae3c5d49fc1d4690d4d787
