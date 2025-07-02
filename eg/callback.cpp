#include<stdio.h>

int Callback_1(int x)  // Callback Function 1
{
    printf("Hello, this is Callback_1: x = %d\n", x);
    return 0;
}

int Callback_2(int x)  // Callback Function 2
{
    printf("Hello, this is Callback_2: x = %d\n", x);
    return 0;
}

int Callback_3(int x)  // Callback Function 3
{
    printf("Hello, this is Callback_3: x = %d\n", x);
    return 0;
}

int Callback_4(int x, double y)  // Callback Function 4
{
    printf("Hello, this is Callback_3: x = %d\n", x);
    return 0;
}

/*
 * 原始example的处理函数，y参数提供回调函数调用时的参数
 * 回调函数返回值在本示例程序中无意义，但要保证函数指针与回调函数的原型完全一致
*/
void Handle(int y, int (*Callback)(int))
{
    Callback(y);
}

/*
 * 为了避免混淆，简化代码表达，形参只传递函数指针，是一个指针
 * 函数指针名加()括号代表调用回调函数，参数由调用时填写的实参决定
 * 上面写法只是一般应用逻辑，并不是必须同时以形参传入
*/
void myHandle(int (*Callback)(int))
{
    int y = 1145141919;
    Callback(y);
}

struct Suff
{
    int i = 10;
    double d = 9.11;
    char c = 'A';
};

// 测试结构体中以函数指针成员存储并调用回调函数
// 可以预留arg成员，提供函数调用时的参数
// 当然，也可以随便安排一个变量作为参数
struct MyStruct
{
    int (*caller)(int x) = nullptr;  // 这是函数指针，用于存储回调函数的地址
    int arg = 114514;  // 参数1
    int data = 0;      // 参数2
    Suff *m_suff;      // 参数3（结构体指针/变量）
};

// 牢记指针解引用*之后就是变量的优越思维，忽略指针是个地址的空洞思维

int main()
{
    int (*caller)(int x);  // 函数签名/函数原型是int (int)
    int (*caller2)(int x, double y);  // Callback_4适配的函数指针

    int a = 114;
    int b = 514;
    int c = 19;

    Suff *suff = new Suff;
    MyStruct *myStruct = new MyStruct;  // new MyStruct是一个资源，myStruct不再空洞
    myStruct->m_suff = suff;            // suff对象赋值
    myStruct->caller = Callback_1;      // 绑定回调函数

    // myStruct             (MyStruct*)
    // myStruct->m_suff     (Suff*)
    // myStruct->m_suff->i  (int)
    myStruct->caller(myStruct->m_suff->i);  // 调用回调函数

    printf("sizeof(MyStruct) is: %d\n", sizeof(MyStruct));  // 查看内存对齐情况
    
    // Callback_1/2/3原型  int (int)
    // Callback_4原型      int (int, double)
    
    // 函数指针手动赋值绑定再调用
    // caller = Callback_1;
    // caller(c);
    // caller2 = Callback_4;  // 先绑定
    // caller2(a, b);         // 再调用

    // 函数指针作为函数参数，回调函数地址传递进入函数，在内部调用
    // myHandle(Callback_1);
    // Handle(a, Callback_1);

    return 0;
}

// 函数指针原型和回调函数原型必须一致

// C++中，貌似non-class type叫变量，class type叫对象？？
