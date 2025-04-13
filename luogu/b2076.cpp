// #B2076 球弹跳高度的计算
// 一球从某一高度落下（整数，单位米），每次落地后反跳回原来高度的一半，再落下。
// 编程计算气球在第 $10$ 次落地时，共经过多少米？第 $10$ 次反弹多高？

#include <bits/stdc++.h>

int main() {
    double total_height = 0;
    double current_height = 0;

    std::cin >> current_height;
    for (int i = 0; i < 10; ++i) {
        current_height /= 2;
        total_height += current_height * 3;
    }

    total_height -= current_height;

    std::cout << total_height << std::endl << current_height << std::endl;
    return 0;
}