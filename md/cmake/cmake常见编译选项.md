在CMake的最佳实践中，有一些编译选项是经常需要指定的，而有些则有默认值。以下是一些常见的编译选项及其默认值：

### 常见编译选项

1. **`CMAKE_CXX_STANDARD`**：指定C++标准。默认情况下，CMake不会指定C++标准，这可能会导致编译器使用默认的C++标准，通常是C++98或C++11，具体取决于编译器版本。
2. **`CMAKE_BUILD_TYPE`**：指定构建类型，如Debug、Release、RelWithDebInfo和MinSizeRel。默认情况下，CMake不会指定构建类型，这可能会导致编译器使用默认的构建类型，通常是Debug或Release，具体取决于编译器和系统设置。
3. **`CMAKE_CXX_FLAGS`**：指定C++编译器的编译选项。默认情况下，CMake会根据编译器和系统设置来选择编译选项，通常包括一些基本的优化和警告选项。
4. **`CMAKE_C_FLAGS`**：指定C编译器的编译选项。默认情况下，CMake会根据编译器和系统设置来选择编译选项，通常包括一些基本的优化和警告选项。
5. **`CMAKE_EXE_LINKER_FLAGS`**：指定链接器的链接选项。默认情况下，CMake会根据编译器和系统设置来选择链接选项，通常包括一些基本的优化和警告选项。
6. **`CMAKE_SHARED_LINKER_FLAGS`**：指定共享库链接器的链接选项。默认情况下，CMake会根据编译器和系统设置来选择链接选项，通常包括一些基本的优化和警告选项。
7. **`CMAKE_MODULE_LINKER_FLAGS`**：指定模块链接器的链接选项。默认情况下，CMake会根据编译器和系统设置来选择链接选项，通常包括一些基本的优化和警告选项。

### 示例

以下是一些示例，展示了如何在CMake中指定这些编译选项：

```cmake
# 设置C++标准为C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置构建类型为Release
set(CMAKE_BUILD_TYPE Release)

# 添加编译选项，如启用所有警告和将警告视为错误
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror)
endif()

# 添加编译定义，如定义DEBUG宏
add_definitions(-DDEBUG)

# 设置可执行文件、库文件和静态库文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 查找并链接线程库
find_package(Threads REQUIRED)
target_link_libraries(my_project PRIVATE Threads::Threads)
```

这些示例展示了如何根据项目的需求来定制编译选项，以确保代码的质量和性能。在实际项目中，您可能需要根据具体情况调整这些选项。