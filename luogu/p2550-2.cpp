#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>

const int NUMBERS_COUNT = 7; // 单张彩票号码个数

/*
    彩票信息输入函数
    唯一的参数n是指彩票张数
    返回值类型为std::vector<std::vector<int>>
    基于EFC原则，需要的时候再创建。
    这里创建了一个vector对象，里面装着若干各vector对象，没有听错
    第一层循环代表几张彩票n
    第二次循环代表单张彩票上有多少各号码 NUMBERS_COUNT 7个
*/
std::vector<std::vector<int>> readInput(int n) {
    std::vector<std::vector<int>> lotteryNumbers(n, std::vector<int>(NUMBERS_COUNT));
    for (int i = 0; i < n; ++i) {
        for (int &num : lotteryNumbers[i]) {
            std::cin >> num;
        }
    }
    return lotteryNumbers;
}

/*
    单张彩票号码中奖的个数
    参数1：单张彩票容器 参数2：最终号码容器  常量左值引用 是c++习惯 用于只读
    count(key)时间复杂度O(1)用来查找key的个数，但这里只用来当作==对比数据
    返回中奖的号码的个数
*/
int countWinningNumbers(const std::vector<int> &lottery, const std::unordered_set<int> &winningNumbers) {
    int winningNumbersCount = 0;
    for (int num : lottery) {
        if (winningNumbers.count(num)) {
            ++winningNumbersCount;
        }
    }
    return winningNumbersCount;
}

int main() {
    int n;
    std::cin >> n;

    // 输入开奖结果 放在unordered_set容器中
    std::unordered_set<int> winningNumbers;
    for (int i = 0; i < NUMBERS_COUNT; ++i) {
        int num;
        std::cin >> num;
        winningNumbers.insert(num);
    }

    // 输入所有彩票号码
    std::vector<std::vector<int>> lotteryNumbers = readInput(n);

    // winningCounts是中奖记录容器 7个元素表示 特等奖到六等奖
    // 遍历每一张彩票 调用countWinningNumbers()函数计数对了几个号码
    // 然后利用万能的数组来记录中奖情况 笨方法可以用switch分支
    std::array<int, NUMBERS_COUNT> winningCounts = {0};
    for (const auto &lottery : lotteryNumbers) {
        int winningNumbersCount = countWinningNumbers(lottery, winningNumbers);
        if (winningNumbersCount > 0) {
            ++winningCounts[winningNumbersCount - 1];
        }
    }

    // 倒序输出中奖结果 就是正序的 为了计算机的特性 稍微优化一下人的主观意识 成本不高
    for (int i = NUMBERS_COUNT - 1; i >= 0; --i) {
        std::cout << winningCounts[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

/*
    这个程序用了三种不同的容器，分别是vector、unordered_set和array
    用来记录 彩票号码、开奖结果、中奖记录
    其实彩票号码也可以用unordered_set来存储，更符合彩票号码不重复的性质
*/