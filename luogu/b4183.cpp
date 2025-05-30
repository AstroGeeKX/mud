// B4183 [中山市赛 2024] 象战

#include <iostream>

using namespace std;

int main() {
    char array[8][8] = {0};
    int flag = 0;  // 对角的个数，大于等于2说明是交叉点

    // 输入数据
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> array[i][j];
        }    
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            flag = 0;  // flag要放在第二层循环中，否则会和同一行的#叠加flag值
            if (array[i][j] != '#') continue;

            if (i + 1 <= 7 && j + 1 <= 7) {
                if (array[i + 1][j + 1] == '#') flag += 1;
            }
            if (i + 1 <= 7 && j - 1 >= 0) {
                if (array[i + 1][j - 1] == '#') flag += 1;
            }
            if (i - 1 >= 0 && j + 1 <= 7) {
                if (array[i - 1][j + 1] == '#') flag += 1;
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                if (array[i - 1][j - 1] == '#') flag += 1;
            }
            // 边沿2，其他4
            if (i == 0 || i == 7 || j == 0 || j == 7) {
                if (flag < 2) continue;
            } else {
                if (flag < 4) continue;
            }

            cout << i + 1 << " " << j + 1 << endl;
            return 0;  // 结束主函数
        }
    }
    return 0;
}
