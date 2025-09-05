// 赋值运算符=
// 包括深拷贝浅拷贝、隐式创建临时对象、对象的生命周期等

#include <iostream>
using namespace std;

class Person {
   public:
    int *m_Age;

    // 构造
    Person(const int &age) {
        cout << "Person(const int &age) is invoked [age: " << age << "]" << endl;
        cout << "    this: " << this << endl;
        m_Age = new int;
        *m_Age = age;
    }
    // 赋值
    Person &operator=(const Person &p) {
        cout << "operator=(const Person &p) is invoked [*this->age: " << *this->m_Age << "]" << "[*p.m_Age: " << *p.m_Age << "]" << endl;
        cout << "    this: " << this << endl;
        if (m_Age != NULL) {
            delete m_Age;
            m_Age = NULL;
        }
        // m_Age = p.m_Age;  // 浅拷贝

        m_Age = new int(*p.m_Age); 
        return *this;
    }
    // 析构
    ~Person() {
        cout << "~Person() is invoked [age: " << *m_Age << "]" << endl;
        cout << "    this: " << this << endl;
        if (m_Age != NULL) {
            delete m_Age;
            m_Age = NULL;
        }
    }
};

void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	cout << "p1  " << *p1.m_Age << endl;
	cout << "p2  " << *p2.m_Age << endl;
	cout << "p3  " << *p3.m_Age << endl;
	p3 = p2 = p1;
    *p1.m_Age = 100;
    cout << "p2 = p3 = p1;" << endl;
	cout << "p1  " << *p1.m_Age << endl;
	cout << "p2  " << *p2.m_Age << endl;
	cout << "p3  " << *p3.m_Age << endl;
} /* 如果浅拷贝，赋值之后，所有对象资源共同指向p1，逻辑上的致命错误 */

void test02()
{
    Person p1(0);
    p1 = 1000;  // 重点语句
	cout << "p1: " << *p1.m_Age << endl;
} /* 隐式创建临时对象再赋值 */

// Person p1(0);
// p1 = 1000;
// 隐式创建临时对象再赋值的过程：先构造一个临时对象，赋值给左边的p1，再销毁临时对象
// Person tempobj(1000); p1 = tempobj; ~tempobj;
//     1: Person(const int &age)  // non-explicit 构造临时对象是隐式调用构造函数，不能用explicit修饰
//     2: Person &operator=(const Person &p)
//     3: ~Person()  // tempobj

int main() {

	test02();

	return 0;
}
