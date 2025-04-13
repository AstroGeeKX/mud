好的，以下通过两个具体的例子来说明CMake查找库时头文件路径和库文件路径的情况：

### Boost库
假设Boost库安装在`/usr/local`目录下，其文件结构如下：
- `/usr/local/include/boost`：Boost库的头文件路径，包含所有Boost模块的头文件。
- `/usr/local/lib`：Boost库的库文件路径，包含编译好的`.a`或`.so`文件，例如`libboost_system.a`、`libboost_filesystem.so`等。

在CMake中，可以通过以下`CMakeLists.txt`文件来查找和使用Boost库：
```cmake
cmake_minimum_required(VERSION 3.15)
project(BoostExample)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)

# 查找Boost库，指定需要的组件
find_package(Boost 1.66.0 COMPONENTS system filesystem REQUIRED)

# 输出 Boost 的相关信息
message("Boost version: ${Boost_VERSION}")
message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message("Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
message("Boost_LIBRARIES: ${Boost_LIBRARIES}")

# 包含Boost头文件目录
include_directories(${Boost_INCLUDE_DIRS})

# 创建可执行文件
add_executable(BoostExample main.cpp)

# 链接Boost库
target_link_libraries(BoostExample ${Boost_LIBRARIES})
```
运行CMake后，`Boost_INCLUDE_DIRS`会指向`/usr/local/include`，`Boost_LIBRARY_DIRS`会指向`/usr/local/lib`，而`Boost_LIBRARIES`则包含了所需的Boost库文件路径，例如`/usr/local/lib/libboost_system.a`和`/usr/local/lib/libboost_filesystem.so`。

### OpenCV库
假设OpenCV库安装在`/usr/lib/x86_64-linux-gnu`目录下，其文件结构如下：
- `/usr/include/opencv4`：OpenCV库的头文件路径，包含所有OpenCV模块的头文件。
- `/usr/lib/x86_64-linux-gnu`：OpenCV库的库文件路径，包含编译好的`.a`或`.so`文件，例如`libopencv_core.so`、`libopencv_imgproc.so`等。

在CMake中，可以通过以下`CMakeLists.txt`文件来查找和使用OpenCV库：
```cmake
cmake_minimum_required(VERSION 3.13)
project(OpenCVExample)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 查找OpenCV库
find_package(OpenCV REQUIRED)

# 输出 OpenCV 的相关信息
message("OpenCV version: ${OpenCV_VERSION}")
message("OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
message("OpenCV_LIBRARIES: ${OpenCV_LIBRARIES}")

# 包含OpenCV头文件目录
include_directories(${OpenCV_INCLUDE_DIRS})

# 创建可执行文件
add_executable(OpenCVExample main.cpp)

# 链接OpenCV库
target_link_libraries(OpenCVExample ${OpenCV_LIBRARIES})
```
运行CMake后，`OpenCV_INCLUDE_DIRS`会指向`/usr/include/opencv4`，而`OpenCV_LIBRARIES`则包含了所需的OpenCV库文件路径，例如`/usr/lib/x86_64-linux-gnu/libopencv_core.so`和`/usr/lib/x86_64-linux-gnu/libopencv_imgproc.so`。

通过这两个例子可以看出，CMake查找库时，头文件路径和库文件路径是分开查找的，最终通过变量的形式提供给项目使用。
