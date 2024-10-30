#include <iostream>
using namespace std;

// 继承示例代码 菜鸟教程

// 基类
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};
 
// 派生类
class Rectangle: public Shape
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};

// 自己练习一个派生类
class Circle: public Shape
{
   public:
      int getArea()
      {
         return width * width * 3;
      }
};
 
int main(void)
{
   Rectangle Rect;
   Rect.setWidth(5);
   Rect.setHeight(7);
   
   Circle Circ;
   Circ.setWidth(5);

   // 输出对象的面积
   cout << "Rectangle area: " << Rect.getArea() << endl;
   cout << "Circle area: " << Circ.getArea() << endl;
 
   return 0;
}