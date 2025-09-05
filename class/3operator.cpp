// 自增运算符
// 本节重点在于operator++的重载上，如果是后置++，则需要一个参数int
// 前置++返回引用，节省开销，后置++返回局部对象的值，不能返回引用

#include <iostream>
using namespace std;

class MyInteger {
    // 全局友元函数重载，返回值和参数为一个特别的重载，跟ostream类无关
    friend ostream& operator<<(ostream& out, MyInteger myint);

   public:
    MyInteger() : m_Num(0) {}

    // 前置++
    // 无参数，为前置
    // 返回引用节省多余的构造消耗
    MyInteger& operator++() {
        m_Num += 1;
        return *this;
    }

    // 后置++
    // 有int参数，为后置
    // 局部对象只能值方式返回，不能像前置++那样
    MyInteger operator++(int) {
        MyInteger temp = *this;  // 拷贝构造
        m_Num += 1;
        return temp;  // 返回旧值，但当前实际值已经+1了
    }

   private:
    int m_Num;
};

ostream& operator<<(ostream& out, MyInteger myint) {
    out << myint.m_Num;
    return out;
}

// 前置++ 先++ 再返回
void test01() {
    MyInteger myInt;
    cout << myInt.operator++() << endl;
    cout << myInt << endl;
}

// 后置++ 先++ 再返回旧值
void test02() {
    MyInteger myInt;
    cout << myInt << myInt++ << myInt << endl;  // 001 第二个输出时已经变为1，第三个输出可以证明
    cout << myInt++ << endl;  // 1
    cout << myInt << endl;  // 2
}

int main() {
    test01();
    cout << "------------------" << endl;
    test02();

    return 0;
}
