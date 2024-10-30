#if 0
#include <iostream>
// 打印任意类型的值 ai
template <typename T>
void print(const T& value) {
  std::cout << value << std::endl;
}

int main() {
  print<int>(10);  // 调用模板函数，传入 int 类型的值
  print<const char*>("Hello");  // 调用模板函数，传入 string 类型的值
}
#endif


#if 0
#include <iostream>
// 比较两个值 ai
template <typename T>
bool compare(const T& a, const T& b) {
  return a == b;
}

int main() {
  std::cout << compare(10, 15) << std::endl;  // 比较两个 int
  std::cout << compare("Hello", "World") << std::endl;  // 比较两个 string
}
#endif


// 菜鸟教程 返回两个数中的最大值
#include <iostream>
#include <string>
 
using namespace std;
 
template <typename T>
inline T const& Max (T const& a, T const& b) 
{ 
    return a < b ? b:a; 
}
// T const& Max 这个函数返回值涉及的知识有点难以理解
int main ()
{
 
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl; 
 
    double f1 = 13.5; 
    double f2 = 20.7; 
    cout << "Max(f1, f2): " << Max(f1, f2) << endl; 
 
    string s1 = "Hello"; 
    string s2 = "World"; 
    cout << "Max(s1, s2): " << Max(s1, s2) << endl; 
 
    return 0;
}

/*
模板函数定义的一般形式如下所示：
template <typename type> ret-type func-name(parameter list)
{
   // 函数的主体
}

但一般这样换行写
template <typename type>
ret-type func-name(parameter list)
{
   // 函数的主体
}
*/