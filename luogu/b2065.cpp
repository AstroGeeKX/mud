// B2065 鸡尾酒疗法

// 你这个年纪怎么会担心浮点数的精度问题？

#include <iostream>

using namespace std;

int main() {
    int n;
    double a, b, x;  // 总病例 有疗效病例 疗效
    double c, d, y;  // 总病例 有疗效病例 疗效
    cin >> n;
    cin >> a >> b;
    x = b / a;  // 鸡尾酒的疗效

    for (int i = 0; i < n - 1; i++) {
        cin >> c >> d;
        y = d / c;      // 疗效
        if (y - x > 0.05) {
            cout << "better\n";
        } else if (x - y > 0.05) {
            cout << "worse\n";
        } else {
            cout << "same\n";
        }
    }

    return 0;
}
