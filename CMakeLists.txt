#cmake最低版本（CMakeList.txt 必填）
cmake_minimum_required(VERSION 3.10)
#项目名（CMakeList.txt 必填）
project(KTC)
#CPP标准（CMakeList.txt 选填）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 设置默认debug模式
set(CMAKE_BUILD_TYPE "Debug")
set(GENERATED  lib/antlr_parser/generated)
# 添加头文件目录
include_directories(
    include
    ${GENERATED}
    third_party/antlr4-runtime
)
# 添加库搜索路径
link_directories(third_party/lib)
#编译test
add_subdirectory(test)
# 添加生成的文件的源代码
#添加可执行文件（CMakeList.txt 必选）
file(GLOB_RECURSE lib_FILES "lib/*.cpp") #GLOB参数表示使用通配符匹配文件 存到指定变量中
file(GLOB_RECURSE LIB_SRC "third_party/lib/*.cpp" )
#file(GLOB_RECURSE GENRATED "lib/antlr_parser/generated/*.cpp")
set(SOURCES
    ${lib_FILES}
    ${LIB_SRC}

)
# 创建可执行文件
add_executable(KTC ${SOURCES})
target_include_directories(KTC PRIVATE "./include" third_party/antlr4-runtime)
target_link_libraries(KTC antlr4-runtime.a) 
#target_include_directories(main PRIVATE "./include")

