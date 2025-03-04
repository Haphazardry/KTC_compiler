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

    // �ļ�ͷ��������Ҫ�Ŀ�
    os << "#include <optional>\n";
    os << "#include <variant>\n";
    os << "#include <vector>\n";
    // os << "#include ";
    os << "#include <memory>\n\n";

    // ���� GloblStruct �� VariantMember
    const auto &defs = records.getDefs();
    for (const auto &def : defs) {
        const std::string &defName = def.first;     // ��ȡ def ������
        const Record *defRecord = def.second.get(); // ��ȡ def �� Record ����

        // ���������� Enumeration �ļ�¼
        if (defRecord->isSubClassOf("Enumeration")) { continue; }

        // ����������¼
        if (defRecord->isAnonymous()) { continue; }

        // ����Ƿ���? GloblStruct �� VariantMember
        if (defRecord->isSubClassOf("GloblStruct")) {
            // ��ȡ fields �ֶ�
            const DagInit *fields = defRecord->getValueAsDag("fields");
            if (!fields) {
                os << "// Error: No fields found for " << defName << "\n";
                continue;
            }

            // ���ɽṹ�嶨��
            os << "class " << defName << " {\n";

            // ���� fields ��ÿ������
            for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                const Init *arg = fields->getArg(i);
                std::string argName = fields->getArgNameStr(i).str(); // ��ȡ��������
                std::string argType = arg->getAsString();      // ��ȡ��������

                // ȥ�� argType �Ŀ�ͷ�ͽ�β������
                if (!argType.empty() && argType.front() == '"' && argType.back() == '"') {
                    argType = argType.substr(1, argType.size() - 2);
                }
                
                os << "    " << argType << " " << argName << ";\n";
            }

            os << "};\n\n";

            // ���ɵ�����Ϣ����ӡ��������
            if (defRecord->getValue("fmt")) {
                std::string fmt = defRecord->getValueAsString("fmt").str(); // ��ȡ fmt �ֶ�
                 // ���? fmt �ǿգ������ɵ�����Ϣ
                if (!fmt.empty()) {
                    std::ostringstream oss;

                    // �滻 fmt �е�ռλ��
                    for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                        const Init *arg = fields->getArg(i);
                        std::string argName = arg->getAsString();

                        // ȥ�� argName �Ŀ�ͷ�ͽ�β������
                        if (!argName.empty() && argName.front() == '"' && argName.back() == '"') {
                            argName = argName.substr(1, argName.size() - 2);
                        }

                        // �滻ռλ��
                        size_t pos = fmt.find("$" + fields->getArgNameStr(i).str());
                        if (pos != std::string::npos) {
                            fmt.replace(pos, fields->getArgNameStr(i).str().length() + 1, argName);
                        }
                    }

                    oss << fmt << "\n";
                    llvm::outs() << "// Debug: " << oss.str(); // ��ӡ��������
                }
            }
        }
    }
    // ���� Variant
    auto variants = records.getAllDerivedDefinitions("Variant");
    for (const auto *def : variants) {
        std::string variantName = def->getName().str();

        // ��ȡ members �ֶ�
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
            memberList.pop_back(); // �Ƴ����һ������?
        }

        os << formatv(variantDeclStr, variantName, memberList);
    }

    // ���� Enumeration
    const auto &enums = records.getAllDerivedDefinitions("Enumeration");
    for (const auto *enumDef : enums) {
        std::string enumName = enumDef->getName().str(); // ��ȡö�����͵�����

        // ��ȡö��ֵ�б�
        const auto *values = enumDef->getValueAsListInit("values");
        if (!values) {
            os << "enum class " << enumName << " {};\n\n"; // ���ö��ֵ�б��?�գ����ɿ�ö��
            continue;
        }

        os << "enum class " << enumName << " {\n";

        // ����ö��ֵ����ע�ͣ�
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

        os << "\n};\n\n"; // ����ö�ٶ���
    }
}

} // namespace llvm

// // ����ö��ֵ ��ע��
    // for (size_t i = 0; i < values->size(); ++i) {
    //     const auto *value = values->getElement(i);
    //     if (const auto *strValue = dyn_cast<StringInit>(value)) {
    //         // �� StringRef ת��Ϊ std::string
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
//   }