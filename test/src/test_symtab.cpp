#include "symtab.h"
int main() {
    using namespace KTC;
    SymTab symtab;
    symtab.add_symbol(Symbol(0, "x"));
    symtab.add_symbol(Symbol(1, "y", 3));
    symtab.add_symbol(Symbol(2, "z"));

    auto sym = symtab.get_symbol(SymIdx(1, "y", 3));
    if (sym) {
        std::cout << "Found symbol: " << sym<< "\n";
    } else {
        std::cout << "Symbol not found.\n";
    }

    return 0;
}
