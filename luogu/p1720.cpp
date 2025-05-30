// P1720 月落乌啼算钱（斐波那契数列）

#define SOLUTION_1

#ifdef SOLUTION_1
/*
*本题解是用不知道什么方法，应该叫做递推
*但是很直观地用前两位数相加得到下一位数，从0、1、1开始递增，
*能否把这个数列换成更直观的一个变量呢
*/
#include <cstdio>
#include <iostream>

int main() {
    long long f[50] = {0, 1};
    long long n;
    std::cin >> n;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];  // 斐波那契数列，下一位的计算是前两位和
    }

    // printf("%lld.00", f[n]);  //输出，保留两位小数，需要使用%lld才能输出long long类型的整数
    std::cout << f[n] << ".00" << std::endl;

    return 0;
}
#endif  /* SOLUTION_1 */
