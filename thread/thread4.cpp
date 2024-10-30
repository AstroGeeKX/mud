// example for thread::joinable
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void mythread() 
{
  // do stuff...
}
 
int main() 
{
  std::thread foo(mythread);
  std::thread bar;

  std::cout << "Joinable after construction:\n" << std::boolalpha;
  std::cout << "foo: " << foo.joinable() << '\n';
  std::cout << "bar: " << bar.joinable() << '\n';

  if (foo.joinable()) foo.join();
  if (bar.joinable()) bar.join();

  std::cout << "Joinable after joining:\n" << std::boolalpha;
  std::cout << "foo: " << foo.joinable() << '\n';
  std::cout << "bar: " << bar.joinable() << '\n';

  return 0;
}

// 这是测试joinable()函数的例子
// 返回值是bool类型用于判断线程是否可join
// joinable的线程不能直接delete 必须join()或detach()才能销毁