// P1089 [NOIP 2004 提高组] 津津的储蓄计划

#define SOLUTION_1

#ifdef SOLUTION_1
/*
*这道题比较简单，题目废话巨长，其实就是简单的几个变量和循环的加减运算
*/
#include <iostream>

int main() {
    int cost = 0, current = 0, total = 0;
    for (int i = 0; i < 12; i++) {
        std::cin >> cost;
        current = current + 300 - cost;  // 月初拿到300就计算了这个月的开销
        if (current < 0) {
            std::cout << '-' << i + 1 << std::endl;
            return 0;
        }
        total += (current / 100) * 100;  // 存钱整百
        current = current % 100;  // 剩余的钱
    }
    std::cout << total * 1.2 + current;
    return 0;
}
#endif  /* SOLUTION_1 */
