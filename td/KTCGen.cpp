#include "llvm/Support/FormatVariadic.h"
#include "llvm/TableGen/Record.h"
#include "llvm/TableGen/TableGenBackend.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Signals.h"
#include "llvm/TableGen/Error.h"
#include "llvm/Support/raw_ostream.h"
#include <iostream>
#include <sstream>
#include <vector>

const static auto variantDeclStr = "using {0}=std::variant<{1}>;\n";
const static auto defDeclStr = "class {0}{{\n{1}}};\n\n";
const static auto getStringMethod = R"(
    void get_string(std::ostream& os) const {{
        {0};
    }
)";
const static auto getClassMemberMethod = R"(
    {0};
)";

const static auto visitorDeclStr = R"(
    struct Visitor {{
        std::ostream& os;
    {0}
    };
};
)";

namespace llvm {
void EmitKTCDecls(const RecordKeeper &records, raw_ostream &os) {
    emitSourceFileHeader("KTC Declarations", os, records);

    // 文件头，包含必要的库
    os << "#include <optional>\n";
    os << "#include <variant>\n";
    os << "#include <vector>\n";
    os << "#include <memory>\n";
    os << "#include <iostream>\n\n";

    // 处理 GloblStruct 和 VariantMember
    const auto &defs = records.getDefs();
    for (const auto &def : defs) {
        const std::string &defName = def.first;     // 获取 def 的名称
        const Record *defRecord = def.second.get(); // 获取 def 的 Record 对象

        // 跳过派生自 Enumeration 的记录
        if (defRecord->isSubClassOf("Enumeration")) { continue; }

        // 跳过匿名记录
        if (defRecord->isAnonymous()) { continue; }

        // 检查是否是 GloblStruct 或 VariantMember
        if (defRecord->isSubClassOf("GloblStruct")) {
            // 获取 fields 字段
            const DagInit *fields = defRecord->getValueAsDag("fields");
            if (!fields) {
                os << "// Error: No fields found for " << defName << "\n";
                continue;
            }

            // 生成结构体定义
            os << "class " << defName << " {\n";

            // 遍历 fields 的每个参数
            std::stringstream getStringBody;
            std::stringstream getClassMemberBody;
            std::string fmt = defRecord->getValueAsString("fmt").str(); // 获取 fmt 字段
            if (!fmt.empty()) {
                // 替换 fmt 中的占位符
                for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                    const Init *arg = fields->getArg(i);
                    std::string argName = fields->getArgNameStr(i).str(); // 获取参数名称
                    std::string argType = arg->getAsString();             // 获取参数类型

                    // 去掉 argType 的开头和结尾的引号
                    if (!argType.empty() && argType.front() == '"' && argType.back() == '"') {
                        argType = argType.substr(1, argType.size() - 2);
                    }

                    // 替换 fmt 中的占位符
                    size_t pos = fmt.find("$" + argName);
                    if (pos != std::string::npos) {
                        fmt.replace(pos, argName.length() + 1, "{" + argName + "}");
                    }
                }
                // 在public中添加成员变量
                for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                    const Init *arg = fields->getArg(i);
                    std::string argName = fields->getArgNameStr(i).str(); // 获取参数名称
                    std::string argType = arg->getAsString();             // 获取参数类型

                    // 去掉 argType 的开头和结尾的引号
                    if (!argType.empty() && argType.front() == '"' && argType.back() == '"') {
                        argType = argType.substr(1, argType.size() - 2);
                    }
                    getClassMemberBody << argType << " "<< argName << ";\n\t";
                }
                // 生成 get_string 方法
                getStringBody << "os << \"" << fmt << "\";\n\t\t";
                for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                    const Init *arg = fields->getArg(i);
                    std::string argName = fields->getArgNameStr(i).str(); // 获取参数名称
                    std::string argType = arg->getAsString();             // 获取参数类型

                    // 去掉 argType 的开头和结尾的引号
                    if (!argType.empty() && argType.front() == '"' && argType.back() == '"') {
                        argType = argType.substr(1, argType.size() - 2);
                    }
                    
                    //进行特判
                    std::string stdvec_opt = "std::vector<std::optional";
                    std::string stdvec = "std::vector";
                    std::string stdopt = "std::optional";
                    std::string stdshared_ptr = "std::shared_ptr";
                    //1. 类型以std::vector开头
                    if (argType.substr(0,stdvec_opt.size()) == stdvec_opt){ // std::vector<std::optional
                        getStringBody << "os << \"{\";\n\t\t";
                        getStringBody << "for (auto arg : "<< argName << "){\n\t\t\targ.value().get_string(os);\n\t\t}";
                        getStringBody << "os << \"}\";\n\t\t";
                    }else if(argType.substr(0,stdvec.size()) == stdvec){    // std::vector
                        getStringBody << "os << \"{\";\n\t\t";
                        getStringBody << "for (auto arg : "<< argName << "){\n\t\t\targ.get_string(os);\n\t\t}";
                        getStringBody << "os << \"}\";\n\t\t";
                    } else if (argType.substr(0,stdopt.size()) == stdopt){  // std::optional
                        getStringBody << "os << \"{\";\n\t\t";
                        getStringBody << "if (" << argName << ".has_value()){\n\t\t\t" << argName << ".value().get_string(os);\n\t\t}";
                        getStringBody << "os << \"}\";\n\t\t";
                    } else if (argType == "int"){                           // int
                        getStringBody << "os << \"{\";\n\t\t";
                        getStringBody << "os <<" + argName + "\n\t\t;";
                        getStringBody << "os << \"}\";\n\t\t";
                    }else if (argType.substr(0,stdshared_ptr.size()) == stdshared_ptr) {  // std::shared_ptr
                        getStringBody << "os << \"{\";\n\t\t";
                        getStringBody << "this->" + argName + ".get()->get_string(os);\n\t\t";
                        getStringBody << "os << \"}\";\n\t\t";
                    }else {
                        getStringBody << "os << \"{\";\n\t\t";
                        getStringBody << "this->" << argName << ".get_string(os);\n\t\t"; // 使用 this-> 访问成员变量
                        getStringBody << "os << \"}\";\n\t\t";
                    }    
                }
            }

