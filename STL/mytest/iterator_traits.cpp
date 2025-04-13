#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};
    
    // 获取 vector 的迭代器类型
    typedef std::iterator_traits<decltype(vec.begin())>::iterator_category
        Category;

    // 判断迭代器类型
    if (std::is_same<Category, std::random_access_iterator_tag>::value) {
        std::cout << "vector has random access iterators." << std::endl;
    }

    return 0;
}
