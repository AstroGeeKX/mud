// P1888 三角函数

#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    
    // a b c从小到大排序
    if (a > b) std::swap(a, b);
    if (a > c) std::swap(a, c);
    if (b > c) std::swap(b, c);
    
    for (int i = c; i > 0; i--) {
        if (c % i == 0 && a % i == 0) {
            c /= i;
            a /= i;
        }
    }

    std::cout << a << '/' << c << std::endl;

    return 0;
}
