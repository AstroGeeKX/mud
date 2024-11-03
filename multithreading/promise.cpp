#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future

void print_int(std::future<int>& fut) {
    int x = fut.get(); // 获取共享状态的值.
    std::cout << "value: " << x << '\n'; // 打印 value: 10.
}

int main ()
{
    std::promise<int> prom; // 生成一个 std::promise<int> 对象.
    std::future<int> fut; // 顺序：先关联 传递 后设值
    fut = prom.get_future(); // 和 future 关联.
    std::thread t(print_int, std::ref(fut)); // 将 future 交给另外一个线程t.
    prom.set_value(10); // 设置共享状态的值, 此处和线程t保持同步.
    t.join();

    prom = std::promise<int>();    // prom 被move赋值为一个新的 promise 对象.
    // 这里是测试operator=的move功能，标准是不能复制，只能move
    std::thread t2(print_int, std::ref(fut));
    fut = prom.get_future(); // 注意，新的promise对象还没有与fut关联
    prom.set_value(20);
    t2.join();
    return 0;
}


//https://www.cnblogs.com/haippy/p/3239248.html

// promise 和 future 的核心目的就是为了解决异步编程中的数据传递问题

// 异步执行: 线程 A 和线程 B 可以同时执行，线程 B 不需要等待线程 A 完成下载。
// 数据传递: promise 和 future 提供了一种安全的机制来传递线程间的数据。
// 线程安全: promise 和 future 的设计确保了数据传递的线程安全。