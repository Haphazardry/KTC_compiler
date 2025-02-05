#include <vector>
#include <string>
#include <memory>
#include <variant>
#include <rv64_instr.h>
#include <sstream>
/*
--汇编文件
    ---代码节 .Text
        ----汇编属性 AsmAttr
        ----RISC-V指令 RV64Instr
    ---数据节 .Data
        ----汇编属性
        ----RISC-V指令
    */
namespace KTC{
    // using KTC::RcSymIdx;
    // using KTC::Imm;
    // using KTC::RV64Instr;
    bool ends_with(const std::string& str, const std::string& suffix) {
        return str.size() >= suffix.size() && 
            str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }
   
   // 定义汇编属性结构体
    struct Annotation {
        std::string annotation;
        Annotation(std::string string) : annotation(std::move(string)) {}
    };
    //Align 定义以及输出
    struct Align {
        size_t align;
        Align(size_t size) : align(size) {}
    };
    std::ostream& operator<<(std::ostream& os, const Align& align) {
        return os << "    .align " << align.align;
    }
    //Global 定义以及输出
    struct Global {
        Imm label;
        Global(Imm imm) : label(imm) {}
    };
    std::ostream& operator<<(std::ostream& os, const Global& global) {
        return os << "    .globl " << global.label;
    }
    struct Double {
        Imm imm;
        Double(Imm imm) : imm(imm) {}
    };
    std::ostream& operator<<(std::ostream& os, const Double& dbl) {
        return os << "    .double " << dbl.imm;
    }
    
    struct Word {
        Imm imm;
        Word(Imm imm) : imm(imm) {}
    };
    std::ostream& operator<<(std::ostream& os, const Word& word) {
        return os << "    .word " << word.imm;
    }
    
    struct Half {
        Imm imm;
        Half(Imm imm) : imm(imm) {}
    };
    std::ostream& operator<<(std::ostream& os, const Half& half) {
        return os << "    .half " << half.imm;
    }
    
    struct Byte {
        Imm imm;
        Byte(Imm imm) : imm(imm) {}
    };
    std::ostream& operator<<(std::ostream& os, const Byte& byte) {
        return os << "    .byte " << byte.imm;
    }
    
    struct Zero {
        size_t len;
        Zero(size_t size) : len(size) {}
    };
    std::ostream& operator<<(std::ostream& os, const Zero& zero) {
        return os << "    .zero " << zero.len;
    }
    
    struct Label {
        Imm imm;
        Label(Imm imm) : imm(imm) {}
    };
    std::ostream& operator<<(std::ostream& os, const Label& label) {
        return os << label.imm << ":";
    }

    enum class DataType {
        Object,
        Function
    };
    std::ostream& operator <<(std::ostream& os,DataType dt){
        switch (dt)
        {
        case DataType::Object:
            os<<"@Object";
            break;
        
        case DataType::Function:
            os<<"@Function";
            break;
        }
        return os;
    }
    struct DataTypeAttr {
        DataType attr_ty;
        Imm imm;
        DataTypeAttr(DataType dt, Imm imm) : attr_ty(dt), imm(imm) {}
    };
    std::ostream& operator<<(std::ostream& os, const DataTypeAttr& attr) {
        return os << attr.imm << ", " << attr.attr_ty;
    }

    struct Data {
        Data() = default;
    };
    std::ostream& operator<<(std::ostream& os, const Data&) {
        return os << "    .data";
    }
    
    struct Text {
        Text() = default;
    };
    std::ostream& operator<<(std::ostream& os, const Text&) {
        return os << "    .text";
    }

    // 定义 AsmAttr，表示不同的汇编属性
    // Asm 可能是一个汇编属性（AsmAttr）或 RISC-V 指令（RV64Instr）
    using Asm = std::variant<
        Data,
        Text,
        Annotation,
        Align,
        Global,
        Double,
        Word,
        Half,
        Byte,
        Zero,     
        Label,
        DataTypeAttr,
        RV64Instr>;
        std::ostream& operator<<(std::ostream& os, const Asm& attr) {
            std::visit([&os](auto&& arg) {
                os << arg;  
            }, attr);
            return os;
        }

 

    // AsmSection 表示一个代码或数据节
    class AsmSection {
        std::string sect_name;
        std::vector<std::unique_ptr<Asm>> statements;

    public:
        explicit AsmSection(std::string sectName) : sect_name(std::move(sectName)) {}
        //explicit 防止发生隐式转化，通常构造函数只有一个参数时需要加
        
        void addAnnotation(const std::string& ann) {
            statements.push_back(std::make_unique<Asm>(Annotation(ann)));
        }

        // 添加对齐属性
        void addAlign(size_t align) {
            statements.push_back(std::make_unique<Asm>(Align(align)));
        }

        // 添加全局标签
        void addGlobal(Imm label) {
            statements.push_back(std::make_unique<Asm>(Global(label)));
        }

        // 添加 Double
        void addDouble(Imm imm) {
            statements.push_back(std::make_unique<Asm>(Double(imm)));
        }

        // 添加 Word
        void addWord(Imm imm) {
            statements.push_back(std::make_unique<Asm>(Word(imm)));
        }

        // 添加 Half
        void addHalf(Imm imm) {
            statements.push_back(std::make_unique<Asm>(Half(imm)));
        }

        // 添加 Byte
        void addByte(Imm imm) {
            statements.push_back(std::make_unique<Asm>(Byte(imm)));
        }

        // 添加 Zero
        void addZero(size_t len) {
            statements.push_back(std::make_unique<Asm>(Zero(len)));
        }

        // 添加 Label
        void addLabel(Imm imm) {
            statements.push_back(std::make_unique<Asm>(Label(imm)));
        }

        // 添加 DataTypeAttr
        void addDataTypeAttr(DataType dt, Imm imm) {
            statements.push_back(std::make_unique<Asm>(DataTypeAttr(dt, imm)));
        }

        // 添加指令
        void addInstruction(RV64Instr instr) {
            statements.push_back(std::make_unique<Asm>(instr));
        }

        // 添加数据段
        void addData() {
            statements.push_back(std::make_unique<Asm>(Data()));
        }

        // 添加代码段
        void addText() {
            statements.push_back(std::make_unique<Asm>(Text()));
        }

        std::string dump(bool enable_annotation) const {
            std::ostringstream s;
            s << ".section " << sect_name << "\n";

            for (size_t i = 0; i < statements.size(); i++) {
                const Asm& asm_attr = *statements[i];

                if (!enable_annotation) {
                    if (std::holds_alternative<Annotation>(asm_attr)) {
                        continue;  // 跳过注释
                    }
                }

                if (enable_annotation && std::holds_alternative<Annotation>(asm_attr)) {
                    const Annotation& ann = std::get<Annotation>(asm_attr);
                    bool next_is_annotation = (i + 1 < statements.size() &&
                                               std::holds_alternative<Annotation>(*statements[i + 1]));

                    s << "              # " << ann.annotation;
                    if (!next_is_annotation && !ends_with(ann.annotation,"\n")) {
                        s << "\n";
                    }
                } else {
                    std::visit([&s](auto&& arg) {
                        using T = std::decay_t<decltype(arg)>;
                        if constexpr (std::is_same_v<T, RV64Instr>) {
                            s << "    ";
                            arg.get_string(s);
                        } else {
                            s << arg << "\n";
                        }
                    }, asm_attr);
                }
            }
            return s.str();
        }

    };


}