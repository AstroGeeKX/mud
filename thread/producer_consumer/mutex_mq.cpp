#include <mutex>
#include <queue>
#include <thread>
#include <iostream>

std::mutex mutex_;
std::queue<int> queue_;
std::condition_variable cond_;

void producer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(i);
        cond_.notify_one();
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mutex_);
        while (queue_.empty()) {
            cond_.wait(lock);
        }
        int value = queue_.front();
        queue_.pop();
        std::cout << "Consumed: " << value << std::endl;
    }
}

int main() {
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}

// 一个使用生产者-消费者模式的简单 C++ 代码示例
// 使用队列来控制互斥量以实现信号量效果
// 我不知道这是从哪里抄来的代码，是比较错误的一个示范
// 生产者不是无限循环，就很有问题
