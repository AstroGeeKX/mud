// B2110 找第一个只出现一次的字符

#include <iostream>
#include <cstdio>
#include <cstring>

int main() {
    char input[1105] = {0};
    int appear_times[26] = {0};

    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\n' && input[i] != '\0'; i++) {
        int index_ = input[i] - 'a';  // 获取当前字母的序号，字母a为开始序号0
        appear_times[index_] += 1;  // 字母对应序号作为下标增1，代表字母出现的次数增1
    }

    // 注意，是按照输入顺序来遍历的 input[i]作为下标访问appear_times的元素
    for (int i = 0; i < strlen(input)/*只需要遍历数组里有效的部分*/; i++) {
        int currentLetter = input[i];
        if (appear_times[currentLetter - 'a'] == 1) {  // 当前字母的序号，找出现次数
            std::cout << char(currentLetter);  // 序号加'a'就是当前字母的ASCII码
            return 0;  // 只输出第一个，结束主函数
        }
    }

    std::cout << "no";  // 上面结束主函数，如果没有找到，才会执行这里

    return 0;
}
