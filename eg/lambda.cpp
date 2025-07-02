#include <iostream>
#include <functional>

using namespace std;

class Person {
    int a = 0;

   public:
    explicit Person(const int &rhs) : a(rhs * 2) {}

    void say_hello() { std::cout << "hello Person " << a << endl; }
};

/* 在这里正常写一个函数，再放进lambda表达式里 */
void func(int a) {
    std::cout << 114514 << std::endl;
}

int main() {
    int x = 5;
    // void (*pfunc)(int&) = nullptr;  // 函数指针，标识符只有pfunc

    // auto lam1 = [](int a) -> int { return a + a; };
    // auto lam2 = [](int a) { return a + a; };  // 省略返回值类型

    // std::function<void()> f = Person::say_hello; // 封装static成员函数
    // f();  // 名称就一个字f

    /* function同样能写lambda表达式 */
    // std::function<void()> lambda = []() {
    //     std::cout << "Hello, Lambda!" << std::endl;
    // };
    // lambda(); // 输出: Hello, Lambda!

    Person p1 = Person(1);  // 第一种构造方式
    Person p2(2);           // 第二种构造方式
    Person *p3 = new Person(3);
    // 绑定公有成员函数和相应的对象
    auto b1 = std::bind(Person::say_hello, p1);
    b1();
    auto b2 = std::bind(Person::say_hello, p2);
    b2();

    return 0;
}

// lambda表达式用法

// function<>可调用对象打包用法

// bind绑定函数参数用法
