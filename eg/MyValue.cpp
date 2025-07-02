#include <iostream>
#include <memory>

static size_t objCountDes = 1;
static size_t objCountCon = 1;

class MyValue
{
public:
    // 掌握技术了就全部写上，反正这不需要其他人看懂 比如noexcept和const
    MyValue() noexcept : value(0) {}
    
    // 这是有和无explicit关键字修饰的构造函数，在下面进行测试
    MyValue(const int &val) noexcept : value(val) { std::cout << "(val) constuctor: " << objCountCon++ << std::endl; }
    // explicit MyValue(const int &val) noexcept : value(val) { std::cout << "(val) constuctor: " << objCountCon++ << std::endl; }
    
    MyValue(const MyValue &rhs) noexcept : value(rhs.value) {}
    ~MyValue() noexcept { std::cout << "~destructor: " << objCountDes++ << std::endl; }

    // 注意，返回值是&引用，而this是指针，需要*this解引用为引用
    // 返回值是MyValue&用于链式编程以支持 a = b = c 这样连续赋值
    MyValue& operator=(const MyValue &rhs) noexcept { this->value = rhs.value + 1; return *this; }

    // inline内联函数 noexcept不抛出异常 
    inline const int getValue() const noexcept { return value; } // cosnt常量函数
    inline int getValue() noexcept { return value; }

    inline void setValue(const int &val) noexcept { value = val; }
private:
    int value;
};

// 非成员函数，用于打印对象里的数值
// 函数参数类型是指定的类类型，但这跟类的本身没有什么关系，就像int参数函数跟int类型也没什么关系一样
void
printValue(const MyValue &obj) { std::cout << obj.getValue() << std::endl; }

int main()
{
    // MyValue *obj = new MyValue(1919810); // 默认构造函数动态创建堆区对象指针
    // std::unique_ptr<MyValue> obj = new MyValue(1919810); // 这样的写法不通过
    // std::unique_ptr<MyValue> obj<MyValue>(1919810) // 这种写法不推荐 涉及到隐式类型转换
    // std::unique_ptr<MyValue> ubj = std::make_unique<MyValue>(114514); // 正确写法
    // std::unique_ptr<MyValue> ubj1 = std::make_unique<MyValue>();
    // std::unique_ptr<MyValue> ubj2 = std::make_unique<MyValue>();
    // *ubj2 = *ubj1 = *ubj; // 连续赋值，链式编程，得益于operator=的返回值是对象引用

    // 普通类对象的打印测试
    // printValue(*ubj); // 解引用*有妙用 从指针对象变成直接的普通对象
    // printValue(*ubj1);
    // printValue(*ubj2);
    MyValue obj(114);
    printValue(obj);
    obj = 514; // 514作为参数隐式调用构造函数，obj变成value是514的新对象
    printValue(obj);
    // obj = 1919;
    // printValue(obj);

    // 模板类对象的打印测试
    // printValue_T(*ibj); // 这里再次强调，对象指针*解引用为普通对象
    // printValue_T(*cbj); // 之前习惯用->但没能领会真正的意思，->其实是*(obj).nember，语法糖

    return 0;
}

// 本示例代码用于测试类的构造函数、析构函数和运算符重载等语法
// 涉及到了对象创建、动态对象创建、对象指针、对象引用，构造函数、拷贝构造、运算符重载、对象传参等

// 10月7日
// 更新了智能指针的写法，用unique_ptr来创建对象指针，练习测试用例
// 还加上了一些关键字noexcept，代表此函数不抛出错误，提升程序效率，优化代码

// 首先忽略二级指针的想法，指针的指针是用来改变指针的指向的
// 引入过多复杂概念，这已经对理解浅层基础内容有了致命性的打击

// const
// const函数（在函数参数后面），限定此函数不会修改数据成员（在能检查到的显式范围）
// 还有一个作用是，用于给类内外的const对象访问成员函数，因为const对象只能访问const成员函数
// 这时只能通过复写一个函数体，来实现。打印对象的时候经常用到。


// 关于explicit修饰构造函数
// 问题概述：所谓的隐式转换，实际的机制是，对于=运算符，隐式调用构造函数创建新对象再赋值
// 比如ClassA *ptr = 114; 发生了一些思维跳跃，看似简单的赋值，其实是将右值114作为参数隐式调用构造函数，
// 创建了对象再返回，最后ptr指针指向这个对象。
// 因为右值只有一个，因此特指类中只含有一个参数的构造函数。
// 这样做看起来就十分符合人意了，是灵活的语言机制，方便给定一个参数，以=运算符的方式创建对象
// 但实际开发中要尽量避免这样的隐式构造，因为意思不明确，容易忽略构造函数中复杂过程，造成程序安全隐患
// 示例代码如下：
// MyValue obj(114);
// printValue(obj);
// obj = 514; // 这里就是在隐式调用构造函数，将514作为参数，创建好之后，114的对象空间随即析构

// 2025-6-4
// explicit使得赋值运算符=函数禁止向单参数构造函数发生隐式转换
// 因为赋值操作符=一侧只有1个参数，所以隐式转换只会面向单参数构造函数
// 所以只需要对单参数构造函数进行explicit修饰
