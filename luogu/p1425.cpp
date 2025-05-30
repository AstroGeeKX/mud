// P1425 小鱼的游泳时间

#define SOLUTION_2

#ifdef SOLUTION_1
/*
 第一种解法，是将时间差换算成分钟数，总分钟数除以60向下取整等于小时数，取余60是分钟数
 分钟数相减可能得到负数，但是和前面的小时差*60得到的分钟数相合并，符合进制的正确运算，得到的是正确分钟数
*/
#include <iostream>

int main() {
    int startHour, startMinute, endHour, endMinute;
    int spendHour, spendMinute;
    std::cin >> startHour >> startMinute >> endHour >> endMinute;
    spendMinute = (endHour - startHour) * 60 + endMinute - startMinute;
    std::cout << spendMinute / 60 << ' ' << spendMinute % 60 << std::endl;
    return 0;    
}
#endif  /*SOLUTION_1*/



#ifdef SOLUTION_2
/*
 第二种方法是计算小时差和分钟差，假如分钟差相减是负数，则代表需要向小时借位，
 1小时60分钟这60分钟合并到分钟数上，并且小时数减1，得到正确的结果
*/
#include <iostream>

int main() {
    int startHour, startMinute, endHour, endMinute;
    int spendHour, spendMinute;
    std::cin >> startHour >> startMinute >> endHour >> endMinute;

    /* 顺序逻辑 */
    // if (endMinute < startMinute) {
    //     spendMinute = endMinute + 60 - startMinute;  // 借位多60
    //     spendHour = endHour - 1 - startHour;         // 这里减1是因为分钟借位
    // } else {
    //     spendMinute = endMinute - startMinute;
    //     spendHour = endHour - startHour;
    // }

    spendMinute = endMinute - startMinute;
    spendHour = endHour - startHour;
    if (spendMinute < 0) {
        spendMinute += 60;  // 自己琢磨加减法的借位运算
        spendHour -= 1;  // 小时借位之后，减去1
    }

    std::cout << spendHour << ' ' << spendMinute << std::endl;
    return 0;    
}
#endif  /*SOLUTION_2*/
