#pragma  once
#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <cmath>
#include <variant>
#include <vector>

#include "register.h"
#include "symtab.h"
namespace KTC{
//using SymIdx = std::shared_ptr<std::string>; // SymIdx是一个int类型的共享指针?

    // 定义Imm类
class Imm {
public:
    enum class Type {
        GlobalLabel,
        LocalLabel,
        Literal
    };
    Imm(){}
    Imm(Type type, SymIdx symidx) : type(type), symidx(symidx) {}

    static Imm new_local_label(SymIdx label) {
        return Imm(Type::LocalLabel, label);
    }

    static Imm new_global_label(SymIdx label) {
        return Imm(Type::GlobalLabel, label);
    }

    static Imm new_literal(SymIdx symidx) {
        return Imm(Type::Literal, symidx);
    }

    static Imm new_literal_isize(int li) {
        return Imm(Type::Literal, SymIdx(0,std::to_string(li)) );
    }

    // static Imm from_offset(int offset) {
    //     if (offset < -2048 || offset > 2047) {  // 12位立即数
    //         throw std::runtime_error("you can't use an offset from");
    //     }
    //     return Imm(Type::Literal, std::make_shared<std::string>(std::to_string(offset)));   //int类型的共享指针
    // }

    friend std::ostream& operator<<(std::ostream& os, const Imm& imm){
    switch (imm.type) {
        case Imm::Type::GlobalLabel:
            os << imm.symidx.symbol_name ;
            break;
        case Imm::Type::LocalLabel:
            os << imm.symidx.symbol_name ;
            break;
        case Imm::Type::Literal:
            os << imm.symidx.symbol_name ;
            break;
    }
    return os;
    
}


private:
    Type type;
    SymIdx symidx;
};

// std::ostream& operator<<(std::ostream& os, const Imm& imm) {
//     switch (imm.type) {
//         case Imm::Type::GlobalLabel:
//             os << imm.symidx.symbol_name ;
//             break;
//         case Imm::Type::LocalLabel:
//             os << imm.symidx.symbol_name ;
//             break;
//         case Imm::Type::Literal:
//             os << imm.symidx.symbol_name ;
//             break;
//     }
//     return os;
// }


// 定义Shifts类
class Shifts  {
public:
    enum class Type {
        // {rd,rs1,rs2} 逻辑左移,将寄存器rs1值左移寄存器rs2值的低6位（rv64I）存到寄存器rd中
        Sll,Sllw,
        // {rd,rs1,shamt} 立即数左移
        Slli,Slliw,
        // {rd,rs1,rs2} 逻辑右移动
        Srl,Srlw,
        // {rd,rs1,shamt} 立即数右移
        Srli,Srliw,
        // {rd,rs1,rs2} 算术右移
        Sra,Sraw,
        // {rd,rs1,shamt} 立即数算术右移
        Srai,Sraiw
    };
    // 对于不同的指令类型，参数不同,我在这里使用了函数重载
    // {rd,rs1,rs2}
    Shifts(Type type, Register rd, Register rs1, Register rs2)
        : type(type), rd(rd), rs1(rs1), rs2(rs2) {}
    // {rd,rs1,imm}
    Shifts(Type type, Register rd, Register rs1,  Imm shamt = Imm::new_literal_isize(0))
        : type(type), rd(rd), rs1(rs1), shamt(shamt) {}
    // Shifts(Type type, Register rd, Register rs1, Register rs2 = Register(), Imm shamt = Imm())
    //     : type(type), rd(rd), rs1(rs1), rs2(rs2), shamt(shamt) {}

    void get_string(std::ostream& os) const{
        switch (type) {
            case Type::Sll:
                os << "sll " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::Slli:
                os << "slli " << rd << ", " << rs1 << ", " << shamt;
                break;
            case Type::Srl:
                os << "srl " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::Srli:
                os << "srli " << rd << ", " << rs1 << ", " << shamt;
                break;
            case Type::Sra:
                os << "sra " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::Srai:
                os << "srai " << rd << ", " << rs1 << ", " << shamt;
                break;
            case Type::Sllw:
                os << "sllw " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::Slliw:
                os << "slliw " << rd << ", " << rs1 << ", " << shamt;
                break;
            case Type::Srlw:
                os << "srlw " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::Srliw:
                os << "srliw " << rd << ", " << rs1 << ", " << shamt;
                break;
            case Type::Sraw:
                os << "sraw " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::Sraiw:
                os << "sraiw " << rd << ", " << rs1 << ", " << shamt;
                break;
        }
    }
    