            // 添加 get_string 方法
            os << "public:\n";
            os << formatv(getClassMemberMethod,getClassMemberBody.str());
            os << formatv(getStringMethod, getStringBody.str());

            os << "};\n\n";
        }
    }

    // 处理 Variant
    auto variants = records.getAllDerivedDefinitions("Variant");
    for (const auto *def : variants) {
        std::string variantName = def->getName().str();

        // 获取 members 字段
        const auto *members = def->getValueAsListInit("members");
        if (!members) {
            os << "// Error: No members found for " << variantName << "\n";
            continue;
        }

        std::stringstream oss;
        for (const auto *member : *members) {
            if (const auto *defValue = dyn_cast<DefInit>(member)) {
                oss << defValue->getDef()->getName().str() << ",";
            }
        }

        std::string memberList = oss.str();
        if (!memberList.empty()) {
            memberList.pop_back(); // 移除最后一个逗号
        }

        // 生成 variant 定义
        os << formatv(variantDeclStr, variantName+"Var", memberList);
        os << "class " + variantName + "{\npublic :\n\t"+ variantName + "(" + variantName + "Var " + R"(variant):variant( variant){}
    void get_string(std::ostream& os) const{
        std::visit(Visitor{os}, variant);
    }
private:)" + "\n\t" + variantName + "Var variant;";
        // 生成 Visitor 访问器
        std::stringstream visitorBody;
        for (const auto *member : *members) {
            if (const auto *defValue = dyn_cast<DefInit>(member)) {
                std::string memberName = defValue->getDef()->getName().str();
                visitorBody << "\tvoid operator()(const " << memberName << "& instr) const {\n\t";
                visitorBody << "\t\tinstr.get_string(os);\n\t";
                visitorBody << "\t}\n\t";
            }
        }

        os << formatv(visitorDeclStr, visitorBody.str());
    }

    // 处理 Enumeration
    const auto &enums = records.getAllDerivedDefinitions("Enumeration");
    for (const auto *enumDef : enums) {
        std::string enumName = enumDef->getName().str(); // 获取枚举类型的名称

        // 获取枚举值列表
        const auto *values = enumDef->getValueAsListInit("values");
        if (!values) {
            os << "class " << enumName << " {};\n\n"; // 如果枚举值列表为空，生成空枚举
            continue;
        }
        os << "class " << enumName << " {\n";
        os << "public:\n\tenum class "+ enumName + "Type {\n";

        // 遍历枚举值（带注释）
        for (size_t i = 0; i < values->size(); ++i) {
            const auto *value = values->getElement(i);
            if (const auto *defValue = dyn_cast<DefInit>(value)) {
                const Record *enumValue = defValue->getDef();
                // name
                std::string valueName = enumValue->getValueAsString("Name").str();
                // comment
                std::string comment = enumValue->getValueAsString("Comment").str();

                os << "\t\t" << valueName;
                if (!comment.empty()) {
                    os << ",\t// " << comment;
                }
                if (i != values->size() - 1) {
                    os << "\n";
                }
            }
        }
        os << "}\n\t};\n\n"; // 结束枚举定义
        os << enumName <<"("+ enumName +"Type t) : t(t){}\n";
        os << enumName << "Type t ;\n" ;

        for (size_t i = 0; i < values->size(); ++i) {
            const auto *value = values->getElement(i);
            if (const auto *defValue = dyn_cast<DefInit>(value)) {
                const Record *enumValue = defValue->getDef();
                // name
                std::string valueName = enumValue->getValueAsString("Name").str();
                os << enumName + " new_" + valueName + "(){return " + enumName + "(" + enumName +"Type::" + valueName + ");}\n";
            }
        }
        
        os << "void get_string(std::ostream& os) const{\nswitch (Type) {\n";
        for (size_t i = 0; i < values->size(); ++i) {
            const auto *value = values->getElement(i);
            if (const auto *defValue = dyn_cast<DefInit>(value)) {
                const Record *enumValue = defValue->getDef();
                // name
                std::string valueName = enumValue->getValueAsString("Name").str();
                os << "case " + enumName + "Type::" + valueName +":\n\t\tos<<\"" + valueName + "\";\nbreak;\n";
            }
        }
        os << "}\n}\n";
        os << "private :\n" ;
        os << enumName + "Type Type;\n" ;
        os << "};";
    }
}

} // namespace llvm