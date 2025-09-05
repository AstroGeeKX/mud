// 纯虚函数 基本认知
// 类中只要有一个纯虚函数就称为抽象类
// 抽象类无法实例化对象
// 子类必须重写父类中的纯虚函数，否则也属于抽象类

#include <iostream>
using namespace std;

class Base {
   public:
    virtual void func() = 0;
};

class Son : public Base {
   public:
    virtual void func() { cout << "func调用" << endl; };
};

void test01() {
    Base* base = nullptr;
    // base = new Base; // 错误，抽象类无法实例化对象
    base = new Son;  // 基类指针指向子类对象
    base->func();
    delete base;  // 记得销毁
}

int main() {
    test01();

    return 0;
}
