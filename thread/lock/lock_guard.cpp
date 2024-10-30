#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard, std::adopt_lock

std::mutex mtx;           // mutex for critical section

void print_thread_id (int id) {
  mtx.lock();
  std::lock_guard<std::mutex> lck(mtx,std::adopt_lock);
  std::cout << "thread #" << id << '\n';
}

int main ()
{
  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = std::thread(print_thread_id,i+1);

  for (auto& th : threads) th.join();

  return 0;
}

// 简单的lock_guard示例代码

// 使用std::adopt_lock非阻塞地获取锁的所有权
// 核心在于使用原子操作来确数据安全
// CAS操作 自旋锁