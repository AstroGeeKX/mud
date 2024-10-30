// P1109 学生分组

// 学生总数sum 对比 nL <= sum <= nR就是有效的，否则无效
// 单组小于L的数量记负数 单组大于R的数量记正数 绝对值取最大
// 10合规，不计数，0    20不合规，大于15，计数 +5，绝对值最大是5
// 举例 10 和 18    18大于15 计数+3     所以移动3次
// 举例 9  和 18    9小于10计数 -1  18大于15 计数 +3 绝对值最大是3
// 无法完成的情况 就是第一行描述的

#include <iostream>

using namespace std;

int main()
{
    int n;
    int sum = 0;
    int array[50] = {0};
    int L, R;
    int less = 0, than = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        sum += array[i];
    }
    cin >> L >> R;

    // 首先判断是否能完成
    if (sum >= n * L && sum <= n * R)
    {
        // 能完成
    }
    else
    {
        cout << -1; // 不能完成
        return 0;
    }

    // 遍历每一个不合格情况，记录所有L界和R界不合规的总数 两者绝对值的最大值
    for (int i = 0; i < n; i++)
    {
        if (array[i] < L)
        {
            // less += array[i] - L; // 下面做了处理，不需要绝对值了
            less += L - array[i];
        }
        else if (array[i] > R)
        {
            than += array[i] - R;
        }
    }

    // 输出最大的那个数
    cout << (less > than ? less : than);
    return 0;
}