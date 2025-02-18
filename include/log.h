#pragma once
#include <iostream>
#include <cassert>
// 在 Release 模式下不做任何操作
#ifdef NDEBUG
    #define LOG(msg) 
    #define ASSERT_LOG(cond, msg)
#else
    #define LOG(msg) std::cout << msg << std::endl; 
    #define ASSERT_LOG(cond, msg) \
    if (!(cond)) { \
        LOG("Assertion failed: " << msg << " (File: " << __FILE__ << ", Line: " << __LINE__ << ")"); \
        assert(cond); \
    }
#endif
