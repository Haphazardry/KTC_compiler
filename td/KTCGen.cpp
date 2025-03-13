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

    // ÎÄ¼şÍ·£¬°üº¬±ØÒªµÄ¿â
    os << "#include <optional>\n";
    os << "#include <variant>\n";
    os << "#include <vector>\n";
    // os << "#include ";
    os << "#include <memory>\n\n";

    // ´¦Àí GloblStruct ºÍ VariantMember
    const auto &defs = records.getDefs();
    for (const auto &def : defs) {
        const std::string &defName = def.first;     // »ñÈ¡ def µÄÃû³Æ
        const Record *defRecord = def.second.get(); // »ñÈ¡ def µÄ Record ¶ÔÏó

        // Ìø¹ıÅÉÉú×Ô Enumeration µÄ¼ÇÂ¼
        if (defRecord->isSubClassOf("Enumeration")) { continue; }

        // Ìø¹ıÄäÃû¼ÇÂ¼
        if (defRecord->isAnonymous()) { continue; }

        // ¼ì²éÊÇ·ñÊÇ GloblStruct »ò VariantMember
        if (defRecord->isSubClassOf("GloblStruct")) {
            // »ñÈ¡ fields ×Ö¶Î
            const DagInit *fields = defRecord->getValueAsDag("fields");
            if (!fields) {
                os << "// Error: No fields found for " << defName << "\n";
                continue;
            }

            // Éú³É½á¹¹Ìå¶¨Òå
            os << "class " << defName << " {\n";

            // ±éÀú fields µÄÃ¿¸ö²ÎÊı
            for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                const Init *arg = fields->getArg(i);
                std::string argName = fields->getArgNameStr(i).str(); // »ñÈ¡²ÎÊıÀàĞÍ
                std::string argType = arg->getAsString();      // »ñÈ¡²ÎÊıÃû³Æ

                // È¥µô argType µÄ¿ªÍ·ºÍ½áÎ²µÄÒıºÅ
                if (!argType.empty() && argType.front() == '"' && argType.back() == '"') {
                    argType = argType.substr(1, argType.size() - 2);
                }
                
                os << "    " << argType << " " << argName << ";\n";
            }

            os << "};\n\n";

            // Éú³Éµ÷ÊÔĞÅÏ¢²¢´òÓ¡µ½ÃüÁîĞĞ
            if (defRecord->getValue("fmt")) {
                std::string fmt = defRecord->getValueAsString("fmt").str(); // »ñÈ¡ fmt ×Ö¶Î
                 // Èç¹û fmt ·Ç¿Õ£¬ÔòÉú³Éµ÷ÊÔĞÅÏ¢
                if (!fmt.empty()) {
                    std::ostringstream oss;

                    // Ìæ»» fmt ÖĞµÄÕ¼Î»·û
                    for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                        const Init *arg = fields->getArg(i);
                        std::string argName = arg->getAsString();

                        // È¥µô argName µÄ¿ªÍ·ºÍ½áÎ²µÄÒıºÅ
                        if (!argName.empty() && argName.front() == '"' && argName.back() == '"') {
                            argName = argName.substr(1, argName.size() - 2);
                        }

                        // Ìæ»»Õ¼Î»·û
                        size_t pos = fmt.find("$" + fields->getArgNameStr(i).str());
                        if (pos != std::string::npos) {
                            fmt.replace(pos, fields->getArgNameStr(i).str().length() + 1, argName);
                        }
                    }

                    oss << fmt << "\n";
                    llvm::outs() << "// Debug: " << oss.str(); // ´òÓ¡µ½ÃüÁîĞĞ
                }
            }
        }
    }
    // ´¦Àí Variant
    auto variants = records.getAllDerivedDefinitions("Variant");
    for (const auto *def : variants) {
        std::string variantName = def->getName().str();

        // »ñÈ¡ members ×Ö¶Î
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
            memberList.pop_back(); // ÒÆ³ı×îºóÒ»¸ö¶ººÅ
        }

        os << formatv(variantDeclStr, variantName, memberList);
    }

    // ´¦Àí Enumeration
    const auto &enums = records.getAllDerivedDefinitions("Enumeration");
    for (const auto *enumDef : enums) {
        std::string enumName = enumDef->getName().str(); // »ñÈ¡Ã¶¾ÙÀàĞÍµÄÃû³Æ

        // »ñÈ¡Ã¶¾ÙÖµÁĞ±í
        const auto *values = enumDef->getValueAsListInit("values");
        if (!values) {
            os << "enum class " << enumName << " {};\n\n"; // Èç¹ûÃ¶¾ÙÖµÁĞ±íÎª¿Õ£¬Éú³É¿ÕÃ¶¾Ù
            continue;
        }

        os << "enum class " << enumName << " {\n";

        // ±éÀúÃ¶¾ÙÖµ£¨´ø×¢ÊÍ£©
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

        os << "\n};\n\n"; // ½áÊøÃ¶¾Ù¶¨Òå
    }
}

} // namespace llvm

