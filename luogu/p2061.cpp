//2061
#include <iostream>

using namespace std;

int main()
{
    int count, count1 = 0, count5 = 0, count10 = 0;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int t;
        cin >> t;
        count1 += ((1 == t) ? 1 : 0);
        count5 += ((5 == t) ? 1 : 0);
        count10 += ((10 == t) ? 1 : 0);
    }
    cout << count1 << endl << count5 << endl << count10 << endl;
    return 0;
}