    // Shifts new_slli_from_multiple(Register re1,Register re2, int mul){
    //     //usize 没定义，懒得研究怎么定义了，后面再补
    // }
    // friend std::ostream& operator<<(std::ostream& os, const Shifts& instr);
private:
    Type type;
    Register rd;
    Register rs1;
    Register rs2;
    Imm shamt;
};

//定义Arithmetic 类
class Arithmetic {
public:
    enum class Type{
        ADD,ADDW,   // {rd,rs1,rs2}
        ADDI,ADDIW, // {rd,rs1,imm}
        SUB,SUBW,   // {rd,rs1,rs2}
        LUI,        // {rd,imm} 高位立即数加载
        AUIPC,      // {rd,imm}    

        MUL,        // {rd,rs1,rs2}
        MULW,       // {rd,rs1,rs2}
        DIV,        // {rd,rs1,rs2}
        DIVW,       // {rd,rs1,rs2}
        REM,        // {rd,rs1,rs2}
        REMW,       // {rd,rs1,rs2}

        FADDS,      // {rd,rs1,rs2}
        FSUBS,      // {rd,rs1,rs2}
        FMULS,      // {rd,rs1,rs2}
        FDIVS,      // {rd,rs1,rs2}
        FSQRTS      // {rd,rs1,rs2}
    };

    // {rd,rs1,rs2} 
    Arithmetic(Type type, Register rd, Register rs1, Register rs2 )
        : type(type), rd(rd), rs1(rs1), rs2(rs2){}
    // {rd,rs1,imm}
    Arithmetic(Type type, Register rd, Register rs1,  Imm imm = Imm())
        : type(type), rd(rd), rs1(rs1), imm(imm) {}
    // {rd,imm}
    Arithmetic(Type type, Register rd, Imm imm = Imm())
        : type(type), rd(rd), imm(imm) {}
    void get_string(std::ostream& os) const{
        switch (type) {
            case Type::ADD:
                os << "add " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::ADDI:
                os << "addi " << rd << ", " << rs1 << ", " << imm;
                break;
            case Type::SUB:
                os << "sub " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::LUI:
                os << "lui " << rd << ", " << imm;
                break;
            case Type::AUIPC:
                os << "auipc " << rd << ", " << imm;
                break;
            case Type::ADDW:
                os << "addw " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::ADDIW:
                os << "addiw " << rd << ", " << rs1 << ", " << imm;
                break;
            case Type::SUBW:
                os << "subw " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::MUL:
                os << "mul " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::MULW:
                os << "mulw " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::DIV:
                os << "div " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::DIVW:
                os << "divw " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::REM:
                os << "rem " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::REMW:
                os << "remw " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::FADDS:
                os << "fadd.s " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::FSUBS:
                os << "fsub.s " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::FMULS:
                os << "fmul.s " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::FDIVS:
                os << "fdiv.s " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::FSQRTS:
                os << "fsqrt.s " << rd << ", " << rs1;
                break;
            default:
                throw std::runtime_error("Unknown arithmetic instruction type");
        }
    }

private:
    Type type;
    Register rd;
    Register rs1;
    Register rs2;
    Imm imm;
};

// 定义Logical 类
class Logical  {
public:
    enum class Type {
        XOR,   // {rd, rs1, rs2}
        XORI,  // {rd, rs1, imm}
        OR,    // {rd, rs1, rs2}
        ORI,   // {rd, rs1, imm}
        AND,   // {rd, rs1, rs2}
        ANDI   // {rd, rs1, imm}
    };

    // {rd, rs1, rs2}
    Logical(Type type, Register rd, Register rs1, Register rs2 )
        : type(type), rd(rd), rs1(rs1), rs2(rs2){}
    // {rd, rs1, imm}
    Logical(Type type, Register rd, Register rs1, Imm imm )
        : type(type), rd(rd), rs1(rs1), imm(imm) {}