// // ±éÀúÃ¶¾ÙÖµ ÎŞ×¢ÊÍ
    // for (size_t i = 0; i < values->size(); ++i) {
    //     const auto *value = values->getElement(i);
    //     if (const auto *strValue = dyn_cast<StringInit>(value)) {
    //         // ½« StringRef ×ª»»Îª std::string
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

    // æ–‡ä»¶å¤´ï¼ŒåŒ…å«å¿…è¦çš„åº“
    os << "#include <optional>\n";
    os << "#include <variant>\n";
    os << "#include <vector>\n";
    // os << "#include ";
    os << "#include <memory>\n\n";

    // å¤„ç† GloblStruct å’Œ VariantMember
    const auto &defs = records.getDefs();
    for (const auto &def : defs) {
        const std::string &defName = def.first;     // è·å– def çš„åç§°
        const Record *defRecord = def.second.get(); // è·å– def çš„ Record å¯¹è±¡

        // è·³è¿‡æ´¾ç”Ÿè‡ª Enumeration çš„è®°å½•
        if (defRecord->isSubClassOf("Enumeration")) { continue; }

        // è·³è¿‡åŒ¿åè®°å½•
        if (defRecord->isAnonymous()) { continue; }

        // æ£€æŸ¥æ˜¯å¦æ˜¯ GloblStruct æˆ– VariantMember
        if (defRecord->isSubClassOf("Struct")) {
            // è·å– fields å­—æ®µ
            const DagInit *fields = defRecord->getValueAsDag("fields");
            if (!fields) {
                os << "// Error: No fields found for " << defName << "\n";
                continue;
            }

            // ç”Ÿæˆç»“æ„ä½“å®šä¹‰
            os << "class " << defName << " {\n";

            // éå† fields çš„æ¯ä¸ªå‚æ•°
            for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                const Init *arg = fields->getArg(i);
                std::string argName = fields->getArgNameStr(i).str(); // è·å–å‚æ•°ç±»å‹
                std::string argType = arg->getAsString();      // è·å–å‚æ•°åç§°

                // å»æ‰ argType çš„å¼€å¤´å’Œç»“å°¾çš„å¼•å·
                if (!argType.empty() && argType.front() == '"' && argType.back() == '"') {
                    argType = argType.substr(1, argType.size() - 2);
                }
                
                os << "    " << argType << " " << argName << ";\n";
            }

            os << "};\n\n";

            // ç”Ÿæˆè°ƒè¯•ä¿¡æ¯å¹¶æ‰“å°åˆ°å‘½ä»¤è¡Œ
            if (defRecord->getValue("fmt")) {
                std::string fmt = defRecord->getValueAsString("fmt").str(); // è·å– fmt å­—æ®µ
                 // å¦‚æœ fmt éç©ºï¼Œåˆ™ç”Ÿæˆè°ƒè¯•ä¿¡æ¯
                if (!fmt.empty()) {
                    std::ostringstream oss;

                    // æ›¿æ¢ fmt ä¸­çš„å ä½ç¬¦
                    for (unsigned i = 0; i < fields->getNumArgs(); ++i) {
                        const Init *arg = fields->getArg(i);
                        std::string argName = arg->getAsString();

                        // å»æ‰ argName çš„å¼€å¤´å’Œç»“å°¾çš„å¼•å·
                        if (!argName.empty() && argName.front() == '"' && argName.back() == '"') {
                            argName = argName.substr(1, argName.size() - 2);
                        }

                        // æ›¿æ¢å ä½ç¬¦
                        size_t pos = fmt.find("$" + fields->getArgNameStr(i).str());
                        if (pos != std::string::npos) {
                            fmt.replace(pos, fields->getArgNameStr(i).str().length() + 1, argName);
                        }
                    }

                    oss << fmt << "\n";
                    llvm::outs() << "// Debug: " << oss.str(); // æ‰“å°åˆ°å‘½ä»¤è¡Œ
                }
            }
        }
    }
    // å¤„ç† Variant
    auto variants = records.getAllDerivedDefinitions("Variant");
    for (const auto *def : variants) {
        std::string variantName = def->getName().str();

        // è·å– members å­—æ®µ
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
            memberList.pop_back(); // ç§»é™¤æœ€åä¸€ä¸ªé€—å·
        }

        os << formatv(variantDeclStr, variantName, memberList);
    }

    // å¤„ç† Enumeration
    const auto &enums = records.getAllDerivedDefinitions("Enumeration");
    for (const auto *enumDef : enums) {
        std::string enumName = enumDef->getName().str(); // è·å–æšä¸¾ç±»å‹çš„åç§°

        // è·å–æšä¸¾å€¼åˆ—è¡¨
        const auto *values = enumDef->getValueAsListInit("values");
        if (!values) {
            os << "enum class " << enumName << " {};\n\n"; // å¦‚æœæšä¸¾å€¼åˆ—è¡¨ä¸ºç©ºï¼Œç”Ÿæˆç©ºæšä¸¾
            continue;
        }

        os << "enum class " << enumName << " {\n";

        // éå†æšä¸¾å€¼ï¼ˆå¸¦æ³¨é‡Šï¼‰
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

        os << "\n};\n\n"; // ç»“æŸæšä¸¾å®šä¹‰
    }
}

} // namespace llvm

// // éå†æšä¸¾å€¼ æ— æ³¨é‡Š
    // for (size_t i = 0; i < values->size(); ++i) {
    //     const auto *value = values->getElement(i);
    //     if (const auto *strValue = dyn_cast<StringInit>(value)) {
    //         // å°† StringRef è½¬æ¢ä¸º std::string
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