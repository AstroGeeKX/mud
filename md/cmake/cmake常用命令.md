 ### CMake常用命令

以下是一些CMake中常用的命令，按照使用频率排序：
<参数> [属性]

1. `cmake_minimum_required(VERSION <VERSION_NUMBER>)`：设置所需的CMake最小版本。
2. `project(<PROJECT_NAME>)`：设置项目名称，并可指定支持的语言。
3. `add_executable(<EXECUTABLE_NAME> <SOURCE_FILES...>)`：创建可执行文件。
4. `add_library(<LIBRARY_NAME> <TYPE> <SOURCE_FILES...>)`：创建库，`<TYPE>`可以是`SHARED`、`STATIC`或`MODULE`。
5. `target_link_libraries(<TARGET> <ITEM1> [...])`：为目标链接库。
6. `include_directories(<DIR>)`：添加包含目录到编译器的搜索路径。
7. `link_directories(<DIR>)`：添加链接目录到链接器的搜索路径。
8. `set(<VARIABLE> <VALUE> [CACHE <TYPE> <DOCSTRING> [FORCE]])`：设置变量值。
9. `if(<CONDITION>) ... endif()`：条件语句块。
10. `foreach(<ITERATOR> <LIST>) ... endforeach()`：遍历列表。
11. `add_subdirectory(<DIR>)`：添加子目录并执行其`CMakeLists.txt`。
12. `target_include_directories(<TARGET> <INTERFACE|PUBLIC|PRIVATE> <INCLUDE_DIRS...>)`：为目标添加包含目录。
13. `set_target_properties(<TARGET> PROPERTIES <PROPERTY_NAME>=<VALUE> [...])`：设置目标属性。
14. `message(<MESSAGE_SEVERITY> "<MESSAGE>")`：显示消息。
15. `find_package(<PACKAGE_NAME> <CONFIG> [REQUIRED] [...])`：查找并加载外部项目或库。

### CMake常用内置变量

以下是一些CMake中常用的内置变量：

1. `PROJECT_SOURCE_DIR`：项目源代码目录。
2. `PROJECT_BINARY_DIR`：项目构建输出目录。
3. `CMAKE_CURRENT_SOURCE_DIR`：当前处理的`CMakeLists.txt`所在的源代码目录。
4. `CMAKE_CURRENT_BINARY_DIR`：当前处理的`CMakeLists.txt`的构建目录。
5. `CMAKE_CURRENT_LIST_FILE`：当前`CMakeLists.txt`文件的完整路径。
6. `CMAKE_CURRENT_LIST_LINE`：当前`CMakeLists.txt`中调用变量的行号。
7. `CMAKE_BINARY_DIR`：项目实际的构建路径。
8. `CMAKE_SOURCE_DIR`：顶层`CMakeLists.txt`所在的源代码目录路径。
9. `CMAKE_CURRENT_LIST_DIR`：当前正在处理的CMake文件所在的路径。
10. `CMAKE_COMMAND`：CMake命令的路径。
11. `CMAKE_MAKE_PROGRAM`：生成的构建系统中使用的make命令的路径（例如make, ninja）。

以上命令和变量是根据搜索结果中的信息整理得出的，并考虑了时效性和相关性.

### Cmake常用编译选项

1. **`CMAKE_CXX_STANDARD`**：指定C++标准。
2. **`CMAKE_BUILD_TYPE`**：指定构建类型，如Debug、Release、RelWithDebInfo和MinSizeRel。
3. **`CMAKE_CXX_FLAGS`**：指定C++编译器的编译选项。
4. **`CMAKE_C_FLAGS`**：指定C编译器的编译选项。
5. **`CMAKE_EXE_LINKER_FLAGS`**：指定链接器的链接选项。
6. **`CMAKE_SHARED_LINKER_FLAGS`**：指定共享库链接器的链接选项。
7. **`CMAKE_MODULE_LINKER_FLAGS`**：指定模块链接器的链接选项。