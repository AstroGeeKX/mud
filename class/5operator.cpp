// 关系运算符
// ==和!=重载来进行判断对象是否相等
// 这需要主观逻辑上的思绪，一个类在某种程度上需要进行这样的操作时，才需要
// 逻辑上是一个从描述到实际结果的过程

#include <iostream>
#include <string>
using namespace std;

class Person {
   public:
    Person(string name, int age) : m_Name(name), m_Age(age) {};

    bool operator==(const Person& p) {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
            return true;
        } else {
            return false;
        }
    }

    bool operator!=(const Person& p) {
        // 这个逻辑挺奇怪
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
            return false;
        } else {
            return true;
        }

        // 另一个逻辑
        // if (this->m_Name != p.m_Name || this->m_Age != p.m_Age) {
        //     return true;
        // } else {
        //     return false;
        // }
    }

    string m_Name;
    int m_Age;
};

void test01() {
    // int a = 0;
    // int b = 0;

    Person a("孙悟空", 18);
    Person b("孙悟空", 18);

    if (a == b) {
        cout << "a和b相等" << endl;
    } else {
        cout << "a和b不相等" << endl;
    }

    if (a != b) {
        cout << "a和b不相等" << endl;
    } else {
        cout << "a和b相等" << endl;
    }
}

int main() {
    test01();

    return 0;
}
