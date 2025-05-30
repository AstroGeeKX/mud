// B4021 [语言月赛 202408] 于抑郁中支持

#define SOLUTION_2

#ifdef SOLUTION_1
/*
 题解1的思路是仅仅输入后t位，用set来帮忙去重
 set的size就是不同事件数
*/
#include <iostream>
#include <set>
#include <cmath>

int main() {
    int n, t, mod;
    int x;
    std::set<int> ans;
    std::cin >> n >> t;
    mod = std::pow(10, t);

    for (int i = 0; i < n; i++) {
        std::cin >> x;
        x = x % mod;  // 只留取最后mod位数字，取余运算可以做到
        ans.insert(x);
    }

    std::cout << ans.size() << std::endl; 
    return 0;
}
#endif  /* SOLUTION_1 */



#ifdef SOLUTION_2
/*
 题解2的思路是使用桶，常规的计数桶，下标数字对应个数的桶
 这个桶至少n 10000那么大,思路很清晰了 
*/
#include <iostream>
#include <cmath>

int main() {
    int n, t, mod, counts = 0;
    int array[10000] = {0};  // n最大是10000
    int temp;
    std::cin >> n >> t;
    mod = std::pow(10, t);

    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        temp %= mod;
        array[temp] += 1;
    }

    for (int i = 0; i < mod/*mod是优化范围，可以无脑10000*/; i++) {
        if (array[i] > 0) {
            counts += 1;
        }
    }

    std::cout << counts << std::endl;

    return 0;
}
#endif  /* SOLUTION_2 */
