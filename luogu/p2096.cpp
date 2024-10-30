// B2096 直方图

#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    int max = 0; 

    cin >> count;
    int* arrayInput = new int[count]; // 用new分配空间，比malloc好用
    for (size_t i = 0; i < count; i++)
    {
        cin >> arrayInput[i];
        // 查找最大值
        if (max < arrayInput[i])
        {
            max = arrayInput[i];
        }
    }
    
    max += 1;    //  max加1是因为还要统计0的个数

    int* stats = new int[max]{0}; // {0}这样初始化为零
    for (size_t i = 0; i < count; i++)
    {
        stats[ arrayInput[i] ] += 1; // 常规数组是什么数字，就在统计数组上自增1
    }
    
    for (size_t i = 0; i < max; i++)
    {
        cout << stats[i] << endl;
    }
    
    return 0;
}