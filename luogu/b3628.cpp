// B3628 机器猫斗恶龙

#define SOLUTION_1

#ifdef SOLUTION_1
#include <iostream>
using namespace std;

int main() {
    int n = 0;              // 战斗次数
    int array[1005] = {0};  // 加血和减血
    int ans = 1;            // 最终答案
    int blood = 1;          // 枚举血量
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    while (true) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            blood += array[i];
            if (blood <= 0) {
                flag = false;  // 战斗死亡，设置为flase
                break;
            }
        }

        if (flag == false) {
            ans += 1;     // 血量需要继续增加，继续尝试战斗
            blood = ans;  // 更新临时血量
        } else {
            cout << ans << endl;
            return 0;
        }
    }

    return 0;
}
/*
从头到底遍历每一个战斗过程，如果血量少于0，标记死了，
一直增加血量，直到过程不死为止
不AC，问了AI只回答时间复杂度的问题，测试结果找不到错的地方
*/
#endif 


#ifdef SOLUTION_2
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
int a[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 从后往前计算，确定每个关卡所需的最小血量
    long long min_health = 1; // 通过所有关卡后至少需要1点血量
    
    for (int i = n - 1; i >= 0; i--) {
        min_health = max(1LL, min_health - a[i]);
    }
    
    cout << min_health << endl;
    return 0;
}
#endif
