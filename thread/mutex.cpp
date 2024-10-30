// mutex example
#include <iostream> // std::cout
#include <thread>   // std::thread
#include <mutex>    // std::mutex

std::mutex mtx; // mutex for critical section // 全局变量mtx

void print_block(int n, char c)
{
  // critical section (exclusive access to std::cout signaled by locking mtx):
  mtx.lock(); // lock()并不是那两个lock模板类的特有的成员函数 本质上锁的是mutex对象
  for (int i = 0; i != n; ++i)
  {
    std::cout << c;
  }
  std::cout << '\n';
  mtx.unlock(); // 手动解锁
}

void eprint_block(char c, int n)
{
  // 这颠倒了参数列表，没有mutex互斥量和锁
  for (int i = 0; i != n; ++i)
  {
    std::cout << c;
  }
  std::cout << '\n';
}

int main()
{
  // std::thread th1(print_block, 50, '!');
  // std::thread th2(print_block, 50, '@');
  
  std::thread th3(eprint_block, '*', 50);
  std::thread th4(eprint_block, '$', 50);

  // th1.join();
  // th2.join();
  th3.join();
  th4.join();

  return 0;
}
// cplus官网的mutex使用范例

// 魔改了一些内容