// B3971 [语言月赛 202405] 闰年
// 本题题目有问题，只需要关注符合真闰年的条件即可

#include <iostream>

int main() {
    int y;
    bool ok = false;
    std::cin >> y;
    // y 是 4 的倍数，等价于 y 对 4 取余为 0，其余同理
    if (y % 4 == 0 && y % 100 != 0)
        ok = true;
    else if (y % 400 == 0 && y % 3200 != 0)
        ok = true;
    else if (y % 172800 == 0)
        ok = true;

    std::cout << (ok == true ? "Yes" : "No");

    return 0;
}
