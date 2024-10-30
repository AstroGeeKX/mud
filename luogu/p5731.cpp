#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int main()
{
    int n, k = 1, x = 1, y = 0;
    cin >> n;
    // 这些逻辑很可以 元素值为0表示没有填充
    // y > 1 (但不是x > 1）是防止最外一层左边界的问题 情况是左下角a[n - 1][-1]的时候 y下标-1是未定义行为
    // 循环条件前面y < n等用于最外一层的情况，其余循环起作用的是!a[][]等的条件
    while (k <= n * n)
    {
        while (y < n && !a[x][y + 1])
            a[x][++y] = k++;
        while (x < n && !a[x + 1][y])
            a[++x][y] = k++;
        while (y > 1 && !a[x][y - 1])
            a[x][--y] = k++;
        while (x > 1 && !a[x - 1][y]) // 这里有坑x > 1正常情况不起作用，但是删掉会使1*1的矩阵报错
            a[--x][y] = k++;
    }
    // 打印数组
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%3d", a[i][j]); // %3d对齐数字
        printf("\n");
    }
    return 0;
}