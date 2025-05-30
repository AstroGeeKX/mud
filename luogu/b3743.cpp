// B3743 [语言月赛202304] 扶苏与 0
/*
 题目最多输入10^18数字，这显然很大一个数字了，需要字符的方式处理这些数字
 列一个表，每个数字对应0的影子数，按照数字去查找对应关系，也可以是简单手动判断
*/
#define SOLUTION_3

#ifdef SOLUTION_1
#include <iostream>

int main() {
    char input[20] = {0};
    int counts = 0;  // 影子的个数
    std::cin >> input;  // cin可以自动处理输入的数字，拆解成单个数字放入char数组

    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
            case '2':
                counts += 1;
                continue;
            case '6':
                counts += 1;
                continue;
            case '9':
                counts += 1;
                continue;
            case '0':
                counts += 1;
                continue;
            case '8':
                counts += 2;
                continue;
            default :
                continue;
        }
    }
    std::cout << counts << std::endl;
    return 0;
}
#endif  /* SOLUTION_1 */



#ifdef SOLUTION_2
#include <iostream>

int main() {
    int counts = 0;
    char input[20] = {0};
    char num_to_count[] = {1, 0, 1, 0, 0, 0, 1, 0, 2, 1};  // 下标0-9数字对应的影子数
    std::cin >> input;

    for (int i = 0; input[i] != '\0'; i++) {
        int num = input[i];  // 提出数字
        num = num - '0';  // 转换数字序列
        counts += num_to_count[num];  // 加上对应的影子数
    }

    std::cout << counts << std::endl;

    return 0;
}
#endif  /* SOLUTION_2 */



#ifdef SOLUTION_3
/*
 第三个解题思路更巧妙，基于kv数组的前提下，使用了除余的方法来切割数字
*/
#include <iostream>

int main() {
    int counts = 0;
    char num_to_count[] = {1, 0, 1, 0, 0, 0, 1, 0, 2, 1};
    long long input = 0;  // long long 可以承受10^18数字范围
    std::cin >> input;

    while (input) {
        counts += num_to_count[input % 10];
        input /= 10;  // 破坏式处理每一位单独的数字
    }

    std::cout << counts << std::endl;

    return 0;
}
#endif  /* SOLUTION_3 */
