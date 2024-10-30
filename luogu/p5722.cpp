// P5722 【深基4.例11】数列求和

#include <iostream>

using namespace std;

int main()
{
    unsigned short n; // 100个数以内
    int sum = 0;
    cin >> n;
    while (n)
    {
        sum += n--;
    }
    cout << sum << endl;
    return 0;
}