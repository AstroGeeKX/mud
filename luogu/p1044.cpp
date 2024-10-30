// P1044 [NOIP2003 普及组] 栈

#include <iostream>
#include <vector>

// Function to calculate the number of possible output sequences
long long count_sequences(int n) {
    std::vector<long long> dp(n+1, 0);
    
    // Base cases
    dp[0] = dp[1] = 1;
    
    // Fill the DP table
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1];  // Case where n is the first to pop out
        for (int k = 0; k < i-1; ++k) {
            dp[i] += dp[k] * dp[i-k-2];  // i-k-2, because n is not counted and we already have k numbers in the stack
        }
    }
    
    return dp[n];
}

int main() {
    int n;
    std::cin >> n;
    
    // Calculate and print the result
    std::cout << count_sequences(n) << std::endl;
    
    return 0;
}

// 这里用到了动态规划的算法