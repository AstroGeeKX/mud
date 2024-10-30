// P5744 【深基7.习9】培训

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

void trained(vector<Student> &students)
{
    for (Student &student : students)
    {
        student.age++;

        student.score *= 12;
        student.score /= 10;
        if (student.score > 600)
            student.score = 600;
    }
}

int main()
{
    int count;
    cin >> count;
    vector<Student> students(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> students[i].name >> students[i].age >> students[i].score;
    }
    trained(students);
    for (size_t i = 0; i < count; i++)
    {
        cout << students[i].name << " " << students[i].age << " " << students[i].score << endl;
    }
    return 0;
}