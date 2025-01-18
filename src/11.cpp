#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <cmath>

// 定义一些基础类型
using RcSymIdx = std::shared_ptr<int>; // 假设SymIdx是一个int类型的共享指针
using SymIdx = int;

// 定义Imm类
class Imm {
public:
    enum class Type {
        GlobalLabel,
        LocalLabel,
        Literal
    };

    Imm(Type type, RcSymIdx symidx) : type(type), symidx(symidx) {}

    static Imm new_local_label(RcSymIdx label) {
        return Imm(Type::LocalLabel, label);
    }

    static Imm new_global_label(RcSymIdx label) {
        return Imm(Type::GlobalLabel, label);
    }

    static Imm new_literal(RcSymIdx symidx) {
        return Imm(Type::Literal, symidx);
    }

    static Imm new_literal_isize(int li) {
        return Imm(Type::Literal, std::make_shared<int>(li));
    }

    static Imm from_offset(int offset) {
        if (offset < -2000 || offset > 2000) {
            throw std::runtime_error("you can't use an offset from");
        }
        return Imm(Type::Literal, std::make_shared<int>(offset));
    }

    friend std::ostream& operator<<(std::ostream& os, const Imm& imm);

private:
    Type type;
    RcSymIdx symidx;
};

std::ostream& operator<<(std::ostream& os, const Imm& imm) {
    switch (imm.type) {
        case Imm::Type::GlobalLabel:
            os << "GlobalLabel(" << *imm.symidx << ")";
            break;
        case Imm::Type::LocalLabel:
            os << "LocalLabel(" << *imm.symidx << ")";
            break;
        case Imm::Type::Literal:
            os << "Literal(" << *imm.symidx << ")";
            break;
    }
    return os;
}

class Register {
public:
    enum class Type {
        Zero,
        RA,
        SP,
        GP,
        // ranging from t0 to t6
        Temp,
        // ranging from s0 to s11
        Saved,
        // ranging from a0 to a7
        Arg,
        // ranging from fa0 to fa7
        FArg,
        // ranfing from f0 to f9 and f18 to f31
        FSaved
    };

    Register(Type type, int reg_idx = 0) : type(type), reg_idx(reg_idx) {}

    static Register new_s0() {
        return Register(Type::Saved, 0);
    }

    static Register new_s(int idx) {
        if (idx < 1 || idx >= 12) throw std::runtime_error("Invalid saved register index");
        return Register(Type::Saved, idx);
    }

    static Register new_a(int idx) {
        if (idx < 0 || idx >= 8) throw std::runtime_error("Invalid argument register index");
        return Register(Type::Arg, idx);
    }

    static Register new_t(int idx) {
        if (idx < 0 || idx >= 7) throw std::runtime_error("Invalid temporary register index");
        return Register(Type::Temp, idx);
    }

    static Register new_fa(int idx) {
        if (idx < 0 || idx >= 8) throw std::runtime_error("Invalid float argument register index");
        return Register(Type::FArg, idx);
    }

    static Register new_fs(int idx) {
        if (idx < 0 || idx >= 16) throw std::runtime_error("Invalid float saved register index");
        return Register(Type::FSaved, idx);
    }

    bool is_fpr() const {
        return type == Type::FArg || type == Type::FSaved;
    }

    bool is_gpr() const {
        return !is_fpr();
    }

    friend std::ostream& operator<<(std::ostream& os, const Register& reg);

private:
    Type type;
    int reg_idx;
};

std::ostream& operator<<(std::ostream& os, const Register& reg) {
    switch (reg.type) {
        case Register::Type::Zero:
            os << "zero";
            break;
        case Register::Type::RA:
            os << "ra";
            break;
        case Register::Type::SP:
            os << "sp";
            break;
        case Register::Type::GP:
            os << "gp";
            break;
        case Register::Type::Temp:
            os << "t" << reg.reg_idx;
            break;
        case Register::Type::Saved:
            os << "s" << reg.reg_idx;
            break;
        case Register::Type::Arg:
            os << "a" << reg.reg_idx;
            break;
        case Register::Type::FArg:
            os << "fa" << reg.reg_idx;
            break;
        case Register::Type::FSaved:
            os << "f" << reg.reg_idx;
            break;
    }
    return os;
}

