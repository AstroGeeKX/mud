// P1308 [NOIP 2011 普及组] 统计单词数

#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctype.h>

void my_tolower(char *a) {
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] += 32;  // 小写字符在大写字符后32个ASCII码
        }
    }
}


int main() {
    int counts = 0;
    int first_position = -1;
    char word[12] = {0};
    char input[1000003] = {0};

    fgets(word, sizeof(word), stdin);
    fgets(input, sizeof(input), stdin);

    // 去除结尾的换行符
    word[strlen(word) - 1] = 0;  // 下标-1处是最后一个字符，是换行符
    input[strlen(input) - 1] = 0;

    // 统一转换成小写，因为题目不区分大小写
    my_tolower(word);
    my_tolower(input);

    char *single_word = strtok(input, " ");
    while (single_word) {
        // printf("%s\n", single_word);
        if (strcmp(word, single_word) == 0) {
            counts += 1;
            if (first_position == -1) {  // 不要恐惧反复操作浪费性能，这样只会限致你的编程发挥
                first_position = single_word - input;
            }
        }
        single_word = strtok(NULL, " ");
    }

    if (first_position == -1) {
        std::cout << -1 << std::endl;  // 如果没找到，就输出-1
    } else {
        std::cout << counts << ' ' << first_position << std::endl;
    }
    
    return 0;
}

// 不知道如何处理字符串，是本题的最大问题，而不是其他的什么东西
// 应该采用简单的方案直接把这个问题解决了，而不是到处思考这个问题
// strtok()函数就是很好的分割单词的函数
