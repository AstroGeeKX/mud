// P1603 斯诺登的密码

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int WORDS_NUM = 27;

// 字典打表obamaDic和obamaNum一一对应
char obamaDic[WORDS_NUM][12] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                                "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                                "nineteen", "twenty", "a", "both", "another", "first", "second", "third"};

int obamaNum[WORDS_NUM] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 0,
                           21, 44, 69, 96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1, 4, 9};

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    char tempStr[64] = {0};
    int a[6] = {0};

    // 题目会输入6个单词，自行判断是否符合转换数字
    int aIndex = 0;
    for (size_t i = 0; i < 6; i++)
    {
        scanf("%s", tempStr); // 数组名是首元素地址，不用加&
        // 判断输入的字符串是否对应字典
        for (int j = 0; j < WORDS_NUM; ++j)
        {
            if (strcmp(obamaDic[j], tempStr) == 0)
            {
                a[aIndex] = obamaNum[j]; // j是字典下标 i是密码下标
                aIndex++;
                break;
            }
        }
    }

    // 如果aIndex等于0，说明输入的单词没有有效转换成数字密码的
    if (aIndex == 0)
    {
        cout << "0";
        return 0;
    }

    qsort(a, aIndex, sizeof(int), compare);

    /*这道题目格式是个巨大的坑
    格式一：密码数字前导0不需要输出，需要抹去 首个数字抹去0，后面的数字就不是首个数字了
    格式二：首个数字不足二位数，不需要补0在后面
    格式三：除了首个数字，不足二位数，需要补0在后面

    格式一和格式二很容易混淆，谁能想到间谍会用这样劣质的方式加密呢
    */
    bool flag = 0;
    for (int i = 0; i < aIndex; i++)
    {
        if (flag) // 不是第一位
        {
            printf("%.2d", a[i]); // 限制格式输出
        }
        else
        {
            if (a[i]) // 前导0不输出
            {
                printf("%d", a[i]); // 第一个数字%d输出 后面的输出全部是上面的语句了 看flag的关系
                flag = 1;
            }
        }
    }

    return 0;
}