// B3655 [语言月赛202208] 天天爱跑步

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, ans = 0;
    int v1, v3, v7, v30, v120, v365;

    // 输入数据
    cin >> n;
    cin >> v1 >> v3 >> v7 >> v30 >> v120 >> v365;
    vector<int> day(n, 0);  // n个初始化为0

    for (int i = 0; i < n; i++) {
        cin >> day[i];
    }

    // 累加
    int current = 0;
    for (int i = 0; i < n; i++) {
        if (day[i] == 1) {
            current += 1;
        } else {
            current = 0;
            continue;
        }
        
        if (current >= 1 && current <= 2) {
            ans += v1;    
        }
        if (current >= 3 && current <= 6) {
            ans += v3;
        }
        if (current >= 7 && current <= 29) {
            ans += v7;
        }
        if (current >= 30 && current <= 119) {
            ans += v30;
        }
        if (current >= 120 && current <= 364) {
            ans += v120;
        }
        if (current >= 365) {
            ans += v365;
        }
    }

    cout << ans << endl;

    return 0;
}
