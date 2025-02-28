#pragma once 
#include <iostream>
#include <string>
namespace KTC{
    // Temp 寄存器：t0 到 t6，一共7个
    constexpr int NUM_TEMP   = 7;    
    // Saved 寄存器：s0 到 s11，一共12个
    constexpr int NUM_SAVED  = 12;   
    // Arg 寄存器：a0 到 a7，一共8个
    constexpr int NUM_ARG    = 8;  
    
    // FArg 寄存器：fa0 到 fa7，一共8个
    constexpr int NUM_FARG   = 8;   
    // FSaved 寄存器：f0 到 f9 (10个) 加上 f18 到 f31 (14个) 一共24个
    constexpr int NUM_FSAVED = 24;
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
            //空寄存器初始化
            Register():type(Type::Zero){}
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
                if (idx < 0 || idx >= 24) throw std::runtime_error("Invalid float saved register index");
                return Register(Type::FSaved, idx);
            }
            static Register new_sp() {
                return Register(Type::SP);
            }
        
            static Register new_ra() {
                return Register(Type::RA);
            }
        
        
            static Register new_gp() {
                return Register(Type::GP);
            }
        
            bool is_fpr() const {
                return type == Type::FArg || type == Type::FSaved;
            }
        
            bool is_gpr() const {
                return !is_fpr();
            }
        
            std::string get_name() const {
                switch (type) {
                    case Type::Zero:
                        return "zero";
                    case Type::RA:
                        return "ra";
                    case Type::SP:
                        return "sp";
                    case Type::GP:
                        return "gp";
                    case Type::Temp:
                        return "t" + std::to_string(reg_idx);
                    case Type::Saved:
                        return "s" + std::to_string(reg_idx);
                    case Type::Arg:
                        return "a" + std::to_string(reg_idx);
                    case Type::FArg:
                        return "fa" + std::to_string(reg_idx);
                    case Type::FSaved:
                        return "f" + std::to_string(reg_idx);
                    default:
                        throw std::runtime_error("Unknown register type");
                    }
            }
            friend std::ostream& operator<<(std::ostream& os, const Register& reg){
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
            };
            friend struct std::hash<Register>;
            // 重载 operator==
            bool operator==(const Register& other) const {
                return type == other.type && reg_idx == other.reg_idx;
            }
        private:
            Type type;
            int reg_idx;
        };
        
}