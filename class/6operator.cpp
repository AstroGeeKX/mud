// 函数运算符重载（仿函数）
// 重载了之后，类对象名就是函数名，类对象名加括号，就是函数调用的效果
// 匿名调用方式直接使用类名，类名后面有一对括号，再调用函数

#include <iostream>
#include <string>
using namespace std;

class MyPrint {
   public:
    void operator()(string text) { cout << text << endl; }
};

void test01() {
    MyPrint myprint;
    myprint("hello world");  // 字符串参数
}

class MyAdd {
   public:
    MyAdd() {
        cout << "MyAdd()" << endl;
    }
    int operator()(int v1, int v2) { return v1 + v2; }
};

void test02() {
    MyAdd add;
    int ret = add(10, 10);
    cout << "ret = " << ret << endl;

    // 匿名对象调用
    // 构造临时对象，再调用
    cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main() {
    test01();
    test02();

    return 0;
}
