// B2137 判决素数个数
// 查找素数可以暴力轻松解决，也可以使用埃氏筛，在不优化的情况下，这个思路简单

#define SOLUTION_2

#ifdef SOLUTION_1
/*
 *这是普通解法，遍历取余，有一些针对循环范围的优化
 *仔细一看才知道是x和y的范围可能相反输入，需要倒转过来，才能正确
*/
// #include <bits/stdc++.h>
#include <iostream>

int main() {
    int x, y;
    int flag = 0;
    int ans = 0;
    std::cin >> x >> y;
    if (x > y) std::swap(x, y);  // 这是代码能否AC的关键，简直奇葩

    for (int i = x; i <= y; i++) {  // 范围内每一个数是否是素数的计算 3
        flag = 1;
        for (int j = 2; j * j <= i; j++) {  // 3卡bug，不进入循环，没有%过程
            // 能整除说明不是素数，直接标记flag = 0并退出循环
            if (i % j == 0 || i % 2 == 0) {  // i % 2这个优化了20ms
                flag = 0;
                break;
            }
        }

        if (flag == 1 && i != 1) {
            ans += 1;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
#endif  /* SOLUTION_1 */



#ifdef SOLUTION_2
/*
*埃氏筛法，利用的原理简单来说就是素数的倍数是合数，从2开始
*2、3、5、7的倍数通通挤爆数组，就能够标记所有的合数
*剩下来的就是素数。代码里循环有2点优化，看起来莫名其妙
*但抛开优化的部分，最主要的逻辑是简单的
*/
#include <bits/stdc++.h>
int main() {
    int x, y, ans = 0;
    std::cin >> x >> y;
    if (x > y) std::swap(x, y);

    std::vector<bool> isPrime(1.1e6, true);  // 1.1e6具体数值是1100000
    isPrime[0] = isPrime[1] = false;  // 0和1不是素数
    for (int p = 2; p * p <= y; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= y; i += p)
                isPrime[i] = false;
        }
    }

    for (int i = x; i <= y; i++) {
        if (isPrime[i])
            ans += 1;
    }

    std::cout << ans;
	return 0;
}
#endif  /* SOLUTION_2 */
