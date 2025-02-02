#include <vector>
#include <string>
#include <memory>
#include <variant>
#include <rv64_instr.h>
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
    using KTC::SymIdx;
    using KTC::Imm;
    using KTC::RV64Instr;
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
    }

   // 定义汇编属性结构体
    struct Annotation {
        std::string annotation;
        Annotation(std::string string) : annotation(std::move(string)) {}
    };

    struct Align {
        size_t align;
        Align(size_t size) : align(size) {}
    };

    struct Global {
        Imm label;
        Global(Imm imm) : label(imm) {}
    };

    struct Double {
        Imm imm;
        Double(Imm imm) : imm(imm) {}
    };

    struct Word {
        Imm imm;
        Word(Imm imm) : imm(imm) {}
    };

    struct Half {
        Imm imm;
        Half(Imm imm) : imm(imm) {}
    };

    struct Byte {
        Imm imm;
        Byte(Imm imm) : imm(imm) {}
    };

    struct Zero {
        size_t len;
        Zero(size_t size) : len(size) {}
    };

    struct Label {
        Imm imm;
        Label(Imm imm) : imm(imm) {}
    };

    struct DataTypeAttr {
        DataType attr_ty;
        Imm imm;
        DataTypeAttr(DataType dt, Imm imm) : attr_ty(dt), imm(imm) {}
    };

    // 定义 Data 和 Text 结构体
    struct Data {
        Data() = default;
    };

    struct Text {
        Text() = default;
    };

    // 定义 AsmAttr，表示不同的汇编属性
    using AsmAttr = std::variant<
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
        DataTypeAttr>;

    // Asm 可能是一个汇编属性（AsmAttr）或 RISC-V 指令（RV64Instr）
    using Asm = std::variant<AsmAttr, RV64Instr>;

    // AsmSection 表示一个代码或数据节
    class AsmSection {
        std::string name;
        std::vector<std::unique_ptr<Asm>> statements;

    public:
        explicit AsmSection(std::string sectName) : name(std::move(sectName)) {}
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
        void addInstruction(BaseIntInstrVarint instr) {
            statements.push_back(std::make_unique<Asm>(RV64Instr(std::move(instr))));
        }

        // 添加数据段
        void addData() {
            statements.push_back(std::make_unique<Asm>(Data()));
        }

        // 添加代码段
        void addText() {
            statements.push_back(std::make_unique<Asm>(Text()));
        }

    
    };

}