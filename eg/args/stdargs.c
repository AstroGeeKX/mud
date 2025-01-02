#include <stdio.h>
#include <stdarg.h>

int sum(int count,...) {
    int result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        result += va_arg(args, int);
    }
    va_end(args);
    return result;
}

int sub(int count, ...) {
    va_list args;
    va_start(args, count);
    int result = va_arg(args, int);
    for (int i = 0; i < count - 1; ++i) {
        result -= va_arg(args, int);
    }
    va_end(args);
    return result;
}

int main() {
    int res = sub(5, 25, 25, 50, 50, -214);
    printf("%d\n", res);
    return 0;
}

// 可变参数原始用法是这几个宏，va_list va_start va_arg va_end
// 函数参数通常需要传入一个参数代表参数的个数，printf不需要这样做是因为%的设计
// 这样的理解多少有点不适应，以为这是什么冷门的知识
