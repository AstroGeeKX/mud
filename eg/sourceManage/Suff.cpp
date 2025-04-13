#include <iostream>
#include <string>
#include <cstdio>

// 掌管资源的类，四大函数全部删光，然后安心定义析构函数
class Suff
{
public:
    std::string s;
    void *p; // 指针资源

    Suff() : s("默认构造的对象")
    {
        p = malloc(1);
        std::cout << "调用构造函数" << std::endl;
    }

    // 删除四大函数
    // Suff(Suff &&) = delete;
    Suff(Suff const &) = delete;            // 可省略不写
    // Suff &operator=(Suff &&) = delete;      // 可省略不写
    // Suff &operator=(Suff const &) = delete; // 可省略不写
    
    // **拷贝构造**
    // explicit Suff(Suff const &that) : s("拷贝构造的对象")
    // {
    //     std::cout << "调用拷贝构造函数" << std::endl;
    // }

    // **移动构造** 移动构造管理资源在于，将原资源销毁，这样就不会造成两份资源的情况
    Suff(Suff &&that) : s("移动构造的对象"), p(that.p)
    {
        that.p = nullptr; // 一定要把对方置空！
        std::cout << "调用移动构造函数" << std::endl; 
    }

    // **拷贝赋值** 赋值不是构造，即使都是四大函数，但并没有构造
    // Suff &operator=(Suff const &that)
    // {
    //     s = "拷贝赋值的对象";
    //     std::cout << "调用拷贝赋值函数" << std::endl;
    //     return *this;
    // }

    ~Suff()
    {
        if (p)
        {
            std::cout << "~析构" << " " << s;
            std::cout << " 释放指针p" << std::endl;
            free(p);
        }
        else
        {
            std::cout << "~析构" << " " << s << std::endl;
        }
    }
};

void func(Suff x)
{
    std::cout << "func函数左括号{" << std::endl;
}

// 资源管理一大重点在于移动构造，资源转移，避免二次释放资源
// 移动构造里将原资源销毁清空，析构函数里先if判断资源指针是否清空然后再释放

int main()
{
    auto suff = Suff();  // 打印：调用构造函数
    std::cout << "func函数调用前一行" << std::endl;
    func(std::move(suff));  // 打印：调用了移动构造函数
    std::cout << "func函数右括号}" << std::endl;

    // Suff suff2(std::move(suff));
    // 假如移动构造没有实现，并且使用了move，那么隐式调用拷贝构造
    // Suff suff3;
    // suff3 = suff;  // 首次创建新对象只会调用构造而不是赋值， operator=赋值将转化为构造函数()

    return 0;
}

// 右值移动并没有什么复杂的地方，旨在标记右值的手段来选择具体的内存操作方法，必须要开发者具体实现
// 栈上创建了多少对象，都是在生命周期结束后销毁，并没有移动的意思
// 内置基本类型构成的简单类，不具移动构造的意义，不会因此节省性能
