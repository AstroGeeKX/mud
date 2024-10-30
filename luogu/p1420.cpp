// #include <iostream>
// #include <cstdio>
// //这是一个最长连号的程序
// using namespace std;
// int main()
// {
//     int n, count = 0;
//     char ch;
//     int temp = 0;
//     while (cin.get(ch)) {
//         char chh = ch;
//         if (ch - chh == 1) {
//             temp++;
//         } else {
//             if (temp > count)
//                 count = temp;
//             temp = 0;
//         }
//         chh = ch;
//     }
//     cout << count;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     int count = 0;
//     int temp = 0;
//     char prevChar = '\0'; // 用于存储前一个字符
//     char currentChar; // 用于存储当前字符

//     // 从标准输入读取字符，直到到达文件末尾
//     while (cin.get(currentChar)) {
//         // 如果当前字符是空格，跳过
//         if (currentChar == ' ') {
//             continue;
//         }

//         // 如果当前字符与前一个字符连续，则计数加一
//         if (currentChar == prevChar + 1) {
//             temp++;
//         } else {
//             // 否则更新最长连号的个数，并重置临时计数器
//             if (temp > count) {
//                 count = temp;
//             }
//             temp = 1; // 因为当前字符不是连号，所以临时计数器初始化为 1
//         }

//         // 更新前一个字符为当前字符
//         prevChar = currentChar;
//     }

//     // 在循环结束后，检查最后的连号个数是否大于之前记录的最大值
//     if (temp > count) {
//         count = temp;
//     }

//     // 输出最长连号的个数
//     cout << count << endl;

//     return 0;
// } 上面的是AI写的代码，看不懂是什么意思

// P1420 最长连号

#include <iostream>

using namespace std;

int main()
{
    int n; // 输入n个数字
    int k = 1, l = 1;
    int a[4000] = {0}; // 一共那么多个数字

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i + 1] - a[i] == 1) // 后一个数减前一个数等于1说明是连续的
            k += 1;
        else
            k = 1; // 如果不连续，那么重置为1

        if (k > l)
            l = k; // l是不会重置的，指最大连续的个数
    }

    cout << l << endl;
    return 0;
}
