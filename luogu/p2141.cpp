#include <iostream>

using namespace std;

int main()
{
    int array[100] = {0}; // 最大数字100 所以100足以
    int fgExist[20000] = {0}; // 最大两数和19999数字当下标补足20000
    int ans = 0; // 题目答案
    int count; // 题目输出多少个数
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> array[i];
        fgExist[ array[i] ] = 1; // 输入的数字标记 增一
    }
    
    // 这是相当暴力浪费数组的算法
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            int tempAdd = array[i] + array[j]; // 两数和
            if (fgExist[tempAdd] != 0)
                fgExist[tempAdd] += 1; // 不存在，就不加，防止其他数字随意加造成不符合题意
        }
    }

    for (int i = 0; i < 20000; i++)
    {
        if (fgExist[i] >= 2)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}