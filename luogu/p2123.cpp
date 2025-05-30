// B2123 字符串 p 型编码

#include <cstdio>
#include <cstring>

int main() {
    char input[1002] = {0};  // 题目最多输入1000个字符，多一个换行和一个空字符
    int counts = 1;
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';

    for (int i = 0; input[i] != '\0'/*可以使用strlen(input)*/; i++) {
        if (input[i] == input[i+1]) {
            counts += 1;
        } else {
            printf("%d%c", counts, input[i]);
            counts = 1;
        }
    }
    return 0;
}
