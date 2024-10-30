#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> uniqueNumbers; // 存储去重后的数字
    int count;
    int inputNum;
    cin >> count;

    for (int i = 0; i < count; ++i)
    {
        cin >> inputNum;
        auto ifFind = find(begin(uniqueNumbers), end(uniqueNumbers), inputNum);
        if (ifFind == uniqueNumbers.end()) // 找不到返回的是end迭代器
        { 
            // uniqueNumbers.insert(uniqueNumbers.end(), inputNum); // insert接受迭代器，或加end用重载函数
            uniqueNumbers.push_back(inputNum);
        }
    }

    for (auto &&i : uniqueNumbers)
    {
        cout << i << " ";
    }
    
    // 使用unordered_set输出是倒序的
    // unordered_set<int> numbers(100); // 预留100个空间
    // int count;
    // cin >> count;
    // int inp;
    // for (size_t i = 0; i < count; i++)
    // {
    //     cin >> inp;
    //     numbers.insert(inp);
    // }

    // for (auto &i : numbers)
    // {
    //     cout << i << " ";
    // }

    return 0;
}