    void get_string(std::ostream& os)  const{
        switch (type) {
            case Type::XOR:
                os << "xor " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::XORI:
                os << "xori " << rd << ", " << rs1 << ", " << imm;
                break;
            case Type::OR:
                os << "or " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::ORI:
                os << "ori " << rd << ", " << rs1 << ", " << imm;
                break;
            case Type::AND:
                os << "and " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::ANDI:
                os << "andi " << rd << ", " << rs1 << ", " << imm;
                break;
            default:
                throw std::runtime_error("Unknown logical instruction type");
        }
    }

private:
    Type type;
    Register rd;
    Register rs1;
    Register rs2;
    Imm imm;
};

// 定义Compare 类
class Compare  {
public:
    enum class Type {
        SLT,    // {rd, rs1, rs2}
        SLTI,   // {rd, rs1, imm}
        SLTU,   // {rd, rs1, rs2}
        SLTIU,  // {rd, rs1, imm}
        FEQ_S,  // {rd, rs1, rs2}
        // 单浮点精度比较
        FLT_S,  // {rd, rs1, rs2}
        FLE_S   // {rd, rs1, rs2}
    };
    // {rd, rs1, rs2}
    Compare(Type type, Register rd, Register rs1, Register rs2  )
        : type(type), rd(rd), rs1(rs1), rs2(rs2) {}
    // {rd, rs1, imm}
    Compare(Type type, Register rd, Register rs1, Imm imm )
        : type(type), rd(rd), rs1(rs1), imm(imm) {}

    // Compare(Type type, Register rd, Register rs1, Register rs2 =Register() , Imm imm = Imm())
    //     : type(type), rd(rd), rs1(rs1), rs2(rs2), imm(imm) {}

    void get_string(std::ostream& os) const{
        switch (type) {
            case Type::SLT:
                os << "slt " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::SLTI:
                os << "slti " << rd << ", " << rs1 << ", " << imm;
                break;
            case Type::SLTU:
                os << "sltu " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::SLTIU:
                os << "sltiu " << rd << ", " << rs1 << ", " << imm;
                break;
            case Type::FEQ_S:
                os << "feq.s " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::FLT_S:
                os << "flt.s " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::FLE_S:
                os << "fle.s " << rd << ", " << rs1 << ", " << rs2;
                break;
            default:
                throw std::runtime_error("Unknown compare instruction type");
        }
    }

private:
    Type type;
    Register rd;
    Register rs1;
    Register rs2;
    Imm imm;
};

// 定义Branch 类
class Branch  {
public:
    enum class Type {
        BEQ,   // {rs1, rs2, imm}
        BNE,   // {rs1, rs2, imm}
        BLT,   // {rs1, rs2, imm}
        BGE,   // {rs1, rs2, imm}
        BLTU,  // {rs1, rs2, imm}
        BGEU   // {rs1, rs2, imm}
    };
    // {rs1, rs2, imm}
    Branch(Type type, Register rs1, Register rs2, Imm imm)
        : type(type), rs1(rs1), rs2(rs2), imm(imm) {}


    void get_string(std::ostream& os) const{
        switch (type) {
            case Type::BEQ:
                os << "beq " << rs1 << ", " << rs2 << ", " << imm;
                break;
            case Type::BNE:
                os << "bne " << rs1 << ", " << rs2 << ", " << imm;
                break;
            case Type::BLT:
                os << "blt " << rs1 << ", " << rs2 << ", " << imm;
                break;
            case Type::BGE:
                os << "bge " << rs1 << ", " << rs2 << ", " << imm;
                break;
            case Type::BLTU:
                os << "bltu " << rs1 << ", " << rs2 << ", " << imm;
                break;
            case Type::BGEU:
                os << "bgeu " << rs1 << ", " << rs2 << ", " << imm;
                break;
            default:
                throw std::runtime_error("Unknown branch instruction type");
        }
    }

private:
    Type type;
    Register rs1;
    Register rs2;
    Imm imm;
};

// 定义JumpAndLink 类
class JumpAndLink  {
public:
    enum class Type {
        JAL,   // {rd, imm}
        JALR   // {rd, rs1, imm}
    };

