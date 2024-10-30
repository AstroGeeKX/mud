// P2669 [NOIP2015 普及组] 金币

#include <iostream>

using namespace std;

int main()
{
    // day是剩余天数 per是当天的金币数 sum是合计
    int day, per = 1, sum = 0;
    cin >> day;

    while(day)
    {
        if (day < per)
        {
            sum += per * day;
            break;
        } // 天数不足，per * 剩余天数，而不是per * per
        sum += per * per;
        day -= per;
        per += 1;
    }
    cout << sum << endl;
    return 0;
}