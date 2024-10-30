// P5723 【深基4.例13】质数口袋

#include <iostream>

using namespace std;

// 来自天工
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main()
{
    int l, count = 0, sum = 0;
    cin >> l;
    for (int i = 2; i < l; i++)
    {
        if (i % 2 == 0 && i != 2) // 不是2的偶数排除，以免调用函数浪费时间
            continue;
        if (isPrime(i))
        {
            if (sum + i > l)
                break;
            sum += i;
            count++;
            cout << i << endl;
        }
    }
    cout << count << endl;
    return 0;
}