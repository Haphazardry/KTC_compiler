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
#include "symbol.h"

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

        bool operator==(const SymIdx& other) const {
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
    struct SymIdxHash {
        std::size_t operator()(const SymIdx& s) const {
            return std::hash<std::string>{}(s.symbol_name) ^ std::hash<uint32_t>{}(s.scope_node);
        }
    };

    class SymTab {
        using MapType = std::unordered_map<SymIdx, Symbol, SymIdxHash>;
        
        MapType map;
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
        Symbol& get(const SymIdx& key) {
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


