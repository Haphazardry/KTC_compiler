#include <iostream>
#include <variant>
#include <string>

// 定义 variant 的类型
using MyVariant = std::variant<int, double, std::string>;

// 定义访问器
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

    // 使用 std::visit 调用对应的函数
    std::visit(Visitor{}, v1);  // 输出: Processing int: 42
    std::visit(Visitor{}, v2);  // 输出: Processing double: 3.14
    std::visit(Visitor{}, v3);  // 输出: Processing string: Hello, variant!
    std::visit(v, v1);  // 输出: Processing string: 1
    
    return 0;
}