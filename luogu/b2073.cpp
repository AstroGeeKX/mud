// 题目描述
// 分数a/b化为小数后，小数点后第 n 位的数字是多少？

#include <bits/stdc++.h>

int main() {
    int a, b, n;
    std::cin >> a >> b >> n;
    
    if (a == b) {
        std::cout << 0;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        a %= b;
        a *= 10;
    }
    
    std::cout << a / b;
    return 0;
}