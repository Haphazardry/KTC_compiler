<<<<<<< HEAD
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
const static auto defDeclStr = "class {0}{\n{1}};\n\n";
namespace llvm {
void EmitKTCDecls(const RecordKeeper &records, raw_ostream &os) {
    emitSourceFileHeader("KTC Declarations", os, records);

    // 文件头，包含必要的库
    os << "#include <optional>\n";
    os << "#include <variant>\n";
    os << "#include <vector>\n";
    // os << "#include ";
    os << "#include <memory>\n\n";

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
            for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                const Init *arg = fields->getArg(i);
                std::string argName = fields->getArgNameStr(i).str(); // 获取参数类型
                std::string argType = arg->getAsString();      // 获取参数名称

                // 去掉 argType 的开头和结尾的引号
                if (!argType.empty() && argType.front() == '"' && argType.back() == '"') {
                    argType = argType.substr(1, argType.size() - 2);
                }
                
                os << "    " << argType << " " << argName << ";\n";
            }

            os << "};\n\n";

            // 生成调试信息并打印到命令行
            if (defRecord->getValue("fmt")) {
                std::string fmt = defRecord->getValueAsString("fmt").str(); // 获取 fmt 字段
                 // 如果 fmt 非空，则生成调试信息
                if (!fmt.empty()) {
                    std::ostringstream oss;

                    // 替换 fmt 中的占位符
                    for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                        const Init *arg = fields->getArg(i);
                        std::string argName = arg->getAsString();

                        // 去掉 argName 的开头和结尾的引号
                        if (!argName.empty() && argName.front() == '"' && argName.back() == '"') {
                            argName = argName.substr(1, argName.size() - 2);
                        }

                        // 替换占位符
                        size_t pos = fmt.find("$" + fields->getArgNameStr(i).str());
                        if (pos != std::string::npos) {
                            fmt.replace(pos, fields->getArgNameStr(i).str().length() + 1, argName);
                        }
                    }

                    oss << fmt << "\n";
                    llvm::outs() << "// Debug: " << oss.str(); // 打印到命令行
                }
            }
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

        os << formatv(variantDeclStr, variantName, memberList);
    }

    // 处理 Enumeration
    const auto &enums = records.getAllDerivedDefinitions("Enumeration");
    for (const auto *enumDef : enums) {
        std::string enumName = enumDef->getName().str(); // 获取枚举类型的名称

        // 获取枚举值列表
        const auto *values = enumDef->getValueAsListInit("values");
        if (!values) {
            os << "enum class " << enumName << " {};\n\n"; // 如果枚举值列表为空，生成空枚举
            continue;
        }

        os << "enum class " << enumName << " {\n";

        // 遍历枚举值（带注释）
        for (size_t i = 0; i < values->size(); ++i) {
            const auto *value = values->getElement(i);
            if (const auto *defValue = dyn_cast<DefInit>(value)) {
                const Record *enumValue = defValue->getDef();

                std::string valueName = enumValue->getValueAsString("Name").str();
                std::string comment = enumValue->getValueAsString("Comment").str();

                os << "    " << valueName;
                if (!comment.empty()) {
                    os << ", // " << comment;
                }
                if (i != values->size() - 1) {
                    os << "\n";
                }
            }
        }

        os << "\n};\n\n"; // 结束枚举定义
    }
}

} // namespace llvm

// // 遍历枚举值 无注释
    // for (size_t i = 0; i < values->size(); ++i) {
    //     const auto *value = values->getElement(i);
    //     if (const auto *strValue = dyn_cast<StringInit>(value)) {
    //         // 将 StringRef 转换为 std::string
    //         os << "    " << strValue->getValue().str(); 
    //         if (i != values->size() - 1) {
    //             os << ",";
    //         }
    //         os << "\n";
    //     }
    // }

        


// static void emitKTCDefs(const RecordKeeper &records, raw_ostream &os) {
//     emitSourceFileHeader("KTC Declarations", os, records);
  
//     auto dialectDefs = records.getAllDerivedDefinitions("Dialect");
//     if (dialectDefs.empty())
//       return false;
  
