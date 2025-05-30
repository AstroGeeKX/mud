// B3888 [语言月赛 202311] 画图练习

#define SOLUTION_1

#ifdef SOLUTION_1
// TODO
#include <iostream>

// 简单的判断质数函数
bool check(int k) {  // 判断素数，0表示不是质数，1表示是质数
    if (k == 1) return 0;
    if (k == 2) return 1;
    for (int i = 2; i * i <= k; ++i)  // i * i是sqrt优化
        if (k % i == 0) return 0;  // 能除尽，说明不是素数
    return 1;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {  // i行
        int col = 1;
        for (int j = 0; j < (i+1) * (i+1); ) {  // i^2个字符  在这里处理(i+1)比在上面要方便
            int letter = i + j;  // i行就从第i个字母开始，j个就是第i个字母开始的第j个
            if (letter > 25) letter = letter % 26;  // 字母序号越界回环

            if (check(letter + 'A' + col)) {  // ASCII加列数是否是质数
                std::cout << char(letter + 'A');
                j++;  // 控制输出字母的循环范围
            } else {
                std::cout << ' ';  // 输出空格不定量，依照质数的条件
            }
            col++;  // 不论是空格还是字母，列数都会改变
        }
        std::cout << std::endl;
    }
    return 0;
}
#endif  /* SOLUTION_1 */
