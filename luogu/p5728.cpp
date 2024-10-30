// P5728 【深基5.例5】旗鼓相当的对手

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    unsigned short array[1000][4] = {0}; // 数组前三列是各科分数 第四列是总分统计
    size_t count; // 同学个数
    size_t result = 0; // 多少组同学
    cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        cin >> array[i][0] >> array[i][1] >> array[i][2];
        array[i][3] = array[i][0] + array[i][1] + array[i][2];
    }
    // 下面只需要便利数组每一行，对比各科和总分差就可以了
    for (size_t i = 0; i < count - 1; i++)
    {
        for (size_t j = i + 1; j < count; j++)
        {
            if (
                
                abs(array[i][0] - array[j][0]) <= 5 &&
                abs(array[i][1] - array[j][1]) <= 5 &&
                abs(array[i][2] - array[j][2]) <= 5 &&
                abs(array[i][3] - array[j][3]) <= 10)
                result += 1;
        }
    }
    cout << result << endl;
    return 0;
}