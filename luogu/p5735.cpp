// P5735 【深基7.例1】距离函数 题解

#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

double distance(double x1, double x2, double y1, double y2)
{
    return sqrt( ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)) );
}
int main()
{
    double x1, x2, x3, y1, y2, y3, c;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    c = distance(x1, x2, y1, y2) + distance(x1, x3, y1, y3) + distance(x2, x3, y2, y3);
    printf("%.2f\n", c);
    return 0;
}