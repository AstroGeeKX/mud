// B4094 [CSP-X2021 山东] 成绩排名

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v(10000);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> q;
    
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        if (v[i] == q) {
            cout << i + 1 << endl;
            return 0;  // 输出结果，退出主函数
        }
    }

    return 0;
}
