// B2046 骑车与走路
#include <iostream>

int main() {
    double distance = 0;
    double walk_v = 1.2;
    double bike_v = 3;
    int bike_time_add = 50;  // 自行车额外消耗50秒

    std::cin >> distance;
    if (distance / walk_v == (distance / bike_v + bike_time_add)) {
        std::cout << "All";
    } else if (distance / walk_v < (distance / bike_v + bike_time_add)){
        std::cout << "Walk";
    } else {
        std::cout << "Bike";
    }
    std::cout << std::endl;
    return 0;
}
