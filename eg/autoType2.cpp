#include <iostream>
#include <utility>
#include <typeinfo>

template <typename T>
std::string typeName()
{
    return typeid(T).name();
}

int main() {
    // 使用 make_pair 创建 pair 对象
    auto p = std::make_pair(10, 20);

    // 使用 decltype 获取 p 的类型
    using PairType = decltype(p);

    // 输出 pair 对象的元素
    std::cout << "First element: " << p.first << std::endl;
    std::cout << "Second element: " << p.second << std::endl;

    // 打印类型
    std::cout << "Type of p: " << typeName<PairType>() << std::endl;

    return 0;
}