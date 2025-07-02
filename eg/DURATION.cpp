// 计算if语句耗时的示例
#include <iostream>
#include <chrono>

using namespace std;

// 宏定义了START和END，也可以直接使用
#define START auto start = chrono::high_resolution_clock::now()
#define END auto end = chrono::high_resolution_clock::now()
#define DURATION auto duration = chrono::duration_cast<chrono::microseconds>(end - start)

// 二次计时的时候用下面的版本，多了个下划线_
#define START_ start = chrono::high_resolution_clock::now()
#define END_ end = chrono::high_resolution_clock::now()
#define DURATION_ duration = chrono::duration_cast<chrono::microseconds>(end - start)


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


/*  2025-6-4 随便复制粘贴的，还是上面的好用

#include <chrono>
#include <iostream>

int main() {
auto start = std::chrono::system_clock::now();
// 执行一些操作
auto end = std::chrono::system_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
std::cout << "花费了" << double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den << "秒" << std::endl;
return 0;
}

*/