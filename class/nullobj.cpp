// C++ 中空指针可以调用成员函数，当然这个函数不能用到this指针
// 如果用到this指针，需要加以判断保证代码的健壮性

#include <iostream>
using namespace std;

// 空指针访问成员函数
class Person {
   public:
    void ShowClassName() { cout << "我是Person类!" << endl; }

    void ShowPerson() {
        if (this == nullptr) {
            return;
        }
        cout << mAge << endl;
    }

   public:
    int mAge;
};

void test01() {
    Person* p = nullptr;
    p->ShowClassName();  // 空指针，可以调用成员函数
    p->ShowPerson();     // 但是如果成员函数中用到了this指针，就不可以了
}

int main() {
    test01();

    return 0;
}
