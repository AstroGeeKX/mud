#if 0
#include <functional>
#include <iostream>
 
struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};
 
void print_num(int i)
{
    std::cout << i << '\n';
}
 
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};
 
int main()
{
    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);
 
    // store a lambda
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();
 
    // store the result of a call to std::bind
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();
 
    // store a call to a member function
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);
    f_add_display(314159, 1);
 
    // store a call to a data member accessor
    std::function<int(Foo const&)> f_num = &Foo::num_;
    std::cout << "num_: " << f_num(foo) << '\n';
 
    // store a call to a member function and object
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind( &Foo::print_add, foo, _1 );
    f_add_display2(2);
 
    // store a call to a member function and object ptr
    std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo, _1 );
    f_add_display3(3);
 
    // store a call to a function object
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);
}
#endif /* #if 0 */
/* file:///D:/book/reference/en/cpp/utility/functional/function.html */
/************************************************************************/

#include <functional>
#include <iostream>
 
struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};
 
void print_num(int i)
{
    std::cout << i << '\n';
}
 
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};
 
int main()
{
    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);
 
    // store a lambda
    // 函数原型类型是对于函数本身的，跟函数体内容无关，所以lambda的类型是<void()>
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();
 
    // store the result of a call to std::bind
    // 绑定函数和指定参数，调用只需要空括号()
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();
 
    // store a call to a member function
    // 封装成员函数，参数列表首位多接收一个对象参数，调用的时候需要指定对象
    std::function<void(Foo const, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);
    f_add_display(314159, 1);  // tempobj = Foo(314159)隐式创建临时对象
 
    // store a call to a data member accessor
    // 比较特殊的写法，数据成员访问器，对象作为参数，获取数据成员
    std::function<int(Foo const&)> f_num = &Foo::num_;
    std::cout << "num_: " << f_num(foo) << '\n';
 
    // store a call to a member function and object
    // 成员函数绑定指定对象，并且有一个占位符_1
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind( &Foo::print_add, foo, _1 );
    f_add_display2(2);
 
    // store a call to a member function and object ptr
    // 和上面的区别是使用的是对象指针
    std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo, _1 );
    f_add_display3(3);
 
    // store a call to a function object
    // 仿函数
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);
}


/*
我们要把你知道的，我们要搞你的计划，这个思维给删除掉，第二天你照样蒙在鼓里被我们搞
“ ”
*/
