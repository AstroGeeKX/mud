// B2109 统计数字字符个数

#include <iostream>
#include <cstdio>

int main() {
    char input[260] = {0};
    int counts = 0;
    fgets(input, sizeof(input), stdin);
    
    for (int i = 0; i < sizeof(input); i++) {
        if (input[i] >= '0' && input[i] <= '9')
            counts += 1;
    }
    std::cout << counts << std::endl;
    return 0;
}
