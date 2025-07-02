// B3882 [信息与未来 2015] 求回文数
// 不就是求回文数，直接用取余的方法逐个数求出来

#include <iostream>

using namespace std;

// 颠倒数字序列，对比是否和原数相等
// 先思考基本逻辑，再处理边界问题

bool fun(int num_) {
    int num1 = num_;  // 原数
    int num2 = 0;     // 反转后的数
    int bit = 1;      // 最高位数

    // 求出原数是几位数，得到bit是10的n次方
    while (num_ /= 10) {  // 先判断，就是少一次循环
        bit *= 10;
    }
    num_ = num1;  // 之前的循环修改了num_，现在恢复

    // 逐个数字扭转
    while (num_) {  // num_是几位数，就执行几次循环，这样化简思维，十分有用
        num2 += bit * (num_ % 10);
        bit /= 10;
        num_ /= 10;
    }

    // 反转数字等于原数，说明是回文数
    if (num1 == num2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, ans = 0;
    cin >> n;

    for (int i = 1; i < n; i++) {
        if (fun(i)) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}
