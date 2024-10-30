#include <iostream>

class MyInt;

class MyInt
{
    // 重载>大于运算符
    bool operator>(const MyInt &rhs) const { return this->value > rhs.value; }
    // this是个指针，所以即使是类内操作，也要->箭头

    // 重载加法运算符
    int operator+(const MyInt &rhs) { return this->value + rhs.value; }

public:
    MyInt() : value(0), broPtr(nullptr) {}
    MyInt(const MyInt &bro) : value(bro.getValue()), broPtr(&bro) {}
    MyInt(const int &value) : value(value), broPtr(nullptr) {}
    MyInt(const int &value, const MyInt &bro) : value(value), broPtr(&bro) {}
    ~MyInt() {}

    // 获取值
    int getValue()  const { return this->value; }
    /* 对于const对象，即使函数里没有修改值，调用另一个函数没有const，编译器也认为该函数会改变对象的值，
    所以我们尽量按照要求将所有的不需要改变对象内容的函数都作为 const 成员函数。*/
    
    // 设置值
    void setValue(const int &value) { this->value = value; }
    // 重载函数 支持对象传参设置值
    void setValue(const MyInt &obj) { this->value = obj.value; }
    void setValue(const MyInt *pobj)
    {
        if (pobj != nullptr)
        {
            this->value = pobj->value;
        }
    }

    // 获取兄弟指针 
    const MyInt* getBroPtr() const { return broPtr; }
    // 设置兄弟指针 （为了传参方便，设置为引用传递，这样就不需要添加&取地址符号
    void setBroPtr(const MyInt &bro) { this->broPtr = &bro; }

    // 链式编程 打印
    MyInt* printMyIntPlain();

private:
    const MyInt *broPtr;
    int value;
};

// // 打印value的函数 SP就是多一个空格
// void printMyInt(MyInt &obj)
// {
//     std::cout << obj.getValue();
// }
// append参数结尾附加字符

void printMyIntSP(const MyInt &obj)
{
    std::cout << obj.getValue() << "& ";
}
void printMyIntSP(const MyInt *obj)
{
    std::cout << obj->getValue() << "* ";
}
// 链式编程 打印 类外定义
MyInt* MyInt::printMyIntPlain()
{
    std::cout << this->value << "-";
    return this;
}

int main()
{
    MyInt myclass114(114); // value参构造函数 普通栈区创建
    MyInt *myclass514 = new MyInt(514, myclass114); // value &obj参构造函数 new堆区创建
    MyInt *myclass514_p = myclass514; // operator=运算符，只复制了地址，共同访问同一块myclass2
    MyInt *myclass_temp = new MyInt(810);

    printMyIntSP(myclass114); // 114
    printMyIntSP(myclass514); // 514 指针解引用，可以变成普通的obj对象
    myclass514_p->setValue(1919);
    printMyIntSP(myclass514); // 1919
    myclass514_p->setValue(myclass_temp); // set value to temp is 810
    printMyIntSP(*myclass514); // 810 跟上面的对比有了解引用* 就会调用const MyInt &obj的重载函数
    printMyIntSP(myclass514->getBroPtr()); // 测试返回兄弟关联对象指针
    // std::cout << myclass514->getBroPtr()->getValue() << " ";

    std::cout << std::endl << "--------------------" << std::endl;
    myclass514->printMyIntPlain()->printMyIntPlain(); // 链式编程

    delete myclass514_p;
    delete myclass_temp;

    return 0;
}
