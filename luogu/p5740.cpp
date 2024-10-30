// P5740 【深基7.例9】最厉害的学生
// 天工AI

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 用结构体来存储单个人的信息是非常合适的
// 再用容器来创建和存储每一个结构体实例对象
// 而不是在结构体里面创建容器
struct Student {
    std::string name;
    int chinese, math, english, total;
    
    // 重载运算符< 是为了下面的max_element()函数
    bool operator<(const Student& other) const {
        return total < other.total;
    }
};

int maxMark(const std::vector<Student> &f_students, int n)
{
    int maxIndex = 0; // 假设第一个是max
    int cur = 0;
    int max = f_students[0].total;
    for (size_t i = 0; i < n; i++)
    {
        cur = f_students[i].total;
        max = f_students[maxIndex].total;
        if (cur > max)
            maxIndex = i; // 更换下标
    }
    return maxIndex; // 返回的是容器的下标 比对规则是比较结构体对象里的total
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Student> students(N); // 容器里存的是结构体类型的若干个对象
    
    for (int i = 0; i < N; ++i) {
        std::cin >> students[i].name >> students[i].chinese >> students[i].math >> students[i].english;
        students[i].total = students[i].chinese + students[i].math + students[i].english;
    }
    
    //Student best = *std::max_element(students.begin(), students.end());
    //std::cout << best.name << " " << best.chinese << " " << best.math << " " << best.english << std::endl;
    int index = 0;
    index = maxMark(students, N); // 找到total最大的结构体对象在容器students里的下标
    std::cout << students[index].name << " " << students[index].chinese << " " << students[index].math << " " << students[index].english << std::endl;
    return 0;
}

