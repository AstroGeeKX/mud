// P5741 【深基7.例10】旗鼓相当的对手 - 加强版

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

// 学生姓名和三科成绩的结构体
struct Student
{
    string name;
    int score1;
    int score2;
    int score3;
    int sumScore;

    // 初始化结构体对象 由于拷贝构造函数只能初始化数字，所以用了常规的成员函数
    void setStudent(string n, int s1, int s2, int s3)
    {
        name = n;
        score1 = s1;
        score2 = s2;
        score3 = s3;
        sumScore = s1 + s2 + s3;
    }
};

int main()
{
    size_t count; // 同学个数
    cin >> count;
    vector<Student> students(count); // 若干个Students类对象 重载的[]运算符可以像使用数组那样访问和修改

    string name;
    int s1, s2, s3;
    for (size_t i = 0; i < count; i++)
    {
        cin >> name >> s1 >> s2 >> s3; // 先存入临时变量，然后调用构造函数
        students[i].setStudent(name, s1, s2, s3);
    }

    for (size_t i = 0; i < count - 1; i++)
    {
        for (size_t j = i + 1; j < count; j++)
        {
            if (abs(students[i].score1 - students[j].score1) <= 5 &&
                abs(students[i].score2 - students[j].score2) <= 5 &&
                abs(students[i].score3 - students[j].score3) <= 5 &&
                abs(students[i].sumScore - students[j].sumScore) <= 10
                )
            {
                cout << students[i].name << " " << students[j].name << endl;
            }
        }
    }
    
    return 0;
}