// B4062 [GESP202412 一级] 温度转换

#include <iostream>
#include <iomanip>

int main() {
    double k, c, f;
    std::cin >> k;

    c = k - 273.15;
    f = c * 1.8 + 32;

    if (f > 212) {
        std::cout << "Temperature is too high!" << std::endl;
        return 0;  // 提前退出程序
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << c << ' ' << f << std::endl;

    return 0;
}
