#include <iostream>
using namespace std;

class myclass {
   public:
    int *m_Age;

    // 构造函数
    // explicit
    myclass(const int &age) {
        cout << "myclass(const int &age) [age: " << age << "]"
             << endl;
        cout << "    this: " << this << endl;
        m_Age = new int;
        *m_Age = age;
    }
    // 拷贝构造
    // explicit
    myclass(const myclass &p) {
        cout << "myclass(const myclass &p) [*p.m_Age: " << *p.m_Age
             << "]" << endl;
        cout << "    this: " << this << endl;
        m_Age = new int(*(p.m_Age));
    }
    // 拷贝赋值
    myclass &operator=(const myclass &p) {
        cout << "operator=(const myclass &p) [*this->age: "
             << *this->m_Age << "]" << "[*p.m_Age: " << *p.m_Age << "]" << endl;
        cout << "    this: " << this << endl;
        // 销毁原数据
        if (m_Age != nullptr) {  
            delete m_Age;
            m_Age = nullptr;
        }
        m_Age = new int(*p.m_Age);  // new并初始化

        return *this;
    }

    // 析构函数
    ~myclass() {
        cout << "~myclass() [age: " << *m_Age << "]" << endl;
        cout << "    this: " << this << endl;
        if (m_Age != NULL) {
            delete m_Age;
            m_Age = NULL;
        }
    }
};

int main() {
    myclass obj1(18);  // 显式构造
    // myclass obj3(obj1);  // 显式拷贝构造
    myclass obj3 = obj1;    // 隐式拷贝构造
    obj3 = obj1;  // 赋值
    obj3 = 11;  // 隐式构造 赋值 析构
    cout << "obj1: " << *obj1.m_Age << endl;
    // cout << "obj2: " << *obj2.m_Age << endl;
    cout << "obj3: " << *obj3.m_Age << endl;
    return 0;
}

// explicit只修饰构造函数
// 但深浅拷贝是构造函数和赋值运算符都有的事情

/*
myclass obj3(obj1);   // 显示拷贝构造
myclass obj3 = obj1;  // 隐式拷贝构造
obj3 = obj1;          // 拷贝赋值

myclass obj3(9);  // 显示构造
myclass obj3 = 10;  // 隐式构造
obj3 = 11;          // 隐式构造 拷贝赋值 析构
*/
