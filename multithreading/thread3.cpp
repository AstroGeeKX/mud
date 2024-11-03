#include <stdio.h>
#include <stdlib.h>

#include <chrono>    // std::chrono::seconds
#include <iostream>  // std::cout
#include <thread>    // std::thread, std::this_thread::sleep_for

void thread_task(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout 
        << "hello thread "
        << std::this_thread::get_id()
        << " paused " << n << " seconds" << std::endl;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::thread threads[5];
    std::cout << "Spawning 5 threads...\n";
    // 
    for (int i = 0; i < 5; i++) {
        threads[i] = std::thread(thread_task, i + 1); // 真正意义能看懂的构造函数
    }
    // 用对象数组存储各个thread 省得写th1、th2、th3、th4。。。
    std::cout << "Done spawning threads! Now wait for them to join\n";
    for (auto& t: threads) {
        t.join();
    }
    std::cout << "All threads joined.\n";

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */

// 这是测试多个线程同时运行的程序
// 每个线程多增1秒延迟

// 这个程序实际上是测试move赋值操作的 operator=