// P3717 [AHOI2017初中组] cover 题解
// 题目给出的坐标是下标1

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m, r;
    int x, y;
    int ans = 0;
    int array[105][105] = {0};  // 这是地图
    int bot[105][2] = {0};      // 这是探测器可能的位置，col_1是x，col_2是y

    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {  // 输入探测器坐标
        cin >> x >> y;
        bot[i][0] = x;
        bot[i][1] = y;
    }

    for (int a = 1; a <= n; a++) {      // 遍历所有的点，计算和探测器的距离
        for (int b = 1; b <= n; b++) {  // a和b作为下标1
            for (int i = 0; i < m; i++) {  // 所有探测器去探这个扫描点，看距离是否足够
                double distance = 0;
                int x = bot[i][0], y = bot[i][1];
                distance = sqrt( (x - a) * (x - a) + (y - b) * (y - b) );
                if (distance <= r) {  // 判断符号<=是关键，没有=号会计算出错误答案
                    array[a][b] = 1;  // 能探测到
                    break;  // 退出的是计算探测器距离的循环
                }
            }
        }
    }

    // 最后统计地图所有探测到的点
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (array[i][j] == 1) {
                ans += 1;
            }
        }
    }
    
    cout << ans;

    return 0;
}
