#include <iostream>
#include <variant>
#include <string>

// ���� variant ������
using MyVariant = std::variant<int, double, std::string>;

// ���������
struct Visitor {
    void operator()(int value) const {
        std::cout << "Processing int: " << value << std::endl;
    }

    void operator()(double value) const {
        std::cout << "Processing double: " << value << std::endl;
    }

    void operator()(const std::string& value) const {
        std::cout << "Processing string: " << value << std::endl;
    }
    
};
auto v=[] (auto&& a)  {
        std::cout << "Processing string: " << a << std::endl;
    };
int main() {
    MyVariant v1 = 42;
    MyVariant v2 = 3.14;
    MyVariant v3 = "Hello, variant!";

    // ʹ�� std::visit ���ö�Ӧ�ĺ���
    std::visit(Visitor{}, v1);  // ���: Processing int: 42
    std::visit(Visitor{}, v2);  // ���: Processing double: 3.14
    std::visit(Visitor{}, v3);  // ���: Processing string: Hello, variant!
    std::visit(v, v1);  // ���: Processing string: 1
    
    return 0;
}