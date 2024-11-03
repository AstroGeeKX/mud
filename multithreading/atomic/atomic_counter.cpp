#include <iostream>
#include <atomic>
#include <thread>

std::atomic<int> counter(0); // 初始化为0

void increment_counter() {
  for (int i = 0; i < 1000; ++i) {
    counter.fetch_add(1, std::memory_order_relaxed); // 使用relaxed内存序
  }
}

int main() {
  std::thread thread1(increment_counter);
  std::thread thread2(increment_counter);

  thread1.join();
  thread2.join();

  std::cout << "Final counter value: " << counter.load() << std::endl;
  return 0;
}
