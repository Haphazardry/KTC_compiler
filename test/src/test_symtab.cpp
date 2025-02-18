#include "symtab.h"
int main() {
    using namespace KTC;
    SymTab symtab;
    symtab.add_symbol(Symbol(0, "x"));
    symtab.add_symbol(Symbol(1, "y", 3));
    symtab.add_symbol(Symbol(2, "z"));

    auto sym = symtab.get(SymIdx(1, "y", 3));
    std::cout << "Found symbol: " << sym<< "\n";

    return 0;
}
