#include <iostream>

template <class T>
class MyValue
{
public:
    MyValue() : value(0) {} // 默认构造
    MyValue(const MyValue &rhs) : value(rhs.value) {} // 拷贝构造
    MyValue(const T &val) : value(val) {} // 初值构造

    void operator=(const MyValue &rhs) { value = rhs.value + 1; } // 赋值运算
    bool operator>(const MyValue &rhs) { return value > rhs.value; } // 大于运算
    bool operator<=(const MyValue &rhs) { return value <= rhs.value; } // 小于等于运算

    T operator[](const T &index) // 方块号运算
    {
        // 这里index参数只是做一个样子，[]必须有一个参数
        if (index > 0)
        {
            return -114;
        }
        return value;
    }

    T getValue() const { return value; } // 获取值
    void setValue(const T &val) { value = val; } // 设置值
private:
    T value;
};

// 这样写能正常编译
template <typename T>
void printValue(const MyValue<T> &obj)
{
    std::cout << obj.getValue() << std::endl;
}

int main()
{
    MyValue<int> obj(114514);
    MyValue<char> cbj('c');
    // MyValue *pbj = new MyValue(1919810); // 调用默认构造函数动态创建堆区对象

    printValue(obj);
    printValue(cbj);
    // printValue(*pbj); // 解引用*有妙用 直接从指针对象变成普通对象

    // // 逻辑运算符
    // std::cout << "obj > *pbj is: " << (obj > *pbj) << std::endl;
    // std::cout << "obj <= *pbj is: " << (obj <= *pbj) << std::endl;
    
    // // []运算符
    // std::cout << "obj[0] is: " << obj[0] << std::endl;
    // std::cout << "obj[1] is: " << obj[1] << std::endl;

    // // =运算符
    // std::cout << "obj is: " << obj.getValue() << std::endl;
    // obj = *pbj;
    // std::cout << "operator=, now: " << obj.getValue() << std::endl;

    // std::cout << "addr pbj - &obj is: " << pbj - &obj << std::endl;

    return 0;
}

// 用于测试类的各个构造函数和运算符重载的实例程序
// 涉及到了对象创建、动态对象创建、对象指针、对象引用
// 构造函数、拷贝构造、运算符重载、对象参数传参等

// 这个copy版本的 类模板 练习中，用模板实现泛型，这是最基本的思想的出发点
// 只是很简单的在类名前面添加一个template <class T>
// 然后把所有的value的类型，也就是`int`全部CTRL + f替换成`T`，就可以正常编译了
// 不知道T是什么的，可以自行脑部，补充成int，就清晰很多了
