在这份 CMakeLists.txt 文件中，关于 **源文件编译** 的部分实际上主要集中在以下几个方面：

1. **CMake 语言设置和标准：**
   - 设置 CMake 最低版本为 3.10。
   - 设置使用 C++17 标准：
     ```cmake
     set(CMAKE_CXX_STANDARD 17)
     set(CMAKE_CXX_STANDARD_REQUIRED ON)
     ```
   - 使得生成的 `compile_commands.json` 文件包含源文件编译信息：
     ```cmake
     set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
     ```

2. **CMake 项目配置：**
   - 设定项目名 `Pine`，语言为 C 和 C++。
     ```cmake
     project(Pine
             VERSION 0.1
             DESCRIPTION "pine"
             LANGUAGES C CXX)
     ```

3. **编译选项：**
   - 配置编译器标志和选项：
     ```cmake
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -Wextra -std=c++17 -pthread")
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter -Wno-attributes") #TODO: remove
     set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls")
     set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -fPIC")
     set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fPIC")
     set(CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} -fPIC")
     ```
     - `-fPIC`：生成位置无关代码（Position-Independent Code），通常用于共享库。
     - `-Wall` 和 `-Wextra`：启用所有常见的警告。
     - `-std=c++17`：指定 C++17 标准。
     - `-pthread`：启用线程支持。
     - `-O0`：禁用优化，通常用于调试。
     - `-ggdb`：生成调试信息。
     - `-fsanitize=address`：启用 AddressSanitizer，用于检测内存错误。

4. **输出目录设置：**
   - 设置编译后生成文件的存放目录：
     ```cmake
     set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
     set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
     ```

5. **包含目录设置：**
   - 配置源文件和测试文件的头文件目录：
     ```cmake
     set(PINE_SRC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/include)
     set(PINE_TEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/test/include)
     include_directories(${PINE_SRC_INCLUDE_DIR} ${PINE_TEST_INCLUDE_DIR})
     ```

6. **子目录添加：**
   - 添加 `src` 和 `test` 子目录，其中通常包含源文件和测试文件：
     ```cmake
     add_subdirectory(src)
     add_subdirectory(test)
     ```

### 关键总结：
- **CMake 的主要编译选项**：
  - 你通过设置 `CMAKE_CXX_FLAGS`，控制了 C++ 编译器的选项，包括标准、警告、线程支持以及调试和优化设置。
  - `CMAKE_EXPORT_COMPILE_COMMANDS` 被设置为 `ON`，以生成 `compile_commands.json`，这是 CMake 编译过程中用于存储编译命令的 JSON 文件，通常供 IDE 或其他工具使用。
  - 编译后生成的文件（库、可执行文件）将被放置在 `lib` 和 `bin` 目录中。

- **源文件包含目录**：
  - 使用 `include_directories()` 添加了源文件和测试的头文件目录。

- **源文件组织**：
  - `add_subdirectory(src)` 表示将 `src` 目录中的 CMake 配置文件添加到构建过程中，通常这个目录包含源代码（`.cpp` 和 `.h` 文件）。
  - 同理，`add_subdirectory(test)` 添加了测试目录，通常这里面包含测试代码。

这些部分实际上是源文件编译的核心内容，其他如 clang-format、clang-tidy 和 cpplint 等工具选项都是额外的工具配置，用于格式检查和静态分析，不直接影响源文件的编译过程。如果你只关心源文件的编译，可以将这些工具相关的部分忽略