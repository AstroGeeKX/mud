// 开关灯

#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    bool *light = new bool[n]{};  // 创建n个灯的布尔数组 并用{}初始化所有元素为false

    for (int i = 2; i <= n; i++) {  // 这是每个人的操作
        for (int j = 0; j < n; j++) {  // 这是每个灯的操作
            if ( (j + 1) % i == 0 ) {  // 灯号(数组下标+1)是人号的倍数，需要反转灯的状态
                if (light[j] == true) {  // 这里进行灯反转的操作
                    light[j] = false;
                } else {  // 否则就是关变开
                    light[j] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (light[i] == false) {
            std::cout << i + 1 << " ";
        }
    }

    delete[] light;
    return 0;
}
