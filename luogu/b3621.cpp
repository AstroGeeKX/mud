// B3621 枚举元组
// 本题是求A(n, k)的排列
// 没有思路

#include <iostream>

using namespace std;

void fun(int n, int k) {
    if (--k >= 1) {  // push: 5 4 3 2 1
        fun(n, k);
    }
    // for (int i = 0; i < k; i++) {
    //     cnt = 0;
    //     for (int j = i; ; j++, cnt++) {
    //         if (cnt > n) break;
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
    cout << k + 1 << endl;
    if (--k >= 1) {
        fun(n, k);
    }
}

int main() {
    int n, k;
    int cnt = 0;
    cin >> n >> k;
    // for (int i = 0; i < k; i++) {
    //     cnt = 0;
    //     for (int j = i; ; j++, cnt++) {
    //         if (cnt > n) break;
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
    fun(n, k);
    return 0;
}
