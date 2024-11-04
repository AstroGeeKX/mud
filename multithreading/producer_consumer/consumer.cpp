#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> queue;
std::mutex mtx;
std::condition_variable cv;
const int queue_limit = 10;

// 生产者线程
void producer() {
    int count = 0;
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return queue.size() < queue_limit; }); // 条件为假等待 反直觉

        // 生产数据
        queue.push(count++);
        std::cout << "Produced: " << count - 1 << std::endl;

        // 通知消费者队列已更新
        cv.notify_one();
    }
}

// 消费者线程
void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !queue.empty(); });

        // 消费数据
        int value = queue.front();
        queue.pop();
        std::cout << "  Consumed: " << value << std::endl;

        // 通知生产者队列已更新
        cv.notify_one();
    }
}

int main() {
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    // 等待线程结束
    producer_thread.join();
    consumer_thread.join();

    return 0;
}

// 天工AI 生产者消费者模型