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

# 查找 test/src 目录中的所有 .cpp 文件
file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/test/src/*.cpp")

# 输出调试信息，确认查找到的文件
message(STATUS "Found source files: ${SRC_FILES}")

# 为每个 .cpp 文件生成一个单独的可执行文件
foreach(SRC_FILE ${SRC_FILES})
    message(STATUS "Creating executable for: ${SRC_FILE}")
    # 获取文件名（不带路径和扩展名）
    get_filename_component(EXEC_NAME ${SRC_FILE} NAME_WE)

    # 为每个 .cpp 文件生成一个单独的可执行文件
    add_executable(${EXEC_NAME} ${SRC_FILE})

    # 设置 include 目录
    target_include_directories(${EXEC_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")
endforeach()
