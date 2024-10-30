#include <iostream>
#include <vector>

// 动态规划的斐波那契数列
int fibonacci_dp(int n) {
    if (n <= 1) {
        return n;
    }
    
    // 创建一个数组，用于存储斐波那契数
    std::vector<int> dp(n + 1);
    dp[0] = 0; // 0项是0
    dp[1] = 1; // 1项是1
    
    // 从第2项开始，计算每一项的斐波那契数 0 1 1 2 3 5 8(第六项)
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

// 优化的斐波那契数列 时间复杂度更低
int fibonacci_optimized(int n) {
    if (n <= 1) {
        return n;
    }
    
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    
    return b;
}

int main() {
    int n = 10;
    std::cout << "斐波那契数列第 " << n << " 项是: " << fibonacci_dp(n) << std::endl;
    return 0;
}