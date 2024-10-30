// P1423 小玉在游泳

#include <iostream>

using namespace std;

int main()
{
    double s, sum = 0, push = 2.0;
    int steps = 0;
    cin >> s;
    while (sum < s)
    {
        sum += push;
        push *= 0.98;
        steps += 1;
    }
    cout << steps << endl;
    return 0;
}