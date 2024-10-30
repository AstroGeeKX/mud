// P5740 【深基7.例9】最厉害的学生

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip> // 格式化输出

// n是几个学生 m是几个评委
// 函数不可返回引用，因为students的生命周期仅限函数内
std::vector<std::vector<int>> readInput(int n, int m)
{
    std::vector<std::vector<int>> students(n, std::vector<int>(m));
    for (std::vector<int> &student : students)
    {
        for (int &num : student)
        {
            std::cin >> num;
        }
        std::sort(student.begin(), student.end(), std::greater<int>()); // 从大到小排序
    }
    return students;
}

// 统分 放入一个新的容器vector<double>
std::vector<double> sumScore(const std::vector<std::vector<int>> &students, int n)
{
    int i = 0;
    std::vector<double> f_totalScores(n, 0);                   // 总分容器 n名同学的总分
    for (const std::vector<int> &student : students) // student是一名同学的评分容器
    {
        for (std::vector<int>::const_iterator iter = student.begin() + 1; iter != student.end() - 1; ++iter) // iter是一个分数
        {
            f_totalScores[i] += *iter;
        }
        i++;
    }
    return f_totalScores;
}

int main()
{
    int n = 0, m = 0; // n是同学数量 m是评委数量
    std::cin >> n >> m;
    std::vector<std::vector<int>> students = readInput(n, m); // 函数有创建容器的成分
    std::vector<double> totalScores = sumScore(students, n); // 这里也是

    for (double &value : totalScores) {
        value /= (m - 2);
    }
    std::sort(totalScores.begin(), totalScores.end(), std::greater<int>()); // sort的用法，还不太理解
    std::cout << std::fixed << std::setprecision(2) << totalScores[0] << std::endl;  // 输出两位小数
    return 0;
}