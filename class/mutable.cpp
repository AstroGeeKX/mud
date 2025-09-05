// 函数名后 const 是常函数 --> 这是本示例代码的重点
// 函数名前 const 是常返回值

#include <iostream>
using namespace std;

// 常函数不能修改成员变量
// 常对象只能调用常函数
class Person {
   public:
    Person() : m_A(0), m_B(0) {}

    // 除了mutable修饰的变量m_B
    void ShowPerson() const { this->m_B = 100; }
    void func() {}

   public:
    int m_A;
    mutable int m_B;  // 可修改 可变的
};

// const修饰对象  常对象
void test01() {
    const Person person;  // 常量对象
    cout << person.m_A << endl;
    // person.m_A = 100; // 不可修改 可访问 error: assignment of member 'Person::m_A' in read-only object
    person.m_B = 100;  // 可以修改mutable变量
    cout << person.m_B << endl;

    // 常对象不能调用non-const的函数
    // person.func();
    Person person2;
    person2.func();  // 普通对象可以调用非const函数
}

int main() {
    test01();

    return 0;
}

/*
const修饰的东西有几点疑问  先修饰左边，再修饰右边
修饰type 修饰* 修饰func()
这几个是重点，type代表值，*代表指针，func()代表函数
*/
