// P1217 [USACO1.5] 回文质数 Prime Palindromes

#include <iostream>

using namespace std;

// 判断回文数
bool isPalindrome(int num)
{
    if (num < 0)
        return false; // 负数不是回文数

    // 用于存储反转后的数字
    int reversedNum = 0;
    int originalNum = num;

    // 反转数字
    while (num != 0)
    {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    // 比较原数字和反转后的数字
    return originalNum == reversedNum;
}

// 来自天工 判断素数
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (int i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (isPalindrome(i) && isPrime(i)) // 直接在条件语句中合并判断
        {
            cout << i << endl; // 确保每个结果后都有换行符
        }
    }
    return 0;
}