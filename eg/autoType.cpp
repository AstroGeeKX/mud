#include <iostream>
#include <utility>
#include <vector>

template <typename T>
std::string typeName()
{
    return typeid(T).name();
}

int main() {
    // 使用 make_pair 创建 pair 对象
    // using PairType = std::pair<int, int>;
    // auto p = std::make_pair(10, 20);
    // std::vector<int> v;
    // std::vector<int>::iterator it;
    // v.push_back(1);
    // v.push_back(2);
    // auto p = it;
    // 使用 decltype 获取 p 的类型
    // using PairType = std::pair<int, int>;

    // 输出 pair 对象的元素
    // std::cout << "First element: " << p.first << std::endl;
    // std::cout << "Second element: " << p.second << std::endl;

    // 打印类型（此处使用类型名称，实际运行时不会输出类型）
    std::cout << "Type of p: " << typeid("abc").name() << std::endl;

    return 0;
}