    // {rd, imm}
    JumpAndLink(Type type, Register rd, Imm imm )
        : type(type), rd(rd), rs1(rs1), imm(imm) {}
    // {rd, rs1, imm}
    JumpAndLink(Type type, Register rd, Register rs1 ,Imm imm )
        : type(type), rd(rd), rs1(rs1), imm(imm) {}
    // JumpAndLink(Type type, Register rd, Register rs1 = Register(), Imm imm = Imm())
    //     : type(type), rd(rd), rs1(rs1), imm(imm) {}

    void get_string(std::ostream& os)  const{
        switch (type) {
            case Type::JAL:
                os << "jal " << rd << ", " << imm;
                break;
            case Type::JALR:
                os << "jalr " << rd << ", " << rs1 << ", " << imm;
                break;
            default:
                throw std::runtime_error("Unknown jump and link instruction type");
        }
    }

private:
    Type type;
    Register rd;
    Register rs1;
    Imm imm;
};

// 定义Environment 类
class Environment {
public:
    enum class Type {
        ECALL,   // 环境调用
        EBREAK   // 断点
    };

    Environment(Type type) : type(type) {}

    void get_string(std::ostream& os)  const{
        switch (type) {
            case Type::ECALL:
                os << "ecall";
                break;
            case Type::EBREAK:
                os << "ebreak";
                break;
            default:
                throw std::runtime_error("Unknown environment instruction type");
        }
    }

private:
    Type type;
};

// 定义CSR 类
class CSR {
public:
    enum class Type {
        CSRRW,   // {rd, csr, rs1}
        CSRRS,   // {rd, csr, rs1}
        CSRRC,   // {rd, csr, rs1}
        CSRRWI,  // {rd, csr, imm}
        CSRRSI,  // {rd, csr, imm}
        CSRRCI   // {rd, csr, imm}
    };

    //  {rd, csr, rs1}
    CSR(Type type, Register rd, Register csr, Register rs1  )
        : type(type), rd(rd), csr(csr), rs1(rs1) {}
    // {rd, csr, imm}
    CSR(Type type, Register rd, Register csr,  Imm imm )
        : type(type), rd(rd), csr(csr), imm(imm) {}
    // CSR(Type type, Register rd, Register csr, Register rs1 = Register(), Imm imm = Imm())
    //     : type(type), rd(rd), csr(csr), rs1(rs1), imm(imm) {}

    void get_string(std::ostream& os) const{
        switch (type) {
            case Type::CSRRW:
                os << "csrrw " << rd << ", " << csr << ", " << rs1;
                break;
            case Type::CSRRS:
                os << "csrrs " << rd << ", " << csr << ", " << rs1;
                break;
            case Type::CSRRC:
                os << "csrrc " << rd << ", " << csr << ", " << rs1;
                break;
            case Type::CSRRWI:
                os << "csrrwi " << rd << ", " << csr << ", " << imm;
                break;
            case Type::CSRRSI:
                os << "csrrsi " << rd << ", " << csr << ", " << imm;
                break;
            case Type::CSRRCI:
                os << "csrrci " << rd << ", " << csr << ", " << imm;
                break;
            default:
                throw std::runtime_error("Unknown CSR instruction type");
        }
    }

private:
    Type type;
    Register rd;
    Register csr;
    Register rs1;
    Imm imm;
};

// 定义Loads 类
class Loads  {
public:
    enum class Type {
        LB,    // {rd, rs1, imm}
        LH,    // {rd, rs1, imm}
        LBU,   // {rd, rs1, imm}
        LHU,   // {rd, rs1, imm}
        LWU,   // {rd, rs1, imm}
        LW,    // {rd, rs1, imm}
        LD,    // {rd, rs1, imm}
        FLW,   // {rd, rs1, imm}
        FLD    // {rd, rs1, imm}
    };

    Loads(Type type, Register rd, Register rs1, Imm imm)
        : type(type), rd(rd), rs1(rs1), imm(imm) {}

