#include <cstdio>

//定义了一个Box盒子类
class Box
{
    public:
        //构造函数
        Box(double len, double bre, double hei)
        {
          length = len;
          breadth = bre;
          height = hei;
        }

        double length;
        double breadth;  //这是宽
        double height;
        double get(void);
        void set(double len, double bre, double hei);
        
        void out(void)
        {
            printf("调用了成员函数_out_输出结果\n");
        }
};
//类外写函数体，用作用域运算符标识Box类
double Box::get(void)
{
    return length * breadth * height;
}

void Box::set(double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}

int main()
{
    using namespace std;
    double volume = 0;
    Box box1(2,3,4);
    volume = box1.get();
    printf("box1的体积是%f\n",volume);
    Box box2(4,5,6);
    printf("box2的体积是%f\n",box2.get());
    box2.out();
    return 0;
}