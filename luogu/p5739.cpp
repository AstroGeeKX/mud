// P5739 【深基7.例7】计算阶乘

#include <iostream>

using namespace std;

// 这是用递归计算阶乘
int function(int a)
{
    if (a == 0) // 如果计算0的阶乘 就是1
        return 1;
    return a * function(a - 1); // 计算a * (a - 1)
}

int main()
{
    int a = 0;
    cin >> a;
    cout << function(a);
    return 0;
}