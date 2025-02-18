#pragma  once
#include <memory>
#include <unordered_map>
#include "symtab.h"
#include "rv64_instr.h"
//待实现的value、type
struct Value {
    int val;
    Value() : val(0) {} 
    Value(int x) : val(x) {}
    bool operator ==(const Value& other) const {
        return val == other.val;
    }
    friend std::ostream& operator <<(std::ostream& os, const Value& value);
};
std::ostream& operator <<(std::ostream& os, const Value& value){
    return os << value.val;
}

// 为 Value 类型特化 std::hash
namespace std {
    template <>
    struct hash<Value> {
        size_t operator()(const Value& v) const {
            size_t h = hash<int>()(v.val);  // 使用 int 的哈希函数
            //cout << "Hash value for " << v.val << ": " << h << endl;  // 输出哈希值
            return h;
        }
    };
}

struct Type {
    std::string data;
    Type() : data("") {}  
    Type(std::string d) : data(d) {}
    friend std::ostream& operator<<(std::ostream& os ,const Type& type);
};
std::ostream& operator<<(std::ostream& os ,const Type& type ){
    return os<<type.data; 
}
namespace KTC{
    // 符号（类似 Rust 的 Symbol）
    class Symbol {
        public:
            std::unordered_map<Value, Type> fields; // 符号字段
            std::shared_ptr<SymIdx> rc_symidx; // 共享的 SymIdx
            std::optional<Register> cur_reg;
            Symbol(uint32_t scope, const std::string& name, std::optional<uint32_t> ssa = std::nullopt)
                : rc_symidx(SymIdx::new_verbose(scope, name, ssa)) {}
        
            static Symbol new_verbose(uint32_t scope, const std::string& name, std::optional<uint32_t> ssa) {
                return Symbol(scope, name, ssa);
            }
        
            static Symbol new_symbol(uint32_t scope, const std::string& name) {
                return Symbol(scope, name);
            }
        
            static Symbol new_from_symidx(const std::shared_ptr<SymIdx>& symidx) {
                return Symbol(symidx->scope_node, symidx->symbol_name, symidx->index_ssa);
            }
            void add_cur_reg(Register& reg) {
                cur_reg=reg;
            }
            friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol);
        
        };
    
    // 重载<<运算符
    std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
        os << "{"
        << "SymIdx(" << symbol.rc_symidx->scope_node << ", " << symbol.rc_symidx->symbol_name << "), "
        << "fields: {";
        
        for (const auto& field : symbol.fields) {
            os << field.first << ": " << field.second << ", ";
        }
        os << "}";
        
        return os;
    }
    // 重载<<运算符，用于输出std::optional<Symbol>
    std::ostream& operator<<(std::ostream& os, const std::optional<Symbol>& opt_symbol) {
        if (opt_symbol) {
            os << *opt_symbol;  // 如果有值，解引用并输出
        } else {
            os << "nullopt";  // 如果没有值，输出 "nullopt"
        }
        return os;
    }
}