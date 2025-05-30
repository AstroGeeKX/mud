#include <iostream>
#include <iomanip>

int main() {
    double price[10]{28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};  // 按顺序每本书的价格
    double totalPrice = 0;  // 总金额
    int bookCounts = 0;

    for (int i = 0; i < 10; i++) {
        std::cin >> bookCounts;
        totalPrice += price[i] * bookCounts;
    }

    std::cout << std::fixed << std::setprecision(1) << totalPrice << std::endl;

    return 0;
}
