// 计算if语句耗时的示例
#include <iostream>
#include <chrono>

using namespace std;

// 宏定义了START和END，也可以直接使用
#define START auto start = chrono::high_resolution_clock::now()
#define END auto end = chrono::high_resolution_clock::now()
#define DURATION auto duration = chrono::duration_cast<chrono::microseconds>(end - start)

void func()
{
  for (int i = 0; i < 10000000; i++)
  {
    if (i % 2 == 0)
    {
      // 执行一些操作
      d += 3.14;
    }
  }
}

int main()
{
  START; // 开始
  func();
  END; // 结束

  DURATION; // 计算耗时 创建变量duration

  // 输出结果
  cout << "compare 10000000 times spend:" << duration.count() << " us" << endl;

  return 0;
}
