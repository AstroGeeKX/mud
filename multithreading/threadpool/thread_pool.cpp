#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool
{
public:
    ThreadPool(size_t threads) : stop(false)
    {
        for (size_t i = 0; i < threads; ++i)
        {
            workers.emplace_back(&ThreadPool::worker_thread, this);
        }
    }

    ~ThreadPool()
    {
        stop = true;
        cv.notify_all();
        for (std::thread &worker : workers)
        {
            worker.join();
        }
    }

    void submit(std::function<void()> task)
    {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            tasks.emplace(std::move(task));
        }
        cv.notify_one();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable cv;
    bool stop;

    void worker_thread()
    {
        while (true)
        {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(queue_mutex);
                cv.wait(lock, [this]
                        { return stop || !tasks.empty(); });
                if (stop && tasks.empty())
                    return;
                task = std::move(tasks.front());
                tasks.pop();
            }
            task();
        }
    }
};

// Example usage
int main()
{
    ThreadPool pool(4);

    pool.submit([]()
                { std::cout << "Task 1 is running" << std::endl; });

    pool.submit([]()
                { std::cout << "Task 2 is running" << std::endl; });

    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}

// kimi AI