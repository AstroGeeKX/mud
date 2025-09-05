// 静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员

// 静态成员分为：
// *  静态成员变量
//    *  所有对象共享同一份数据
//    *  在编译阶段分配内存
//    *  类内声明，类外初始化
// *  静态成员函数
//    *  所有对象共享同一个函数
//    *  静态成员函数只能访问静态成员变量

#include <iostream>
using namespace std;

class Person {
   public:
    static int m_A;  // 静态成员变量
    int m_B;         // 非静态成员变量

    // 静态成员函数特点：
    // 1 程序共享一个函数
    // 2 静态成员函数只能访问静态成员变量
    static void func() {
        cout << "func调用" << endl;
        m_A = 100;
        // m_B = 100;  //错误，不可以访问非静态成员变量
    }

   private:
    // 静态成员也是有访问权限的
    static int m_C;  // 私有静态成员变量
    static void func2() { cout << "func2调用" << endl; }  // 私有静态函数
};
int Person::m_A = 10;
int Person::m_C = 10;

// 静态成员变量两种访问方式
void test01() {
    // 1、通过对象
    Person p1;
    p1.m_A = 100;
    cout << "p1.m_A = " << p1.m_A << endl;

    Person p2;
    p2.m_A = 200;
    cout << "p1.m_A = " << p1.m_A << endl;  // 共享同一份数据
    cout << "p2.m_A = " << p2.m_A << endl;

    // 2、通过类名
    cout << "Person::m_A = " << Person::m_A << endl;

    // cout << "m_C = " << Person::m_C << endl;  //私有权限访问不到
}

// 静态成员函数两种访问方式
void test02() {
    // 1、通过对象
    Person p1;
    p1.func();

    // 2、通过类名
    Person::func();

    // Person::func2();  //私有权限访问不到
}

int main() {
    test02();

    return 0;
}
