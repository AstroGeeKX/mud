对于一个新手写 CMake 项目，以下是一个简单的、结构清晰的最佳实践示例。CMake 是用于构建和管理项目的工具，它通常用于 C++ 项目的构建配置中。假设你的项目是一个 C++ 项目，目录结构如下：

```
/your_project
    ├── CMakeLists.txt  # 顶层 CMake 配置文件
    ├── src
    │   ├── main.cpp
    │   └── other.cpp
    └── include
        ├── other.h
        └── myheader.h
```

### 1. 顶层 `CMakeLists.txt` 文件

这是最基本的 `CMakeLists.txt` 配置文件，适用于新手项目。

```cmake
# 设置最低 CMake 版本
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(MyProject VERSION 1.0 LANGUAGES CXX)

# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定源文件目录
set(SOURCE_FILES
    src/main.cpp
    src/other.cpp
)

# 包含头文件目录
include_directories(include)

# 创建可执行文件
add_executable(MyProject ${SOURCE_FILES})

# 如果有需要链接的库，可以在这里指定
# target_link_libraries(MyProject some_library)
```

### 2. 解释各部分：

- **`cmake_minimum_required(VERSION 3.10)`**: 定义最低支持的 CMake 版本。CMake 会根据这个版本来确保语法和特性兼容。
- **`project(MyProject VERSION 1.0 LANGUAGES CXX)`**: 定义项目名称、版本以及使用的语言（C++）。
- **`set(CMAKE_CXX_STANDARD 17)`**: 指定使用的 C++ 标准，这里使用 C++17。
- **`set(SOURCE_FILES ...)`**: 定义源文件路径，将项目的 C++ 文件列出。
- **`include_directories(include)`**: 指定头文件目录，`include` 目录包含了项目的头文件。
- **`add_executable(MyProject ${SOURCE_FILES})`**: 创建一个可执行文件，并将源文件与之链接。
- **`target_link_libraries(...)`**: 如果需要链接其他库，可以在这里进行设置。

### 3. 可能的扩展：

如果你将项目扩展为多个子模块（例如使用 `src` 和 `lib` 目录），你可能需要修改或扩展 CMake 配置。例如：

#### 3.1. 添加子目录：

如果项目包含子模块，可以使用 `add_subdirectory` 来处理子项目：

```cmake
add_subdirectory(src)
add_subdirectory(lib)
```

#### 3.2. 更复杂的文件组织：

如果你的项目组织复杂，可以使用 `aux_source_directory` 来自动获取源文件。

```cmake
aux_source_directory(src SOURCE_FILES)
add_executable(MyProject ${SOURCE_FILES})
```

### 4. 结构化 CMake 文件：

为了更好地组织项目，可以将不同的 CMake 配置拆分到多个文件中。比如：

#### 4.1. `src/CMakeLists.txt`

```cmake
# 这个 CMakeLists.txt 处理 src 目录下的文件

set(SOURCE_FILES
    main.cpp
    other.cpp
)

add_executable(MyProject ${SOURCE_FILES})
```

#### 4.2. 顶层 `CMakeLists.txt`

```cmake
# 顶层 CMake 文件包含 src 目录
cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加 src 子目录
add_subdirectory(src)

# 包含头文件目录
include_directories(include)
```

### 5. 最佳实践总结

- **CMake 最低版本要求**：总是确保 `cmake_minimum_required` 是合适的版本，以便支持你需要的所有 CMake 特性。
- **项目结构清晰**：保持源文件和头文件的分离，可以在 `src` 和 `include` 目录中组织代码。
- **头文件包含**：通过 `include_directories()` 将头文件路径添加到编译器的搜索路径中。
- **命名一致性**：保持文件和目标名称一致，避免混乱。

这样，你的 CMake 配置文件既简单又符合最佳实践，适合新手学习如何管理项目构建。