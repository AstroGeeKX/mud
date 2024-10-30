#if 0
//这里是简单测试动态内存分配一个变量的示例
#include <iostream>
using namespace std;
 
int main ()
{
   double* pvalue  = NULL; // 初始化为 null 的指针
   //pvalue  = new double;   // 为变量请求内存
   // 增加判断内存是否申请成功
   if (! (pvalue = new double))
   {
      cout << "Error: out of memory" << endl;
      return 0;
   }

   *pvalue = 29494.99;     // 在分配的地址存储值
   cout << "Value of pvalue : " << *pvalue << endl;
 
   delete pvalue;         // 释放内存
 
   return 0;
}
#endif


#if 0
// 这里是创建二维动态内存 并使用示例
#include <iostream>
using namespace std;
 
int main()
{
    int **p;  // 二维数组故有两个*号
    int i,j;   //p[4][8] 
    //开始分配4行8列的二维数据   
    p = new int *[4];  // 申请空间的时候一个最近的一个*号退化成中括号[]
    for(i=0;i<4;i++){
        p[i]=new int [8];
    }
   
   // 赋值
    for(i=0; i<4; i++){
        for(j=0; j<8; j++){
            p[i][j] = j*i;
        }
    }   

    //打印数据   
    for(i=0; i<4; i++){
        for(j=0; j<8; j++)     
        {   
            if(j==0) cout<<endl;   
            cout<<p[i][j]<<"\t";   
        }
    }   

    //开始释放申请的堆   
    for(i=0; i<4; i++){
        delete [] p[i];   
    }
    
    delete [] p;   
    return 0;
}
#endif


// 创建动态对象实例
#include <iostream>
using namespace std;
 
class Box
{
   public:
      Box() { 
         cout << "调用构造函数!" <<endl; 
      }
      ~Box() { 
         cout << "调用析构函数!" <<endl; 
      }
};
 
int main( )
{
   Box* myBoxArray = new Box[4];
   cout << "下面执行delete删除" << endl;
   delete [] myBoxArray; // 删除数组
   return 0;
}