    void get_string(std::ostream& os)  const{
        switch (type) {
            case Type::LB:
                os << "lb " << rd << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::LH:
                os << "lh " << rd << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::LBU:
                os << "lbu " << rd << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::LHU:
                os << "lhu " << rd << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::LWU:
                os << "lwu " << rd << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::LW:
                os << "lw " << rd << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::LD:
                os << "ld " << rd << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::FLW:
                os << "flw " << rd << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::FLD:
                os << "fld " << rd << ", " << imm << "(" << rs1 << ")";
                break;
            default:
                throw std::runtime_error("Unknown load instruction type");
        }
    }

private:
    Type type;
    Register rd;
    Register rs1;
    Imm imm;
};

// 定义Stores 类
class Stores {
public:
    enum class Type {
        SB,    // {rs1, rs2, imm}   命令写法为 sb rs2, imm(rs1)
        SH,    // {rs1, rs2, imm}   命令写法为 sh rs2, imm(rs1)
        SW,    // {rs1, rs2, imm}   命令写法为 sw rs2, imm(rs1)
        SD,    // {rs1, rs2, imm}   命令写法为 sd rs2, imm(rs1)
        FSW,   // {rs1, rs2, imm}   命令写法为 fsw rs2, imm(rs1)
        FSD    // {rs1, rs2, imm}   命令写法为 fsd rs2, imm(rs1)
    };


    Stores(Type type, Register rs1, Register rs2, Imm imm)
        : type(type), rs1(rs1), rs2(rs2), imm(imm) {}

    void get_string(std::ostream& os) const{
        switch (type) {
            case Type::SB:
                os << "sb " << rs2 << ", " << imm << "(" << rs1 << ")";// 这里注意顺序,rs2在前,rs1在后
                break;
            case Type::SH:
                os << "sh " << rs2 << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::SW:
                os << "sw " << rs2 << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::SD:
                os << "sd " << rs2 << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::FSW:
                os << "fsw " << rs2 << ", " << imm << "(" << rs1 << ")";
                break;
            case Type::FSD:
                os << "fsd " << rs2 << ", " << imm << "(" << rs1 << ")";
                break;
            default:
                throw std::runtime_error("Unknown store instruction type");
        }
    }

private:
    Type type;
    Register rs1;
    Register rs2;
    Imm imm;
};

// 定义Trans 类
class Trans {
public:
    enum class Type {
        FCVT_W_S,  // {rd, rs1}把寄存器 x[rs1]中的 32 位二进制补码表示的整数转化为单精度浮点数，再写入 f[rd]中。
        FCVT_S_W   // {rd, rs1}把寄存器 f[rs1]中的单精度浮点数转化为 32 位二进制补码表示的整数，再写入 x[rd]中。
    };

    // 构造函数
    Trans(Type type, Register rd, Register rs1)
        : type(type), rd(rd), rs1(rs1) {}

    void get_string(std::ostream& os) const{
        switch (type) {
            case Type::FCVT_W_S:
                os << "fcvt.w.s " << rd << ", " << rs1 << ", rtz";
                break;
            case Type::FCVT_S_W:
                os << "fcvt.s.w " << rd << ", " << rs1 << ", rtz";
                break;
            default:
                throw std::runtime_error("Unknown trans instruction type");
        }
    }

private:
    Type type;
    Register rd;
    Register rs1;
};

// 定义MulAdd 类
class MulAdd {
public:
    enum class Type {
        FMADDS,   // {rd, rs1, rs2, rs3}
        FMSUBS,   // {rd, rs1, rs2, rs3}
        FNMADDS,  // {rd, rs1, rs2, rs3}
        FNMSUBS   // {rd, rs1, rs2, rs3}
    };

    MulAdd(Type type, Register rd, Register rs1, Register rs2, Register rs3)
        : type(type), rd(rd), rs1(rs1), rs2(rs2), rs3(rs3) {}

