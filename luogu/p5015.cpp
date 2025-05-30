// P5015 [NOIP 2018 普及组] 标题统计
// 题目输入5个字符
// 本题最大收获，fgets()预留数组的长度为字符数 + 2

#include <iostream>
#include <cstring>
#include <cstdio>

int main() {
    int counts = 0;  // 字符个数
    char input[10] = {0};  // 数组最少长度为：输入字符数 + 换行符 + 空字符，也就是字符数+2

    /*  fgets()函数：
        fgets()函数会读size - 1个字符(预留空字符），如果少于这个数，会读到换行符，其余用'\0'填充
    */ 
    
    // 两个步骤，第一是数组长度，第二是fgets()的参数。字符数 + 换行符 + 空字符，也就是字符数 + 2。
    // 然后fgets()参数，字符数+2，多一个换行，多一个空字符
    // 7的情况：5个字母 1个换行符 1个空字符    6的情况：5个字母 1个空字符，但是在本题中，没有换行符也正确，6和7皆可

    fgets(input, 7, stdin);
    for (int i = 0; !(input[i] == '\0' || input[i] == '\n'); i++) {
        if (input[i] != ' ') {
            counts += 1;
        }
    }
    std::cout << counts << std::endl;
    
    return 0;
}
