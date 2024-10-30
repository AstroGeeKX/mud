// P5724 【深基4.习5】求极差 / 最大跨度值

#include <iostream>

using namespace std;

int maxf(int *a, size_t n)
{
    int max = a[0];
    for (size_t i = 0; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    return max;
}

int minf(int *a, size_t n)
{
    int min = a[0];
    for (size_t i = 0; i < n; i++)
    {
        if (min > a[i])
            min = a[i];
    }
    return min;
}

int main()
{
    int n;
    int max, min;
    int a[1000] = {0};
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    max = maxf(a, n);
    min = minf(a, n);
    cout << max - min << endl;    
    return 0;
}