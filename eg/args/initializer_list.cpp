#include <iostream>
#include <initializer_list>

void print_list(std::initializer_list<int> list) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "同类型可变参数示例输出：\n";
    print_list({1, 2, 3, 4, 5});
    // print_list(1, 2, 3, 4, 5);
    return 0;
}
