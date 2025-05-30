// B2097 最长平台

#define SOLUTION_3

#ifdef SOLUTION_1
#include <iostream>

int main() {
    int n = 0;
    int array[101] = {0};  // 题目最多100个数字，101是预留了一个数字，以适用于下标1为起点，100为终点
    std::cin >> n;  // 这是输入的数字个数
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    // 遍历数组里的元素，ref作为参考，如果相同，最大连号数、临时连号数加1 max+1，
    // 如果不同，临时连号置1 max_ = 1，同时更新参考数字ref = array[i]
    int ref = array[0];
    int max = 1, max_ = 1;
    for (int i = 1; i < n; i++) {
        if (ref == array[i]) {
            max_ += 1;
        } else {
            max = max_ > max ? max_ : max;  // 更新max，三元运算符的简单使用
            ref = array[i];
            max_ = 1;
        }
    }

    std::cout << max << std::endl;
    return 0;
}
#endif  // SOLUTION_1
// 算法题目重点在于算法逻辑，语言实现尽量简单化，没必要追求动态分配内存等操作
// 追求语言实现容易过度分散注意力，忽略算法本质


/* 
    题解2省略了ref变量，直接用array[i] == array[i + 1]对比前后元素是否相等
    更新max的三元表达式改为if语句，可读性更好
*/
#ifdef SOLUTION_2
#include <iostream>

int main() {
    int n = 0;
    int array[101] = {0};  // 题目最多100个数字，101是预留了一个数字，以适用于下标1为起点，100为终点
    std::cin >> n;  // 这是输入的数字个数
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    // 遍历数组里的元素，当前和后一个元素如果相同，最大连号数、临时连号数加1 max+1，
    // 最好分清“递增”和“下一个”的区别
    int max = 1, max_ = 1;
    for (int i = 0; i < n; i++) {
        if (array[i] == array[i+1]) {
            max_ += 1;
        } else {
            // max = max_ > max ? max_ : max;  // 更新max，如果当前max_更大，那么赋值到max
            if (max_ > max) max = max_;
            max_ = 1;
        }
    }

    std::cout << max << std::endl;
    return 0;
}
#endif  // SOLUTION_2


/*
    题解3 双指针
    左指针记录平台的开始，右指针滑动至平台的结尾，右指针减去左指针得到平台长度，注意+1边界处理
    算法实现简单，技术难度和技术价值不高，建议快速完成，进行下一步的学习
*/
#ifdef SOLUTION_3
#include <iostream>

int main() {
    int n = 0;
    int array[101]{0};  // 预留1位数字，不是必须
    int length = 1;
    int maxLength = 1;
    int *left;
    int *right;
    left = right = array;

    std::cin >> n;  // 输入个数
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    for (int k = 0; k < n; k++) {
        if (array[k] == array[k+1]) {
            right++; // 指针右移，代表实际探测到的平台长度增加
        } else {
            length = right - left + 1;  // 平台截止，计算平台长度
            right = left = right + 1;  // 左右指针同时指向下一个平台的开始
            if (length > maxLength) maxLength = length;
        }
    }

    std::cout << maxLength << std::endl;

    return 0;
}
#endif  // SOLUTION_3


/*
    题解4 键值对 桶
    数组个数n（1≤n≤100），输入的整数 k 范围（0<k<2000），重点在于k，只有2000，
    可以做一个数量为2000的数组，每个元素记录这个数字出现了多少次。 键值对 - 键是数字，值是出现次数
    假如键值对足以覆盖所有数字范围，即0到2000，那么可以采用这样的方式，但是有些数字不用到，就会浪费许多键值对
    题目不会重复数字，如果会，那么结果偏大，大于实际最大的平台长度，因为有不同段的数字拼接
    1 1 1 2 2 2 2 1 1 3  结果是5，因为数字1出现了5次，正确答案应该是2平台长度为4
*/
