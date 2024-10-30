class Empty 
{   public:
    Empty();                            //缺省构造函数
    Empty(const Empty &rhs);            //拷贝构造函数
    ~Empty();                           //析构函数 
    Empty& operator=(const Empty &rhs); //赋值运算符
    Empty* operator&();                 //取址运算符
    const Empty* operator&() const;     //取址运算符(const版本) 
};

// 空类，声明时编译器不会生成任何成员函数,只会生成1个字节的占位符.
// 空类在定义时会生成6个成员函数.

// C++编译器对这些函数的实现
inline Empty::Empty()                          //缺省构造函数
{
}
inline Empty::~Empty()                         //析构函数
{
}
inline Empty *Empty::operator&()               //取址运算符(非const)
{
 return this; 
}           
inline const Empty *Empty::operator&() const    //取址运算符(const)
{
 return this;
}
inline Empty::Empty(const Empty &rhs)           //拷贝构造函数
{
 //对类的非静态数据成员进行以"成员为单位"逐一拷贝构造
 //固定类型的对象拷贝构造是从源对象到目标对象的"逐位"拷贝
}
inline Empty& Empty::operator=(const Empty &rhs) //赋值运算符
{
 //对类的非静态数据成员进行以"成员为单位"逐一赋值
 //固定类型的对象赋值是从源对象到目标对象的"逐位"赋值。
}

// 阿里云的笔记