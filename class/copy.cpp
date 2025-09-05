// C++ 中拷贝构造函数调用时机通常有三种情况

//     *使用一个已经创建完毕的对象来初始化一个新对象
//     *值传递的方式给函数参数传值
//     *以值方式返回局部对象

#include <iostream>
using namespace std;

class Person {
   public:
    Person() {
        cout << "无参构造函数!" << endl;
        mAge = 0;
    }
    Person(int age) {
        cout << "有参构造函数!" << endl;
        mAge = age;
    }
    Person(const Person &p) {
        cout << "拷贝构造函数!" << endl;
        mAge = p.mAge;
    }
    // 析构函数在释放内存之前调用
    ~Person() { cout << "析构函数!" << endl; }

   public:
    int mAge;
};

// 1. 使用一个已经创建完毕的对象来初始化一个新对象
void test01() {
    Person man(100);       // p对象已经创建完毕
    Person newman(man);    // 拷贝构造
    Person newman2 = man;  // 拷贝构造

    // Person newman3;
    // newman3 = man; //不是调用拷贝构造函数，是赋值操作
}

// 2. 值传递的方式给函数参数传值
// 相当于Person p1 = p;
void doWork(Person p1) {}
void test02() {
    Person p;  // 无参构造函数
    doWork(p);  // 拷贝构造
}

// 3. 以值方式返回局部对象
Person doWork2() {
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
}

void test03() {
    Person p = doWork2();  // 拷贝行为，无参构造
    cout << (int *)&p << endl;
}

int main() {
    // test01();
    // test02();
    test03();

    return 0;
}

/*
test03 g++编译器加入编译选项关闭RVO优化 -fno-elide-constructors
这时候可以看到是执行了拷贝构造，再将局部对象析构。
否则，RVO优化只会在返回值处就地无参构造一个对象
*/
