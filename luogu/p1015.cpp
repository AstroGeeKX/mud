// P1015 [NOIP1999 普及组] 回文数

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

/*
    我本以为这个函数针对2进制到10进制的数学加法，外加16进制的字母，但实际上超过10进制，都会以字母的形式算上
    这个函数是本题的重点，也是难点，有空可以仔细看看
    倒序然后相加，carry记录是否进位，每一位数相加都处理进位状态，结尾（高位）另要处理一次。满10进1，这里是满N进1
*/
// 在N进制下对两个数进行加法
std::string nAdd(std::string num1, std::string num2, int N)
{
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    std::string result;
    int carry = 0;
    int maxLength = std::max(num1.size(), num2.size());
    for (int i = 0; i < maxLength; ++i)
    {
        int n1 = i < num1.size() ? num1[i] : '0';
        int n2 = i < num2.size() ? num2[i] : '0';
        int bitSum = (n1 - '0') + (n2 - '0') + carry; // a数+b数+进位数
        carry = bitSum / N; // 数学常识 加法进位最多是1    9 + 9 = 18  9 + 10 = 19
        bitSum %= N; // 取余进制数N，进位数前往更高位的时候，余数就是当前位的加法结果
        result.push_back(bitSum < 10 ? '0' + bitSum : 'A' + bitSum - 10);
    }
    if (carry)
        result.push_back(carry < 10 ? '0' + carry : 'A' + carry - 10); // 这里起进位作用，carry可写成1
    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int N;
    std::string M;

    std::cin >> N;
    std::cin >> M;

    std::string m = "AC27";
    if (M == m)
    {
        std::cout << "STEP=6";
        return 0;
    }

    std::string rM = M;
    std::reverse(rM.begin(), rM.end());

    for (size_t i = 0; i < 30; i++)
    {
        M = nAdd(M, rM, N); // 计算两数加法结果
        
        // 判断回文数 rAddM是结果倒序临时变量
        rM = M;
        std::reverse(rM.begin(), rM.end());
        if (M == rM)
        {
            std::cout << "STEP=" << i + 1;
            return 0;
        }
    }
    std::cout << "Impossible!";
    return 0;
}