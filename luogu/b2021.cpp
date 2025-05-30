// B2021 输出保留 3 位小数的浮点数

#define SOLUTION_2

#ifdef SOLUTION_1
#include <cstdio>

int main() {
    float x = 0;
    scanf("%f", &x);
    printf("%.3f", x);
    return 0;
}
#endif  /* SOLUTION_1 */


#ifdef SOLUTION_2
#include <bits/stdc++.h>
using namespace std;
int main() {
    float a;
    cin >> a;
    cout << fixed << setprecision(3) << a;
    return 0;
}

#endif  /* SOLUTION_2 */