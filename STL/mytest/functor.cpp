// #include <algorithm> // for std::sort
// #include <vector>

// int main() {
//     std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
//     std::sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
//     // v is now sorted in descending order
//     // 使用lambda表达式，这样就不需要完整定义一个仿函数类
// }

#include <iostream>
#include <algorithm>
#include <vector>

// 冒泡排序函数模板
template <typename Iterator, typename Compare>
void bubbleSort(Iterator begin, Iterator end, Compare comp)
{
    for (size_t i = 0; i < end - begin - 1; ++i)
    {
        for (size_t j = 0; j < end - begin - i - 1; ++j)
        {
            if (comp(*(begin + j + 1), *(begin + j))) // 第二个数比第一个数，或者是用!comp()
            {
                std::iter_swap(begin + j, begin + j + 1); // 两数比较规则不正确就交换数值
            }
        }
    }
}

// 使用自定义比较函数的示例
int main()
{
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    bubbleSort(vec.begin(), vec.end(), [](int a, int b)
               { return a > b; }); // 降序排序
    // vec 现在按照降序排序
    for (auto &&i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// sort使用谓词确定排序规则 内部具体实现
// 不要过多纠结算法实现，即使感觉频繁调用comp函数会对性能有很大考验，但至少从逻辑上实现一遍
