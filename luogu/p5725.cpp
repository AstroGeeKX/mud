// P5725 【深基4.习8】求三角形
// TODO 5月10日
// 使用%02d使其不满足2位数的时候补0以足够2位数

#define SOLUTION_1
// #define TEST_1

#ifdef SOLUTION_1
#include <iostream>
#include <cstdio>

int main() {
    int n = 0;
    int m = 1;
    std::cin >> n;

    // 用最简单的for循环嵌套，不要过多考虑优化算法，防止解题思路中断
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%02d", m);
            m += 1;
        }
        printf("\n");
    }

    m = 1;
    printf("\n");

    for (int i = 0; i < n; i++) {
        // 空格
        for (int j = 0; j < 2 * (n - i - 1); j++) {
            printf(" ");
        }
        // 数字
        for (int k = 0; k < i + 1; k++) {
            printf("%02d", m);
            m += 1;
        }
        printf("\n");
    }

    return 0;
}
#endif  /* SOLUTION_1 */


#ifdef TEST_1
/*
 *偶然发现问题，在for循环条件中使用除法
 *结论是，除数会被优化为不等号对侧的乘法上
*/
#include <iostream>

int main() {
    int a = 2, b = 4;
    int ans = 0;

    for (int i = 0; i < 2; i++) {
        ans += 1;
    }
    std::cout << "i < 2,     ans is: " << ans << std::endl;

    ans = 0;
    for (int i = 0; i / 3 < 2; i++) {
        ans += 1;
    }
    std::cout << "i / 3 < 2, ans is: " << ans << std::endl;

    ans = 0;
    for (int i = 0; i < 2 * 3; i++) {
        ans += 1;
    }
    std::cout << "i < 2 * 3, ans is: " << ans << std::endl;

    return 0;
}
#endif  /* TEST_1 */
