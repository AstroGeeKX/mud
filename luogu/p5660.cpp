#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char ch[9] = {0};
    int count = 0;
    cin >> ch;
    for (int i = 0; i < 8; i++)
    {
        if (ch[i] == '1')
            count++;
    }
    cout << count;
    return 0;
}