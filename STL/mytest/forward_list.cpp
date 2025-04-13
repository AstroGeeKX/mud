#include <algorithm>
#include <iostream>
#include <forward_list>
#include <functional>

// 打印函数
void printforward_list(const std::forward_list<int>& L) {
    for (std::forward_list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 又一个打印函数
template <typename T>
void print(const T& fl) {
    for (auto x : fl) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

// 用于for_each()打印的lambda函数
auto print_fn = [](const int& n) { std::cout << n << ' '; };


// forward_list构造函数
void test01() {
    // 构造初始化
    std::forward_list<int> FL1{1, 2, 3, 4, 5};
    printforward_list(FL1);

    // (start, end)拷贝构造
    std::forward_list<int> FL2(FL1.begin(), FL1.end());
    printforward_list(FL2);

    // 拷贝构造
    std::forward_list<int> FL3(FL2);
    printforward_list(FL3);

    // (数量， 元素)初始化构造
    std::forward_list<int> FL4(10, 6);
    printforward_list(FL4);
}


// 测试遍历方式
void test02() {
    std::forward_list<int> FL1{1, 2, 3, 4, 5};
    print<>(FL1);
}


// push_front()前插 和 pop_front()前删
void test03() {
    std::forward_list<int> FL1{5, 6, 7};
    // 前插
    FL1.push_front(1);
    FL1.push_front(2);
    FL1.push_front(3);
    print(FL1);

    // forward_list容器的迭代器是单向迭代器，不支持随机访问
    // cout << FL1.push_back(114) << endl;  // 错误  不支持push_back()
    // cout << FL1.pop_back() << endl;   // 错误  不支持pop_back()
    // it = it + 1;  // 错误，不可以跳跃访问，只能是++这些
    std::cout << "first element: " << FL1.front() << std::endl;
    FL1.pop_front();
    std::cout << "pop_front(), now first element: " << FL1.front() << std::endl;
}


// 迭代器
void test04() {
    std::forward_list<int> FL1{5, 6, 7};
    print(FL1);

    // 迭代器 insert_after
    auto beginIt = FL1.begin();
    FL1.insert_after(beginIt, 114);
    print(FL1);

    // [5, 114, 6, 7]  beginIt是5的位置后插
    // [5, 114, 514, 6, 7]  beginIt++是114的位置后插
    beginIt++;
    FL1.insert_after(beginIt, 514);  // 迭代器没有失效，begin++还是头
    print(FL1);

    // 查找元素
    auto it = FL1.begin();  // 不要害怕使用外部变量，写代码要放开手脚
    for (auto x : FL1) {
        if (x == 6) {
            break;
        }
        it++;
    }
    FL1.insert_after(it, 666);
    print(FL1);
}


int main() {
    test04();
    return 0;
}