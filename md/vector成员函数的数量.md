### vector<T>成员函数
- 这是mySTL项目的代码
一共声明：68个成员函数

### vector<T>::类外定义的成员函数
一共类外定义：26个成员函数

成员函数声明总数 - 类内定义的成员函数数量 = 类外定义的成员函数数量
也就是说，类内定义的数量 = 68 - 26 = 42个
比如begin和end，很多是重复的const定义，也就是十几二十来个类内定义

-------------------------------------------------------------------------

### 天工AI
 ### C++17 `std::vector` 函数列表

在C++17中，`std::vector` 是一个序列容器，它提供了动态数组的特性，包括自动内存管理和高效的随机访问能力。以下是 `std::vector` 在C++17中的所有成员函数的列表：

#### 构造函数
- `explicit vector()`：默认构造函数，创建一个空的 `vector`。
- `vector(size_type n, const T& value = T())`：构造函数，创建一个包含 `n` 个 `value` 的 `vector`。
- `template <class InputIterator> vector(InputIterator first, InputIterator last)`：构造函数，以 `[first, last)` 范围内的元素创建 `vector`。
- `vector(const vector& other)`：拷贝构造函数，创建一个与 `other` 内容相同的 `vector`。
- `vector(vector&& other) noexcept`：移动构造函数，使用 `other` 的资源创建一个新的 `vector`。
- `vector(std::initializer_list<T> init)`：列表初始化构造函数，用初始化列表中的值创建 `vector`。

#### 析构函数
- `~vector()`：析构函数，销毁 `vector` 并释放其内存。

#### 赋值操作
- `vector& operator=(const vector& other)`：拷贝赋值操作符，赋值一个与 `other` 内容相同的 `vector`。
- `vector& operator=(vector&& other) noexcept`：移动赋值操作符，移动赋值 `other` 的资源到当前 `vector`。
- `vector& operator=(std::initializer_list<T> init)`：用初始化列表中的值赋值当前 `vector`。

#### 迭代器
- `iterator begin()`：返回指向 `vector` 第一个元素的迭代器。
- `const_iterator begin() const`：返回指向 `vector` 第一个元素的常量迭代器。
- `iterator end()`：返回指向 `vector` 最后一个元素后一位置的迭代器。
- `const_iterator end() const`：返回指向 `vector` 最后一个元素后一位置的常量迭代器。
- `reverse_iterator rbegin()`：返回指向 `vector` 最后一个元素的逆向迭代器。
- `const_reverse_iterator rbegin() const`：返回指向 `vector` 最后一个元素的常量逆向迭代器。
- `reverse_iterator rend()`：返回指向 `vector` 第一个元素前一位置的逆向迭代器。
- `const_reverse_iterator rend() const`：返回指向 `vector` 第一个元素前一位置的常量逆向迭代器。

#### 容量
- `bool empty() const`：检查 `vector` 是否为空。
- `size_type size() const`：返回 `vector` 中元素的数量。
- `size_type max_size() const`：返回 `vector` 可以容纳的最大元素数量。
- `void reserve(size_type new_cap)`：请求 `vector` 将其容量扩充至至少能容纳 `new_cap` 个元素。
- `size_type capacity() const`：返回当前 `vector` 所分配的容量。
- `void shrink_to_fit()`：减少 `vector` 的容量，使其与当前大小匹配。

#### 元素访问
- `reference operator[](size_type pos)`：访问指定位置的元素。
- `const_reference operator[](size_type pos) const`：访问指定位置的常量元素。
- `reference at(size_type pos)`：访问指定位置的元素，并进行边界检查。
- `const_reference at(size_type pos) const`：访问指定位置的常量元素，并进行边界检查。
- `reference front()`：访问 `vector` 第一个元素。
- `const_reference front() const`：访问 `vector` 第一个常量元素。
- `reference back()`：访问 `vector` 最后一个元素。
- `const_reference back() const`：访问 `vector` 最后一个常量元素。
- `T* data() noexcept`：返回指向 `vector` 中第一个元素的指针。
- `const T* data() const noexcept`：返回指向 `vector` 中第一个元素的常量指针。

#### 修改器
- `void clear() noexcept`：清除所有元素。
- `iterator insert(const_iterator pos, const T& value)`：在 `pos` 位置前插入 `value`。
- `iterator insert(const_iterator pos, T&& value)`：在 `pos` 位置前插入移动的 `value`。
- `template <class InputIterator> iterator insert(const_iterator pos, InputIterator first, InputIterator last)`：在 `pos` 位置前插入 `[first, last)` 范围内的元素。
- `iterator insert(const_iterator pos, std::initializer_list<T> ilist)`：在 `pos` 位置前插入初始化列表中的元素。
- `iterator erase(const_iterator pos)`：移除 `pos` 位置的元素。
- `iterator erase(const_iterator first, const_iterator last)`：移除 `[first, last)` 范围内的元素。
- `void push_back(const T& value)`：在容器末尾添加 `value`。
- `void push_back(T&& value)`：在容器末尾添加移动的 `value`。
- `void pop_back()`：移除容器末尾的元素。
- `void resize(size_type count)`：改变 `vector` 中元素的数量为 `count`。
- `void resize(size_type count, const T& value)`：改变 `vector` 中元素的数量为 `count`，若新元素数量增加，则用 `value` 填充。
- `void swap(vector& other) noexcept`：交换两个 `vector` 的内容。

#### 分配器
- `allocator_type get_allocator() const noexcept`：返回用于构造容器的分配器。

以上列出的是 `std::vector` 在C++17中的所有成员函数。这些函数提供了对动态数组的全面控制，包括构造、赋值、迭代、容量管理、元素访问和修改等.