// 定义RV64Instr类
class RV64Instr {
public:
    virtual ~RV64Instr() = default;
    virtual void print(std::ostream& os) const = 0;
};

std::ostream& operator<<(std::ostream& os, const RV64Instr& instr) {
    instr.print(os);
    return os;
}

// 定义PseudoInstr类
class PseudoInstr : public RV64Instr {
public:
    enum class Type {
        Nop,
        Neg,
        Negw,
        Snez,
        Sltz,
        Sgtz,
        Seqz,
        Beqz,
        Bnez,
        Blez,
        Bgez,
        Bltz,
        Bgtz,
        Bgt,
        Ble,
        Bgtu,
        Bleu,
        J,
        Jr,
        Ret,
        Tail,
        Rdinstret,
        Rdinstreth,
        Rdcycle,
        Rdcycleh,
        Rdtime,
        Rdtimeh,
        Lla,
        La,
        Lb,
        Lh,
        Lw,
        Ld,
        Sb,
        Sh,
        Sw,
        Sd,
        Fmv_s,
        Fmv_w_x,
        Fabs_s,
        Fneg_s,
        Fmv_d,
        Fabs_d,
        Fneg_d,
        Li,
        Mv,
        Not,
        Sext_w,
        Jal,
        Jalr,
        Call,
        Fence
    };

    PseudoInstr(Type type, Register rd, Register rs, Imm imm = Imm::new_literal_isize(0))
        : type(type), rd(rd), rs(rs), imm(imm) {}

