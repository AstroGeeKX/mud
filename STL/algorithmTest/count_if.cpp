#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Greater4 {
   public:
    // bool operator()(int val) { return val >= 4; }
    bool operator()(int val) { return true; }
};

// 内置数据类型
void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    int num = count_if(v.begin(), v.end(), Greater4());

    cout << "大于等于4的个数为： " << num << endl;
}

// 自定义数据类型
class Person {
   public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class AgeLess35 {
   public:
    bool operator()(const Person &p) { return p.m_Age < 35; }
};

void test02() {
    vector<Person> v;

    Person p1("刘备", 35);
    for (int i = 0; i < 10; i++) {
        Person p("张飞", 30 + i);
        v.push_back(p);
    }

    int num = count_if(v.begin(), v.end(), AgeLess35());
    cout << "小于35岁的个数：" << num << endl;
}

int main() {
    test01();

    test02();

    return 0;
}
