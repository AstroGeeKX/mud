// B3654 [语言月赛202208] 影子字符串

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<string> s1;
    string input;
    while (1)
    {
        cin >> input;
        if (input == "0")
        {
            break;
        }
        if (find(s1.begin(), s1.end(), input) == s1.end())
        {
            s1.push_back(input);
        }
    }
    //printSet(s1);
    // for (vector<string>::iterator it = s1.begin(); it != s1.end(); it++)
    // {
    //     cout << *it;
    // }

    for (const auto& str : s1)
    {
        cout << str;
    }
    cout << endl;
    
    // 定义字符串对象
    // 遍历所有字符串对象 对比是否有重复（相等）
    // 输出字符串
    return 0;
}