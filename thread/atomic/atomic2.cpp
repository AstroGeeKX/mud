#include <iostream>                // std::cout
#include <atomic>                // std::atomic_flag
#include <thread>                // std::thread
#include <vector>                // std::vector
//#include <sstream>                // std::stringstream

std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;
//std::stringstream stream; // 直接用cout就好，其他成分容易影响阅读力较弱的学者的注意力

void append_number(int x)
{
    while (lock_stream.test_and_set())
        ; // 为真进入自旋状态
    std::cout << "thread #" << x << '\n'; // 在跳出自旋之后执行的语句
    lock_stream.clear(); // 清除标记变为false （是否还记得lock_stream是atomic_flag类型？
}

int main()
{
    std::vector <std::thread> threads;
    for (int i = 1; i <= 10; ++i)
        threads.push_back(std::thread(append_number  , i));
    for (std::thread& th : threads)
        th.join();

    //std::cout << stream.str() << std::endl;;
    return 0;
}

// 这个程序只是简单地使用了原子操作 演示了自旋锁的示范
// 只是语法上可以简单看一下 逻辑上并没有让读者感受到原子性
// while (lock_stream.test_and_set()) true将会导致自旋不能进行下一步操作
// lock_stream.clear() 则会使其变为false，能使随机下一个线程脱离while{}的束缚

// 相当于锁和解锁，保证while{}后clear()前的代码只能有一个线程在执行