    void get_string(std::ostream& os)  const{
        switch (type) {
            case Type::FMADDS:
                os << "fmadd.s " << rd << ", " << rs1 << ", " << rs2 << ", " << rs3;
                break;
            case Type::FMSUBS:
                os << "fmsub.s " << rd << ", " << rs1 << ", " << rs2 << ", " << rs3;
                break;
            case Type::FNMADDS:
                os << "fnmadd.s " << rd << ", " << rs1 << ", " << rs2 << ", " << rs3;
                break;
            case Type::FNMSUBS:
                os << "fnmsub.s " << rd << ", " << rs1 << ", " << rs2 << ", " << rs3;
                break;
            default:
                throw std::runtime_error("Unknown muladd instruction type");
        }
    }

private:
    Type type;
    Register rd;
    Register rs1;
    Register rs2;
    Register rs3;
};

// 定义MinMax 类
class MinMax {
public:
    enum class Type {
        FMINS,  // {rd, rs1, rs2}
        FMAXS   // {rd, rs1, rs2}
    };

    MinMax(Type type, Register rd, Register rs1, Register rs2)
        : type(type), rd(rd), rs1(rs1), rs2(rs2) {}

    void get_string(std::ostream& os)  const{
        switch (type) {
            case Type::FMINS:
                os << "fmin.s " << rd << ", " << rs1 << ", " << rs2;
                break;
            case Type::FMAXS:
                os << "fmax.s " << rd << ", " << rs1 << ", " << rs2;
                break;
            default:
                throw std::runtime_error("Unknown minmax instruction type");
        }
    }

private:
    Type type;
    Register rd;
    Register rs1;
    Register rs2;
};

// 定义BaseIntInstr 类
class PseudoInstr {
public:
    enum class Type {
        Nop,    // {} 无操作指令
        Neg,    // {rd,rs} rs取反存到rd中，使用64为
        Negw,   // {rd,rs} rs取反存到rd中,截取32位，最后拓展

        // 和0直接比
        Snez,   // {rd,rs} 如果rs非零，则将1存入寄存器rd中
        Sltz,   // {rd,rs} 如果rs小于零，则将1存入寄存器rd中
        Sgtz,   // {rd,rs} 如果rs大于零，则将1存入寄存器rd中
        Seqz,   // {rd,rs} 如果rs等于零，则将1存入寄存器rd中

        // 有条件跳转
        /// 和0比
        Beqz,   // {rd,offset} 如果rs等于零，则根据offset进行分支，pc+offset
        Bnez,   // {rd,offset} 如果rs不等于零，则根据offset进行分支，pc+offset
        Blez,   // {rd,offset} 如果rs小于等于零，则根据offset进行分支，pc+offset
        Bgez,   // {rd,offset} 如果rs大于等于零，则根据offset进行分支，pc+offset
        Bltz,   // {rd,offset} 如果rs小于零，则根据offset进行分支，pc+offset
        Bgtz,   // {rd,offset} 如果rs大于零，则根据offset进行分支，pc+offset
        /// 两两比较
        Bgt,    // {rs1,rs2,offset} 如果rs1大于rs2的值(有符号数)，则根据offset进行分支 
        Ble,    // {rs1,rs2,offset} 如果rs1小于rs2的值(有符号数)，则根据offset进行分支
        Bgtu,   // {rs1,rs2,offset} 如果rs1大于rs2的值(无符号数)，则根据offset进行分支
        Bleu,   // {rs1,rs2,offset} 如果rs1小于等于rs2的值(无符号数)，则根据offset进行分支
        
        // 无条件跳转
        J,      // {offset} 无条件跳转到指定偏移量
        Jr,     // {rs} 无条件跳转到寄存器rs指示的地址/返回调用函数
        Ret,
        Tail,   // {offset} 用于尾调用优化，跳转到偏移量offset指示的地址

        // //特殊寄存器操作
        // Rdinstret,  //{rd} 读取特定硬件寄存器（如指令计数器、周期计数器、时间寄存器）的值到寄存器rd中
        // Rdinstreth,
        // Rdcycle,
        // Rdcycleh,
        // Rdtime,
        // Rdtimeh,

        //内存访问load
        Lla,        // {rd,symbol} 加载指定加载局部或相对地址到寄存器rd中
        La,         // {rd,symbol} 加载全局或绝对地址到寄存器rd中         
        

