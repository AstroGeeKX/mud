// B3651 [语言月赛202208] 数组调整

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    long long ans = 0;
    cin >> n >> k;
    vector<int> array(n);
    // 输入数据
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    // 第k个数字转为相反数
    array[k - 1] *= -1;
    // 计算求和
    for (int i = 0; i < n; i++) {
        ans += array[i];
    }
    cout << ans;
    return 0;
}
