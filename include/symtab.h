#pragma  once
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <optional>
#include <mutex>
#include <sstream>
#include <algorithm>

#include "register.h"
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
class TypeDiscriminants {
    public:
        enum Type {
            I32,
            F32,
            I1,
            Void,
            Label,
            Ref,
            Ptr64,
            Array,
            Fn,
            Unknown
        };
    
    private:
        Type type_;
    
    public:
        TypeDiscriminants(Type type = Unknown) : type_(type) {}
    
        // 根据字符串返回类型
        static TypeDiscriminants new_from_const_str(const std::string& symbol_name) {
            if (symbol_name == "i32") {
                return TypeDiscriminants(I32);
            } else if (symbol_name == "f32") {
                return TypeDiscriminants(F32);
            } else if (symbol_name == "i1") {
                return TypeDiscriminants(I1);
            } else if (symbol_name == "void") {
                return TypeDiscriminants(Void);
            } else if (symbol_name == "label") {
                return TypeDiscriminants(Label);
            } else if (symbol_name == "ref") {
                return TypeDiscriminants(Ref);
            } else if (symbol_name == "ptr64") {
                return TypeDiscriminants(Ptr64);
            } else if (symbol_name == "array") {
                return TypeDiscriminants(Array);
            } else if (symbol_name == "fn") {
                return TypeDiscriminants(Fn);
            } else {
                return TypeDiscriminants(Unknown);
            }
        }
    
        // 获取类型
        Type get_type() const {
            return type_;
        }
    
        // 判断类型是否为 Unknown
        bool is_unknown() const {
            return type_ == Unknown;
        }
        bool operator!=(const TypeDiscriminants& other) const {
            return type_ != other.type_;
        }
    
        // 打印类型
        std::string to_string() const {
            switch (type_) {
                case I32: return "I32";
                case F32: return "F32";
                case I1: return "I1";
                case Void: return "Void";
                case Label: return "Label";
                case Ref: return "Ref";
                case Ptr64: return "Ptr64";
                case Array: return "Array";
                case Fn: return "Fn";
                default: return "Unknown";
            }
        }
    };
    
namespace KTC{
    struct SymIdx {
        uint32_t scope_node;
        std::string symbol_name;
        std::optional<uint32_t> index_ssa;
        SymIdx(){}
        SymIdx(uint32_t scope, std::string name, std::optional<uint32_t> ssa = std::nullopt)
            : scope_node(scope), symbol_name(std::move(name)), index_ssa(ssa) {}
    
        static std::shared_ptr<SymIdx> new_verbose(uint32_t scope, const std::string& name, std::optional<uint32_t> ssa) {
            return std::make_shared<SymIdx>(scope, name, ssa);
        }

        static std::shared_ptr<SymIdx> new_symidx(uint32_t scope, const std::string& name) {
            return std::make_shared<SymIdx>(scope, name, std::nullopt);
        }

        SymIdx to_src_symidx() const {
            SymIdx cloned = *this;      // 克隆当前对象
            cloned.index_ssa = {};      // 将 index_ssa 设置为默认值（这里是空）
            return cloned;              // 返回新的对象
        }

        bool is_global_ptr() const {
            return !symbol_name.empty() && symbol_name[0] == '*'; // 如果 symbol_name 非空并且以 '*' 开头，返回 true
        }
        bool is_literal() const {
            // 假设 TypeDiscriminants 是一个静态类，拥有一个方法 new_from_const_str 用来从字符串生成类型
            return TypeDiscriminants::new_from_const_str(symbol_name) != TypeDiscriminants::Unknown;
        }
        
        bool operator == (const SymIdx& other) const {
            return scope_node == other.scope_node && symbol_name == other.symbol_name && index_ssa == other.index_ssa;
        }
        bool operator!=(const SymIdx& other) const {
            return !(*this==other);
        }
    
        std::string to_string() const {//后续禁用此写法
            std::ostringstream oss;
            if (index_ssa) {
                oss << symbol_name << "_" << scope_node << "_" << *index_ssa;
            } else {
                oss << symbol_name << "_" << scope_node;
            }
            return oss.str();
        }

        friend std::ostream& operator <<(std::ostream& os ,const SymIdx& SymIdx);
    };

    std::ostream& operator <<(std::ostream& os ,const SymIdx& symidx){
        if (symidx.index_ssa) {
            os << symidx.symbol_name << "_" << symidx.scope_node << "_" << *symidx.index_ssa;
        } else {
            os << symidx.symbol_name << "_" << symidx.scope_node;
        }
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const std::optional<SymIdx>& opt_symidx) {
        if (opt_symidx) {  
            os << *opt_symidx;  // 使用 SymIdx 的 << 重载
        } else {
            os << " ";    
        }
        return os;
    }
    // template <>
    // struct std::hash<KTC::SymIdx> {
    //     std::size_t operator()(const SymIdx& s) const {
    //         std::size_t h1 = std::hash<std::string>{}(s.symbol_name);
    //         std::size_t h2 = std::hash<uint32_t>{}(s.scope_node);
            
    //         // 使用位运算组合哈希值
    //         return h1 ^ (h2 << 1);
    //     }
    // };
    struct SymIdxHash {
        std::size_t operator()(const SymIdx& s) const {
            return std::hash<std::string>{}(s.symbol_name) ^ std::hash<uint32_t>{}(s.scope_node);
        }
    };

    class Symbol {
        public:
            std::unordered_map<Value, Type> fields; // 符号字段
            std::shared_ptr<KTC::SymIdx> rc_symidx; // 共享的 SymIdx
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
            bool get_is_global() const{
                //需要，但是不知具体逻辑
                return true;
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
        os << "}" << "}";
        
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
    class SymTab {

        std::unordered_map<SymIdx, Symbol,SymIdxHash> map;
        std::string text;
        //mutable std::mutex mutex_; // 线程安全

    public:
  
        std::shared_ptr<SymIdx> add_symbol(Symbol sym) {
            //std::lock_guard<std::mutex> lock(mutex_);
            const auto& idx = sym.rc_symidx;
            if (map.find(*idx) != map.end()) {
                throw std::runtime_error("Duplicate symbol: " + idx->to_string());
            }
            map.emplace(*idx, std::move(sym));
            return idx;
        }

        // 查找符号
        const Symbol& get(const SymIdx& key) const {
            //std::lock_guard<std::mutex> lock(mutex_);
            auto it = map.find(key);
            if (it == map.end()) {
                throw std::runtime_error("Symbol not found: " + key.to_string());
            }
            return it->second;
        }
        Symbol& get(const SymIdx& key)  {
            //std::lock_guard<std::mutex> lock(mutex_);
            auto it = map.find(key);
            if (it == map.end()) {
                throw std::runtime_error("Symbol not found: " + key.to_string());
            }
            return it->second;
        }

        bool has_symbol(const SymIdx& key) const {
            //std::lock_guard<std::mutex> lock(mutex_);
            return map.find(key) != map.end();
        }

        void remove_symbol(const SymIdx& key) {
            //std::lock_guard<std::mutex> lock(mutex_);
            map.erase(key);
        }

        // 实现Rust的delegate功能
        auto begin() { return map.begin(); }
        auto end() { return map.end(); }
        auto size() const { return map.size(); }
    };
}



