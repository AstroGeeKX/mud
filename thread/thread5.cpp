        #if 0

#include <thread>
#include <atomic>
#include <iostream>

std::atomic<bool> should_execute{true};

void thread_function() {
    if (should_execute) {
        // 执行需要执行的代码
        std::cout << "线程被执行了" << std::endl;
    }
}

int main() {
    std::thread t(thread_function);
    
    // 决定是否要执行代码
    should_execute = true;
    
    // 等待线程完成
    t.join();

    // ...
    return 0;
}
// 使用 std::atomic<bool> 标记线程是否应该执行

        #endif


#include <thread>
#include <condition_variable>
#include <mutex>
#include <iostream>

std::mutex m;
std::condition_variable cv;
bool should_execute = false;

void thread_function() {
    std::unique_lock<std::mutex> lock(m);
    // 在等待前先检查 should_execute
    if (!should_execute) {
        return; // 如果 should_execute 为 false，则直接退出
    }
    //cv.wait(lock); // 等待通知，但只会执行一次
    
    // 执行需要执行的代码
    std::cout << "conditon_variable" << std::endl;
}

int main() {
    std::thread t(thread_function);
    
    // 决定是否要执行代码
    // {
    //     std::lock_guard<std::mutex> lock(m);
    //     should_execute = true;
    // }
    
    // 通知线程可以继续执行，但由于 should_execute 已经为 false，
    // 线程会在检查条件后直接退出
    
    // 等待线程完成
    t.join();

    //cv.notify_one();
    // ...
    return 0;
}

// 使用 std::condition_variable 和 std::mutex 进行条件变量等待

// 假如创建了线程但是不想执行代码 又必须join()或detach() 的例子