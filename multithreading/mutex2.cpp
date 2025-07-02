#include <mutex>
#include <thread>
#include <iostream>
#include <atomic>

// 普通Counter类定义开始
class Counter {
public:
    void increment() {
        count_++;
    }

    int get_count() {
        return count_;
    }

private:
    int count_ = 0; // 类内的count_计数变量
};
// 普通Counter类定义结束

// Counter类定义开始
class mutexCounter {
public:
    void increment() {
        std::lock_guard<std::mutex> lock(mutex_);
        count_++;
    }

    int get_count() {
        return count_;
    }

private:
    std::mutex mutex_; // 类内的互斥量对象
    int count_ = 0; // 类内的count_计数变量
};
// Counter类定义结束

// atomicCounter类定义开始
class atomicCounter {
public:
    void increment() {
        count_.fetch_add(1, std::memory_order_relaxed); // 没有mutex用的是原子变量操作
    }

    int get_count() {
        return count_.load(); // 原子变量读取load()
    }

private:
    std::atomic<int> count_ = 0; // 原子变量创建
};
// atomicCounter类定义结束
// 用原子变量同样可以保证数据线程安全


int main() {
    // mutexCounter counter; // 实例化计数对象
    Counter counter; // 实例化计数对象
    // atomicCounter counter;
    std::thread thread1([&counter]() {
        for (int i = 0; i < 100000; ++i) {
            counter.increment();
        }
    });

    std::thread thread2([&counter]() {
        for (int i = 0; i < 100000; ++i) {
            counter.increment();
        }
    });

    thread1.join();
    thread2.join();

    std::cout << "Count: " << counter.get_count() << std::endl;
    return 0;
}

// 代码示例 (使用互斥量保护共享数据)
// mutex的直接用法
// 不用互斥锁会导致线程资源竞争、代码重排序等问题，使数据结果不确定不正确

// 这里两个线程共增加了2000次计数，如果没有锁，那么会重复修改浪费损失次数、
// 坏处是性能降低

// 整体的思路是，加mutex互斥量lock锁上之后 内存竞争时其中一个线程会保持数据
// 使其他线程阻塞，类似物理上延迟时间设置数据，达到数据稳定的作用
