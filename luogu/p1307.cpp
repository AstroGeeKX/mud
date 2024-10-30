//P1307 [NOIP2011 普及组] 数字反转

/* 
    题目描述给定一个整数N，请将该数各个位上数字反转得到一个新数。新数也应满足整数
    的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见
    样例 2）。
*/

#include <iostream>

using namespace std;

// 数字反转函数
int reverse(int num)
{
    int reversedNum = 0;
    // 反转数字
    while (num != 0)
    {
        int digit = num % 10; // 正负号可以保证
        reversedNum = reversedNum * 10 + digit; // 0*10 + 0可以保证结尾结尾0不会有问题
        num /= 10;
    }
    return reversedNum;
}

int main()
{
    int n;
    cin >> n;
    n = reverse(n);
    cout << n;
    return 0;
}