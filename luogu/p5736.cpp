// p5736质数筛

#include <iostream>

using namespace std;

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
    int n, array[100] = {0};
    int temp, count = 0;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> temp;
        if (isPrime(temp))
        {
            array[count] = temp;
            count++;
        }
    }
    
    for (size_t i = 0; i < count; i++)
    {
        cout << array[i] << " ";
    }
    
    return 0;
}