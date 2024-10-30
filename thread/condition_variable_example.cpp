// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

std::mutex printIdMutex;        // 互斥量，用于同步打印线程
std::condition_variable dataReadyCondition; // 条件变量，用于等待数据准备就绪
bool dataReady = false;        // 数据准备状态

void print_id(int id) {
  std::unique_lock<std::mutex> lck(printIdMutex);
  while (!dataReady) {
    dataReadyCondition.wait(lck);
  }
  // ...
  std::cout << "thread " << id << '\n';
}

void go() {
  std::unique_lock<std::mutex> lck(printIdMutex);
  dataReady = true;
  dataReadyCondition.notify_all();
}

int main() {
  std::thread threads[10];
  // spawn 10 threads:
  for (int i = 0; i < 10; ++i) {
    threads[i] = std::thread(print_id, i);
  }

  std::cout << "10 threads ready to race...\n";
  go();                       // go!

  for (auto& th : threads) {
    th.join();
  }

  return 0;
}

// 用genmi把一些变量名换成更具体的名称 方便阅读
// 注意： 线程执行的顺序可能不同，导致无法正确输出
// 应该保证在 wait() 之后调用 notify_all() 或 notify_one()