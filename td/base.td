def ListOp;
class Struct<dag f=(ListOp ), string _fmt=""> {
    dag fields = f;
    string fmt = _fmt;
    code cppcode = [{}];
    list<string> DeclareFuncs = [];
}
// "fmt" 用于生成调试信息
// a, b  " xxx $a $b  "  ==> xxx a.str  b.str  输出到控制台,oss
class VariantMember<dag f=(ListOp), string fmt=""> : Struct<f,fmt>{}


class Variant<list<VariantMember> lvm>{
    list<VariantMember> members = lvm;
}
// 定义枚举类
//带注释
class EnumMember<string name, string comment = ""> {
    string Name = name;
    string Comment = comment;
}
class Enumeration {
    list<EnumMember> values = [];
}