        Fmv_s,      // {rd,rs} 单精度浮点移动
        Fmv_x_w,    // {rd,rs} 单精度浮点移动，带扩展
        Fabs_s,     // {rd,rs} 单精度取绝对值
        Fneg_s,     // {rd,rs} 单精度取反
        Fmv_d,      // {rd,rs} 双精度浮点移动
        Fabs_d,     // {rd,rs} 双精度取绝对值
        Fneg_d,     // {rd,rs} 双精度取反
        
        Li,         // {rd,imm} 将立即数imm加载到寄存器rd中
        Mv,         // {rd,rs} 将寄存器rs的值移动到寄存器rd中
        Not,        // {rd,rs} 将寄存器rs的值位取反存到寄存器rd中
        Sext_w,     // {rd,rs} 将寄存器rs的值有符号扩展到寄存器rd中
        
        Jal,        // {offset}
        Jalr,       // {rs}
        Call,       // {offset}
        Fence       // {}
    };

    // Nop Ret
    PseudoInstr(){}
    // {rd,rs}
    PseudoInstr(Type type, Register rd, Register rs1)
        : type(type), rd(rd), rs1(rs1) {}
    // {rd,imm}
    PseudoInstr(Type type, Register rd, Imm imm )
        : type(type), rd(rd),  imm(imm) {}
    // {rs1,rs2,imm}
    PseudoInstr(Type type, Register rs1, Register rs2, Imm imm)
        : type(type), rs1(rs1), rs2(rs2), imm(imm) {}
    // {imm}
    PseudoInstr(Type type, Imm imm)
        : type(type), imm(imm) {}
    // {rs1}
    PseudoInstr(Type type, Register rs1)
        : type(type), rs1(rs1) {}

    // PseudoInstr(Type type, Register rd, Register rs1, Imm imm = Imm::new_literal_isize(0))
    //     : type(type), rd(rd), rs1(rs1), imm(imm) {}

    void get_string(std::ostream& os) const {
        switch (type) {
            case Type::Nop:
                os << "nop";
                break;
            case Type::Neg:
                os << "neg " << rd << ", " << rs1;
                break;
            case Type::Negw:
                os << "negw " << rd << ", " << rs1;
                break;
            case Type::Snez:
                os << "snez " << rd << ", " << rs1;
                break;
            case Type::Sltz:
                os << "sltz " << rd << ", " << rs1;
                break;
            case Type::Sgtz:
                os << "sgtz " << rd << ", " << rs1;
                break;
            case Type::Seqz:
                os << "seqz " << rd << ", " << rs1;
                break;
            case Type::Beqz:
                os << "beqz " << rs1 << ", " << imm;
                break;
            case Type::Bnez:
                os << "bnez " << rs1 << ", " << imm;
                break;
            case Type::Blez:
                os << "blez " << rs1 << ", " << imm;
                break;
            case Type::Bgez:
                os << "bgez " << rs1 << ", " << imm;
                break;
            case Type::Bltz:
                os << "bltz " << rs1 << ", " << imm;
                break;
            case Type::Bgtz:
                os << "bgtz " << rs1 << ", " << imm;
                break;
            case Type::Bgt:
                os << "bgt " << rs1 << ", " << rd << ", " << imm;
                break;
            case Type::Ble:
                os << "ble " << rs1 << ", " << rd << ", " << imm;
                break;
            case Type::Bgtu:
                os << "bgtu " << rs1 << ", " << rd << ", " << imm;
                break;
            case Type::Bleu:
                os << "bleu " << rs1 << ", " << rd << ", " << imm;
                break;
            case Type::J:
                os << "j " << imm;
                break;
            case Type::Jr:
                os << "jr " << rs1;
                break;
            case Type::Ret:
                os << "ret";
                break;
            case Type::Tail:
                os << "tail " << imm;
                break;
            // case Type::Rdinstret:
            //     os << "rdinstret " << rd;
            //     break;
            // case Type::Rdinstreth:
            //     os << "rdinstreth " << rd;
            //     break;
            // case Type::Rdcycle:
            //     os << "rdcycle " << rd;
            //     break;
            // case Type::Rdcycleh:
            //     os << "rdcycleh " << rd;
            //     break;
            // case Type::Rdtime:
            //     os << "rdtime " << rd;
            //     break;
            // case Type::Rdtimeh:
            //     os << "rdtimeh " << rd;
            //     break;
            case Type::Lla:
                os << "lla " << rd << ", " << imm;
                break;
            case Type::La:
                os << "la " << rd << ", " << imm;
                break;
            case Type::Fmv_s:
                os << "fmv.s " << rd << ", " << rs1;
                break;
            case Type::Fmv_x_w:
                os << "fmv.w.x " << rd << ", " << rs1;
                break;
            case Type::Fabs_s:
                os << "fabs.s " << rd << ", " << rs1;
                break;
            case Type::Fneg_s:
                os << "fneg.s " << rd << ", " << rs1;
                break;
            case Type::Fmv_d:
                os << "fmv.d " << rd << ", " << rs1;
                break;
            case Type::Fabs_d:
                os << "fabs.d " << rd << ", " << rs1;
                break;
            case Type::Fneg_d:
                os << "fneg.d " << rd << ", " << rs1;
                break;
            case Type::Li:
                os << "li " << rd << ", " << imm;
                break;
            case Type::Mv:
                os << "mv " << rd << ", " << rs1;
                break;
            case Type::Not:
                os << "not " << rd << ", " << rs1;
                break;
            case Type::Sext_w:
                os << "sext.w " << rd << ", " << rs1;
                break;
            case Type::Jal:
                os << "jal x1, " << imm;
                break;
            case Type::Jalr:
                os << "jalr x1, " << rs1 << ", 0";
                break;
            case Type::Call:
                os << "call " << imm;
                break;
            case Type::Fence:
                os << "fence iorw, iorw";
                break;
        }
    }

