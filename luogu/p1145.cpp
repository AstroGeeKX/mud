// P1145 约瑟夫

#include <iostream>

using namespace std;

int main()
{
    int k, m; // k是好人和坏人数 m是约瑟夫数
    cin >> k;
    m = k; // 优化步骤 因为小于k，第一个就能杀到好人
    bool stop = 0;
    while (!stop)
    {
        int badGuys = k;
        int index = 0; // 全文唯一一个下标
        for (int i = 0; i < k; i++)
        {
            index = (index + m - 1) % (2 * k - i); // -1 是因为下标比第n个少1
            if (index < k)
            {
                m++; // 好人排在前，如果杀到了好人，那么m不是正确答案，继续尝试下一个m数
                break; // 下一次循环 m++
            }
            badGuys -= 1; // 杀掉一个坏人，计数减1
        }
        
        // 程序到这有两种情况 1、坏人全部消灭，m值正确    2、刚刚杀到好人了，m不是正确值
        if (badGuys == 0)
        {
            stop = 1; // 坏人全部消灭，那么可以停止模拟了，m值已经找到了
        }
    }
    cout << m;
    return 0;
}
