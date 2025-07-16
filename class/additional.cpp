// +号是二元运算符，所以有2个参数，代表左右两边的操作数
// 又因为成员函数里，this能代表左边的操作数，所以只写右边的操作数
// +运算符是一种形似函数调用的东西，有一种转形的感觉

#include <iostream>
using namespace std;

class Person {
   public:
    Person() { cout << "Person()" << endl; };
    ~Person() { cout << "~Person()" << endl; };
    Person(int a, int b) {
        cout << "Person(int a, int b)" << endl;
        this->m_A = a;
        this->m_B = b;
    }
    // 成员函数实现 + 号运算符重载
    Person operator+(const Person& p) {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }

   public:
    int m_A;
    int m_B;
};

// 全局函数实现 + 号运算符重载
// 和成员函数冲突的情况下，优先调用成员函数，这里+1来分辨全局函数
// Person operator+(const Person& p1, const Person& p2) {
// 	Person temp(0, 0);
// 	temp.m_A = p1.m_A + p2.m_A + 1;
// 	temp.m_B = p1.m_B + p2.m_B + 1;
// 	return temp;
// }

// 运算符重载 可以发生函数重载 这也是全局重载+符号
Person operator+(const Person& p2, int val) {
    Person temp;
    temp.m_A = p2.m_A + val;
    temp.m_B = p2.m_B + val;
    return temp;
}

void test() {
    Person p1(10, 10);
    Person p2(20, 20);

    // 成员函数方式
    Person p3 = p2 + p1;  // 相当于 p2.operaor+(p1)
    // Person p3 = p2.operator+(p1);  // 显式调用成员函数
    cout << "mA:" << p3.m_A << " mB:" << p3.m_B << endl;

    // Person p4 = p3 + 10;  // 相当于 operator+(p3,10)
    Person p4 = operator+(p3, 10);  // 显式调用全局函数
    cout << "mA:" << p4.m_A << " mB:" << p4.m_B << endl;
}

int main() {
    test();

    return 0;
}

// 不要以reference或address的形式返回局部创建的变量
// 要直接以值的形式返回，这会调用默认构造函数