    static PseudoInstr new_reg_mv(const Register& rd, const Register& rs) {
        if (rd.is_gpr() && rs.is_gpr()) {
            return PseudoInstr(Type::Mv, rd, rs); // 生成 mv 指令
        } else if (rd.is_fpr() && rs.is_fpr()) {
            return PseudoInstr(Type::Fmv_s, rd, rs); // 生成 fmv.s 指令
        } else if (rd.is_fpr() && rs.is_gpr()) {
            return PseudoInstr(Type::Fmv_x_w, rd, rs); // 生成 fmv.x.w 指令
        } else {
            throw std::runtime_error("Can't move from register " + rs.get_name() + " to " + rd.get_name());
        }
    }

private:
    Type type;
    Register rd;
    Register rs1;
    Register rs2;
    Imm imm;
};

using BaseIntInstrVarint=std::variant<
        Shifts,
        Arithmetic,
        Logical,
        Compare,
        Branch,
        JumpAndLink,
        Environment,
        CSR,
        Loads,
        Stores,
        Trans,
        MulAdd,
        MinMax,
        PseudoInstr>;
class RV64Instr{
public:
    RV64Instr(BaseIntInstrVarint varint):varint(varint){    }
    void get_string(std::ostream& os) const{
        std::visit(Visitor{os},varint);
    }

private:
    BaseIntInstrVarint varint;

    // 访问器
    struct Visitor {
        std::ostream& os;
        // Shifts,
        void operator()(const Shifts& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // Arithmetic,
        void operator()(const Arithmetic& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // Logical,
        void operator()(const Logical& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // Compare,
        void operator()(const Compare& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // Branch,
        void operator()(const Branch& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // JumpAndLink,
        void operator()(const JumpAndLink& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // Environment,
        void operator()(const Environment& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // CSR,
        void operator()(const CSR& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // Loads,
        void operator()(const Loads& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // Stores,
        void operator()(const Stores& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // Trans,
        void operator()(const Trans& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // MulAdd,
        void operator()(const MulAdd& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // MinMax>;
        void operator()(const MinMax& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
        // PseudoInstr
        void operator()(const PseudoInstr& instr) const {
            instr.get_string(os);
            os<<std::endl;
        }
    };

};
// std::ostream& operator<<(std::ostream& os, const Shifts& instr) {
//     instr.get_string(os);
//     return os;
// }
}
