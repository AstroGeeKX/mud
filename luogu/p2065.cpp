// B2065 鸡尾酒疗法

// 你这个年纪怎么会担心浮点数的精度问题？

#include <iostream>

using namespace std;

int main()
{
    int n;
    double a, b, c;
    cin >> n;
    cin >> a >> b;
    c = b / a; // c是鸡尾酒的疗效
    
    for (int i = 0; i < n - 1; ++i)
    {
        double f, g;
        double _fg;
        cin >> f >> g; // f是总病例数 g是有效治疗数
        _fg = g / f;
        if (c - _fg > 0.05)
        {
            cout << "worse\n";
        } else if (c - _fg < -0.05)
        {
            cout << "better\n";
        } else
        {
            cout << "same\n";
        }
    }
    return 0;
}