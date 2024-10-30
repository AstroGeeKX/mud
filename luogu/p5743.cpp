// P5743 【深基7.习8】猴子吃桃

#include <iostream>

using namespace std;

int main()
{
    int n, ans = 1; // ans = 1是最后一天剩的一个
    cin >> n;
    for (size_t i = 0; i < n - 1; i++) // n - 1天代表最后一天没有吃
    {
        ans += 1; // 这两个式子倒序就不成立了 先加后乘
        ans *= 2; // 很简单地就模拟出来了
    }
    cout << ans << endl;
    return 0;
}