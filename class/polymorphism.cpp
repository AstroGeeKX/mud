#include <iostream> 
using namespace std;

class Shape
{
public:
   int width;
   int height;
public:
   Shape(int a = 0, int b = 0) : width(a), height(b) {}

   const char* msg()
   {
      return "the shape area: ";
   }

   // 应该把这里声明为虚函数才能实现多态 virtual
   virtual int area()
   {
      cout << "Parent class area :" << endl;
      return 0;
   }
};

// Rectangle类继承Shape类
class Rectangle : public Shape
{
public:
   Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
   int area()
   {
      return (width * height);
   }
};

// Triangle类继承Shape类
class Triangle : public Shape
{
public:
   Triangle(int a = 0, int b = 0) : Shape(a, b) {}
   int area()
   {
      return (width * height / 2);
   }
};
// 程序的主函数
int main( )
{
   Shape *shape; // 基类指针可以指向子类对象
   Rectangle rect(10,5);
   Triangle  tri(10,5);
 
   // 存储矩形的地址
   // 调用矩形的求面积函数 area
   shape = &rect;
   std::cout << shape->msg(); // 基类的msg()
   std::cout << shape->area() << std::endl; // 子类Rectangle的area()函数重载
 
   // 存储三角形的地址
   // 调用三角形的求面积函数 area
   shape = &tri;
   std::cout << shape->msg(); // 基类的msg()
   std::cout << shape->area() << std::endl; // 子类Triangle的area()函数重载
   // cout的执行顺序有点迷惑，首先入栈运行函数，然后再cout返回值
   // 也就是说如果函数里有打印的话，先于打印返回值之前打印，返回值后打印   
   return 0;
}

// 多态的基本意思是，继承基类创建子类，子类可以复写基类的函数，名称相同的函数，不同的实现
// 基类指针指向子类对象，调用子类成员函数时，优先调用子类重载的函数，如果子类没有重载，就使用基类的函数
