# 定义项目名称和最低版本要求
cmake_minimum_required(VERSION 3.10)
project(test LANGUAGE CXX)

# 指定生成器为MinGW Makefiles
#set(CMAKE_GENERATOR "MinGW Makefiles")
# 设置构建类型为Release
#set(CMAKE_BUILD_TYPE Release)
# 设置编译器为GCC
#set(CMAKE_CXX_COMPILER "g++")
# 编译选项
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------------------------------------------------

# 重新定义目标二进制可执行文件的存放位置
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 那这个是什么？
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 指定所有源文件 还可以用aux_ ...
# aux_source_directory(. myFiles)
file(GLOB myFiles CMAKE_CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# 添加生成可执行文件
add_executable(hello ${myFiles})
