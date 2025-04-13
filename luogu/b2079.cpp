// 题目描述
// 利用公式 e=1+1/1!+1/2!+1/3!+⋯+1/n!，求 e 的值，要求保留小数点后 10 位。

#include <bits/stdc++.h>

int main() {
    int n;
    double e = 1.0, b = 1.0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        b *= i;
        e += 1 / b;
    }
    printf("%0.10lf", e);
    return 0;
}
