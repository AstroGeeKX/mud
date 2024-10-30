// P1075 [NOIP2012 普及组] 质因数分解

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (size_t i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << n / i << endl;
            return 0;
        }
    }
    return 0;
}