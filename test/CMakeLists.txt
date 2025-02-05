# 指定 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(KTC_test)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置默认构建类型为 Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# 指定头文件目录
include_directories("../include")  # 或者 target_include_directories(ktc_test PRIVATE ../include)

# 查找所有 .cpp 源文件
#file(GLOB SRC_FILES "*.cpp")  # 这里的路径可以根据项目结构调整，如 src/*.cpp

# 生成可执行文件
add_executable(ktc_test "./src/test_asm_struct.cpp")

# 设定 include 目录（如果 include 仅用于 ktc_test，可以用 target_include_directories）
target_include_directories(ktc_test PRIVATE "../include")
