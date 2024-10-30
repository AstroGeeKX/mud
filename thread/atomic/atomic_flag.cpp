#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
 
std::atomic_flag lock = ATOMIC_FLAG_INIT;
 
void f(int n)
{
    for (int cnt = 0; cnt < 100; ++cnt) {
        while (lock.test_and_set(std::memory_order_acquire))  // 获得锁
             ; // 自旋
        std::cout << "Output from thread " << n << '\n';
        lock.clear(std::memory_order_release);               // 释放锁
    }
}
 
int main()
{
    std::vector<std::thread> v;
    for (int n = 0; n < 10; ++n) {
        v.emplace_back(f  , n);
    }
    for (auto& t : v) {
        t.join();
    }
}

// 简单地介绍了自旋锁
// atomic_flag对象是true时while保持自旋 即一直循环
// false时就可以执行下面的语句了 读取到false和重新设置回true是同一时刻test_and_set
// 程序逻辑是保证线程一个一个来运行 比较简单 不需要耗费太多注意力在其他内容上

// 仅仅比普通的示例程序多了memory_order的使用