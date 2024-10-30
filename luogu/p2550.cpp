// P2550 [AHOI2001] 彩票摇奖

#include <iostream>
#include <vector>

using namespace std;

int n; // 彩票张数
const int count = 7; // 号码个数

int inPut(vector<vector<int>> &dataCon)
{
    for (size_t i = 0; i < n; i++)
    {
        dataCon[i].resize(count); // 每一个容器对象都resize为7个大小
    }

    for (size_t i = 0; i < dataCon.size(); i++) // 这层循环为n次，用户控制台输入的n
    {
        for (int &element : dataCon[i]) // 这层循环固定次数为 count 7次
        {
            cin >> element;
        }
    }
    return 1;
}

// 返回值是中了几个号码
int isWin(const vector<int> &containers, int results[])
{
    int whatAward = 0;
    for (size_t i = 0; i < count; i++) // 7个数字分别遍历
    {
        for (const int &num : containers)
        {
            if (num == results[i])
                whatAward += 1;
        }
    }
    return whatAward;
}

int main()
{

    int awards[7] = {0}; // 各等级中奖记录 倒着排列
    int results[7] = {0}; // 彩票中奖结果
    vector<vector<int>> dataContainer; // 用这个方法就可以做到动态创建多个容器对象
    cin >> n; // 输入彩票张数
    dataContainer.resize(n); // 重新规划容器的数量 也就是彩票的数量
    
    // 输入中奖结果
    for (auto &ele : results)
    {
        cin >> ele;        
    }
    // 输入中买的各个彩票
    inPut(dataContainer); // 输入各份彩票的号码

    // 判断彩票中奖 中了几个号码，就在数组awards对应索引上自增1
    for (size_t i = 0; i < n; i++)
    {
        int whataward = isWin(dataContainer[i], results); // 返回值是中的号码个数
        if (whataward)
            awards[whataward - 1]++;
    }

    // 倒着打印数组 就是循序的中奖情况
    for (int i = count - 1; i >= 0; i--) // 切记，这里i不可用size_t类型，因为没有-1
    {
        cout << awards[i] << " ";
    }
    
    return 0;
}