// future::share
#include <iostream>       // std::cout
#include <future>         // std::async, std::future, std::shared_future

int get_value() { return 10; }

int main ()
{
  std::future<int> fut = std::async(get_value);
  std::shared_future<int> shfut = fut.share();  // 这里调用share()

  // shared futures can be accessed multiple times:
  std::cout << "value: " << shfut.get() << '\n';
  std::cout << "its double: " << shfut.get()*2 << '\n';

  return 0;
}

// https://cplusplus.com/reference/future/future/share/
// share_future的简单实例用 get()*2 法来示范多重调用
// future对象只能一个get或wait就变为invaild状态 但是share_future可以多次调用
// 内部的线程安全机制更丰富了，以支持多个线程使用同一个共享状态