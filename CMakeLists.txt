#cmake最低版本（CMakeList.txt 必填）
cmake_minimum_required(VERSION 3.10)
#项目名（CMakeList.txt 必填）
project(KTC)
#CPP标准（CMakeList.txt 选填）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 设置默认debug模式
set(CMAKE_BUILD_TYPE "Debug")
#包含头文件目录（CMakeList.txt 必选）
include_directories(include)
#添加可执行文件（CMakeList.txt 必选）
file(GLOB SRC_FILES "src/*.cpp") #GLOB参数表示使用通配符匹配文件 存到指定变量中
file(GLOB TEST_FILES "test/*.cpp")
add_executable(test TEST_FILES)
add_executable(main main.cpp ${SRC_FILES})
target_include_directories(main PRIVATE "./include")
target_include_directories(test PRIVATE "./include")

