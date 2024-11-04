#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <utility>        // std::move

int do_get_value() { return 11; }

int main ()
{
    // 由默认构造函数创建的 std::future 对象,
    // 初始化时该 std::future 对象处于为 invalid 状态.
    std::future<int> foo, bar;
    // foo bar are invalid
    foo = std::async(do_get_value); // move 赋值, foo 变为 valid.
    // foo is valid
    bar = std::move(foo); // move 赋值, bar 变为 valid, 而 move 赋值以后 foo 变为 invalid.
    // bar is valid
    if (foo.valid())
        std::cout << "foo's value: " << foo.get() << '\n';
    else
        std::cout << "foo is not valid\n";

    if (bar.valid())
        std::cout << "bar's value: " << bar.get() << '\n';
    else
        std::cout << "bar is not valid\n";

    return 0;
}

// https://www.cnblogs.com/haippy/p/3280643.html
// 这个示例说明了future类里valid成员函数的使用
// 合法为1 非法为0 描述一个future对象是否可用