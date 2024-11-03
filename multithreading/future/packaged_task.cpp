// packaged_task example
#include <iostream>     // std::cout
#include <future>       // std::packaged_task, std::future
#include <chrono>       // std::chrono::seconds
#include <thread>       // std::thread, std::this_thread::sleep_for

// count down taking a second for each value:
int countdown (int from, int to) {
  for (int i = from; i != to; --i) {
    std::cout << i << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 延迟1秒
  }
  std::cout << "Lift off!\n";
  return from - to;
}

int main ()
{
  std::packaged_task<int(int,int)> tsk (countdown);   // set up packaged_task
  std::future<int> ret = tsk.get_future();            // get future
  // auto ret = tsk.get_future(); // 也行
  std::thread th (std::move(tsk),10,0);   // spawn thread to count down from 10 to 0

  // ...

  int value = ret.get();                  // wait for the task to finish and get result

  std::cout << "The countdown lasted for " << value << " seconds.\n";

  th.join();

  return 0;
}

// https://cplusplus.com/reference/future/packaged_task/
// 关于packaged_task类的实例代码 将可调用对象打包传递给future对象以便在其他线程中调用
// 异步任务 和 结果管理 机制实现共享结果
// 可以用来解决比如性能问题
// packaged_task采用原子操作和同步机制保证线程安全 相比直接使用函数指针更安全

// join是一种机制，阻塞主线程等待此线程，还有异常处理等
// get()实际上是会隐式调用