// P5726 【深基4.习9】打分

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    size_t n; // 评委数量
    double marks[1000] = {0};
    double sum = 0, score = 0;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> marks[i];
    }
    // 下面去掉一个最小值和一个最大值
    int max = 0;
    int min = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (marks[i] < marks[min])
            min = i;
        if (marks[i] > marks[max])
            max = i;
    }
    marks[min] = 0;
    marks[max] = 0;

    for (size_t i = 0; i < n; i++)
    {
        sum += marks[i];
    }
    score = sum / (n - 2);
    printf("%.2f\n", score);
    return 0;
}