    void print(std::ostream& os) const override {
        switch (type) {
            case Type::Nop:
                os << "nop";
                break;
            case Type::Neg:
                os << "neg " << rd << ", " << rs;
                break;
            case Type::Negw:
                os << "negw " << rd << ", " << rs;
                break;
            case Type::Snez:
                os << "snez " << rd << ", " << rs;
                break;
            case Type::Sltz:
                os << "sltz " << rd << ", " << rs;
                break;
            case Type::Sgtz:
                os << "sgtz " << rd << ", " << rs;
                break;
            case Type::Seqz:
                os << "seqz " << rd << ", " << rs;
                break;
            case Type::Beqz:
                os << "beqz " << rs << ", " << imm;
                break;
            case Type::Bnez:
                os << "bnez " << rs << ", " << imm;
                break;
            case Type::Blez:
                os << "blez " << rs << ", " << imm;
                break;
            case Type::Bgez:
                os << "bgez " << rs << ", " << imm;
                break;
            case Type::Bltz:
                os << "bltz " << rs << ", " << imm;
                break;
            case Type::Bgtz:
                os << "bgtz " << rs << ", " << imm;
                break;
            case Type::Bgt:
                os << "bgt " << rs << ", " << rd << ", " << imm;
                break;
            case Type::Ble:
                os << "ble " << rs << ", " << rd << ", " << imm;
                break;
            case Type::Bgtu:
                os << "bgtu " << rs << ", " << rd << ", " << imm;
                break;
            case Type::Bleu:
                os << "bleu " << rs << ", " << rd << ", " << imm;
                break;
            case Type::J:
                os << "j " << imm;
                break;
            case Type::Jr:
                os << "jr " << rs;
                break;
            case Type::Ret:
                os << "ret";
                break;
            case Type::Tail:
                os << "tail " << imm;
                break;
            case Type::Rdinstret:
                os << "rdinstret " << rd;
                break;
            case Type::Rdinstreth:
                os << "rdinstreth " << rd;
                break;
            case Type::Rdcycle:
                os << "rdcycle " << rd;
                break;
            case Type::Rdcycleh:
                os << "rdcycleh " << rd;
                break;
            case Type::Rdtime:
                os << "rdtime " << rd;
                break;
            case Type::Rdtimeh:
                os << "rdtimeh " << rd;
                break;
            case Type::Lla:
                os << "lla " << rd << ", " << imm;
                break;
            case Type::La:
                os << "la " << rd << ", " << imm;
                break;
            case Type::Lb:
                os << "lb " << rd << ", " << imm;
                break;
            case Type::Lh:
                os << "lh " << rd << ", " << imm;
                break;
            case Type::Lw:
                os << "lw " << rd << ", " << imm;
                break;
            case Type::Ld:
                os << "ld " << rd << ", " << imm;
                break;
            case Type::Sb:
                os << "sb " << rd << ", " << imm << ", " << rs;
                break;
            case Type::Sh:
                os << "sh " << rd << ", " << imm << ", " << rs;
                break;
            case Type::Sw:
                os << "sw " << rd << ", " << imm << ", " << rs;
                break;
            case Type::Sd:
                os << "sd " << rd << ", " << imm << ", " << rs;
                break;
            case Type::Fmv_s:
                os << "fmv.s " << rd << ", " << rs;
                break;
            case Type::Fmv_w_x:
                os << "fmv.w.x " << rd << ", " << rs;
                break;
            case Type::Fabs_s:
                os << "fabs.s " << rd << ", " << rs;
                break;
            case Type::Fneg_s:
                os << "fneg.s " << rd << ", " << rs;
                break;
            case Type::Fmv_d:
                os << "fmv.d " << rd << ", " << rs;
                break;
            case Type::Fabs_d:
                os << "fabs.d " << rd << ", " << rs;
                break;
            case Type::Fneg_d:
                os << "fneg.d " << rd << ", " << rs;
                break;
            case Type::Li:
                os << "li " << rd << ", " << imm;
                break;
            case Type::Mv:
                os << "mv " << rd << ", " << rs;
                break;
            case Type::Not:
                os << "not " << rd << ", " << rs;
                break;
            case Type::Sext_w:
                os << "sext.w " << rd << ", " << rs;
                break;
            case Type::Jal:
                os << "jal x1, " << imm;
                break;
            case Type::Jalr:
                os << "jalr x1, " << rs << ", 0";
                break;
            case Type::Call:
                os << "call " << imm;
                break;
            case Type::Fence:
                os << "fence iorw, iorw";
                break;
        }
    }

private:
    Type type;
    Register rd;
    Register rs;
    Imm imm;
};

// 定义BaseIntInstr类
class BaseIntInstr : public RV64Instr {
public:
    enum class Type {
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
        MinMax
    };

    BaseIntInstr(Type type) : type(type) {}

    void print(std::ostream& os) const override {
        os << "BaseIntInstr(" << static_cast<int>(type) << ")";
    }

private:
    Type type;
};

// 定义Shifts类
class Shifts : public BaseIntInstr {
public:
    enum class Type {
        Sll,
        Sllw,
        Slli,
        Slliw,
        Srl,
        Srlw,
        Srli,
        Srliw,
        Sra,
        Sraw,
        Srai,
        Sraiw
    };

    Shifts(Type type, Register rd, Register rs1, Register rs2, Imm shamt = Imm::new_literal_isize(0))
        : BaseIntInstr(BaseIntInstr::Type::Shifts), type(type), rd(rd), rs1(rs1), rs2(rs2), shamt(shamt) {}

    void print(std::ostream& os) const override {
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

private:
    Type type;
    Register rd;
    Register rs1;
    Register rs2;
    Imm shamt;
};

// 其他指令类的定义类似，这里省略...

int main() {
    // 示例用法
    Register rd = Register::new_a(0);
    Register rs1 = Register::new_s(1);
    Register rs2 = Register::new_t(2);
    Imm imm = Imm::new_literal_isize(42);

    PseudoInstr instr(PseudoInstr::Type::Add, rd, rs1, imm);
    std::cout << instr << std::endl;

    return 0;
}