// P5737 【深基7.例3】闰年展示

#include <iostream>

using namespace std;

int year(int a)
{
    if (a % 100 == 0)
    {
        if (a % 400 == 0)
            return a;
        else
            return 0;
    }
    else if (a % 4 == 0)
        return a;
    return 0;
}

int main()
{
    int l, r;
    int count = 0, array[1000] = {0};
    int temp;
    cin >> l >> r;
    for (size_t i = l; i <= r; i++)
    {
        temp = year(i);
        if (temp == 0)
            continue;
        array[count++] = temp;
    }
    cout << count << endl;
    for (size_t i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
    
    return 0;
}