//     SmallVector<Dialect> dialects(dialectDefs.begin(), dialectDefs.end());
//     std::optional<Dialect> dialect = findDialectToGenerate(dialects);
//     emitDialectDecl(*dialect, os);
=======
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
const static auto defDeclStr = "class {0}{\n{1}};\n\n";
namespace llvm {
void EmitKTCDecls(RecordKeeper &records, raw_ostream &os) {
    emitSourceFileHeader("KTC Declarations", os, records);

    // 鏂囦欢澶达紝鍖呭惈蹇呰鐨勫簱
    os << "#include <optional>\n";
    os << "#include <variant>\n";
    os << "#include <vector>\n";
    // os << "#include ";
    os << "#include <memory>\n\n";

    // 澶勭悊 GloblStruct 鍜� VariantMember
    const auto &defs = records.getDefs();
    for (const auto &def : defs) {
        const std::string &defName = def.first;     // 鑾峰彇 def 鐨勫悕绉�
        const Record *defRecord = def.second.get(); // 鑾峰彇 def 鐨� Record 瀵硅薄

        // 璺宠繃娲剧敓鑷� Enumeration 鐨勮褰�
        if (defRecord->isSubClassOf("Enumeration")) { continue; }

        // 璺宠繃鍖垮悕璁板綍
        if (defRecord->isAnonymous()) { continue; }

        // 妫�鏌ユ槸鍚︽槸 GloblStruct 鎴� VariantMember
        if (defRecord->isSubClassOf("Struct")) {
            // 鑾峰彇 fields 瀛楁
            const DagInit *fields = defRecord->getValueAsDag("fields");
            if (!fields) {
                os << "// Error: No fields found for " << defName << "\n";
                continue;
            }

            // 鐢熸垚缁撴瀯浣撳畾涔�
            os << "class " << defName << " {\n";

            // 閬嶅巻 fields 鐨勬瘡涓弬鏁�
            for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                const Init *arg = fields->getArg(i);
                std::string argName = fields->getArgNameStr(i).str(); // 鑾峰彇鍙傛暟绫诲瀷
                std::string argType = arg->getAsString();      // 鑾峰彇鍙傛暟鍚嶇О

                // 鍘绘帀 argType 鐨勫紑澶村拰缁撳熬鐨勫紩鍙�
                if (!argType.empty() && argType.front() == '"' && argType.back() == '"') {
                    argType = argType.substr(1, argType.size() - 2);
                }
                
                os << "    " << argType << " " << argName << ";\n";
            }

            os << "};\n\n";

            // 鐢熸垚璋冭瘯淇℃伅骞舵墦鍗板埌鍛戒护琛�
            if (defRecord->getValue("fmt")) {
                std::string fmt = defRecord->getValueAsString("fmt").str(); // 鑾峰彇 fmt 瀛楁
                 // 濡傛灉 fmt 闈炵┖锛屽垯鐢熸垚璋冭瘯淇℃伅
                if (!fmt.empty()) {
                    std::ostringstream oss;

                    // 鏇挎崲 fmt 涓殑鍗犱綅绗�
                    for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                        const Init *arg = fields->getArg(i);
                        std::string argName = arg->getAsString();

                        // 鍘绘帀 argName 鐨勫紑澶村拰缁撳熬鐨勫紩鍙�
                        if (!argName.empty() && argName.front() == '"' && argName.back() == '"') {
                            argName = argName.substr(1, argName.size() - 2);
                        }

                        // 鏇挎崲鍗犱綅绗�
                        size_t pos = fmt.find("$" + fields->getArgNameStr(i).str());
                        if (pos != std::string::npos) {
                            fmt.replace(pos, fields->getArgNameStr(i).str().length() + 1, argName);
                        }
                    }

                    oss << fmt << "\n";
                    llvm::outs() << "// Debug: " << oss.str(); // 鎵撳嵃鍒板懡浠よ
                }
            }
        }
    }
    // 澶勭悊 Variant
    auto variants = records.getAllDerivedDefinitions("Variant");
    for (const auto *def : variants) {
        std::string variantName = def->getName().str();

        // 鑾峰彇 members 瀛楁
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
            memberList.pop_back(); // 绉婚櫎鏈�鍚庝竴涓�楀彿
        }

        os << formatv(variantDeclStr, variantName, memberList);
    }

    // 澶勭悊 Enumeration
    const auto &enums = records.getAllDerivedDefinitions("Enumeration");
    for (const auto *enumDef : enums) {
        std::string enumName = enumDef->getName().str(); // 鑾峰彇鏋氫妇绫诲瀷鐨勫悕绉�

        // 鑾峰彇鏋氫妇鍊煎垪琛�
        const auto *values = enumDef->getValueAsListInit("values");
        if (!values) {
            os << "enum class " << enumName << " {};\n\n"; // 濡傛灉鏋氫妇鍊煎垪琛ㄤ负绌猴紝鐢熸垚绌烘灇涓�
            continue;
        }

        os << "enum class " << enumName << " {\n";

        // 閬嶅巻鏋氫妇鍊硷紙甯︽敞閲婏級
        for (size_t i = 0; i < values->size(); ++i) {
            const auto *value = values->getElement(i);
            if (const auto *defValue = dyn_cast<DefInit>(value)) {
                const Record *enumValue = defValue->getDef();

                std::string valueName = enumValue->getValueAsString("Name").str();
                std::string comment = enumValue->getValueAsString("Comment").str();

                os << "    " << valueName;
                if (!comment.empty()) {
                    os << ", // " << comment;
                }
                if (i != values->size() - 1) {
                    os << "\n";
                }
            }
        }

        os << "\n};\n\n"; // 缁撴潫鏋氫妇瀹氫箟
    }
}

} // namespace llvm

// // 閬嶅巻鏋氫妇鍊� 鏃犳敞閲�
    // for (size_t i = 0; i < values->size(); ++i) {
    //     const auto *value = values->getElement(i);
    //     if (const auto *strValue = dyn_cast<StringInit>(value)) {
    //         // 灏� StringRef 杞崲涓� std::string
    //         os << "    " << strValue->getValue().str(); 
    //         if (i != values->size() - 1) {
    //             os << ",";
    //         }
    //         os << "\n";
    //     }
    // }

        


// static void emitKTCDefs(const RecordKeeper &records, raw_ostream &os) {
//     emitSourceFileHeader("KTC Declarations", os, records);
  
//     auto dialectDefs = records.getAllDerivedDefinitions("Dialect");
//     if (dialectDefs.empty())
//       return false;
  
//     SmallVector<Dialect> dialects(dialectDefs.begin(), dialectDefs.end());
//     std::optional<Dialect> dialect = findDialectToGenerate(dialects);
//     emitDialectDecl(*dialect, os);
>>>>>>> fd272d2af98b7bbdb1ae3c5d49fc1d4690d4d787
//   }