#include <iostream>
#include <vector>
#include <cstddef>
#include <cassert>
// #include <cstdlib> // for std::aligned_alloc (C++17)

// Slab
template<typename T>
class Slab {
public:
    // 默认分配16个T类型对象的空间
    static const int page_size = 16;

    Slab() : slab_size_(sizeof(T) * page_size) {
        // 检查对象大小是否合法（必须是 1, 2, 4, 8 字节之一）
        // assert(object_size_ == 1 || object_size_ == 2 || object_size_ == 4 || object_size_ == 8);
        // 检查 Slab 大小是否合法（必须大于 0 且是对象大小的倍数）
        // assert(slab_size_ > 0 && slab_size_ % object_size_ == 0);
    }

    // 析构函数，释放所有分配的 Slab
    ~Slab() {
        for (auto slab : slabs_) {
            std::free(slab); // 使用 std::free 释放内存
        }
    }

    // 分配一个对象
    T* allocate() {
        if (free_list_.empty()) {
            allocate_slab(); // 如果没有空闲对象，分配一个新的 Slab
        }

        void* object = free_list_.back(); // 从空闲列表中获取一个对象
        free_list_.pop_back(); // 从空闲列表中移除该对象
        return static_cast<T*>(object);
    }

    // 释放一个对象
    void deallocate(void* object) {
        free_list_.push_back(object); // 将对象放回空闲列表
    }

private:
    // 分配一个新的 Slab
    void allocate_slab() {
        std::cout << "Allocating new slab page" << std::endl;
        // 使用 std::aligned_alloc 分配对齐的内存
        // 对齐要求为对象大小和 alignof(std::max_align_t) 的最大值
        size_t alignment = std::max(sizeof(T), alignof(T));
        void* slab = std::aligned_alloc(alignment, sizeof(T) * page_size);

        if (!slab) {
            throw std::bad_alloc(); // 如果分配失败，抛出异常
        }

        slabs_.push_back(slab); // 将新分配的 Slab 加入 Slab 列表

        // 将 Slab 划分为多个对象，加入空闲列表
        for (size_t i = 0; i < slab_size_; i += sizeof(T)) {
            free_list_.push_back(static_cast<char*>(slab) + i);
        }
    }

    size_t slab_size_;            // Slab 大小
    std::vector<void*> slabs_;    // 所有分配的 Slab
    std::vector<void*> free_list_; // 空闲对象列表
};

int main() {
    // 测试 Slab 分配器
    Slab<int> allocator; // 对象大小为 8 字节，Slab 大小为 64 字节

    // 分配两个对象
    int* p1 = static_cast<int*>(allocator.allocate());
    // int* p1 = allocator.allocate();
    *p1 = 42;
    std::cout << "Allocated p1: " << *p1 << " at address: " << p1 << std::endl;

    // 使用reinterpret_cast将分配的内存解释为double类型
    double* p2 = reinterpret_cast<double*>(allocator.allocate());
    *p2 = 3.14;
    std::cout << "Allocated p2: " << *p2 << " at address: " << p2 << std::endl;

    // 释放对象
    allocator.deallocate(p1);
    allocator.deallocate(p2);

    // 再次分配对象
    int* p3 = static_cast<int*>(allocator.allocate());
    *p3 = 100;
    std::cout << "Allocated p3: " << *p3 << " at address: " << p3 << std::endl;

    // 释放对象
    allocator.deallocate(p3);

    return 0;
}