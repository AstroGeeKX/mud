// B3779 [语言月赛202306] 课桌
// 本题重点是ans要long long类型

#define SOLUTION_1

#ifdef SOLUTION_1
#include <iostream>

int main() {
    int n, x;
    int books;
    long long ans = 0;
    std::cin >> n >> x;

    for (int i = 0; i < n; i++) {
        std::cin >> books;
        ans += x + books;
    }
    
    std::cout << ans;

    return 0;
}
#endif  /* SOLUTION_1 */
