#include <mutex>
#include <iostream>
#include <thread>

std::mutex mtx;

void worker_thread() {
  std::unique_lock<std::mutex> lock(mtx, std::try_to_lock); // 尝试获取锁
  if (lock.owns_lock()) {
    // 锁获取成功，执行需要锁的操作
    std::cout << "Thread acquired the lock!\n";
  } else {
    // 锁获取失败，执行其他操作
    std::cout << "Thread failed to acquire the lock.\n";
  }
}

int main() {
  std::thread t1(worker_thread);
  std::thread t2(worker_thread);

  t1.join();
  t2.join();

  return 0;
}

// genmi
// 使用 try_lock() 可以实现非阻塞式锁获取。
// 非阻塞式锁获取可以提高性能，避免死锁，但需要小心处理锁获取失败的情况。
// 务必确保在锁获取失败时有合理的应对策略，以保证程序的安全性。