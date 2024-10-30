```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <atomic>
#include <functional>
#include <condition_variable>
#include <map>
#include <future>

using namespace std;

class ThreadPool {
public:
    ThreadPool(int min = 4, int max = thread::hardware_concurrency());
    ~ThreadPool();
    void addTask(function<void()> f);

private:
    void manager();
    void worker();
    
    thread* m_manager;
    map<thread::id, thread> m_workers; 
    vector<thread::id> m_ids; 
    int m_minThreads;
    int m_maxThreads; 
    atomic<bool> m_stop; 
    atomic<int> m_curThreads;
    atomic<int> m_idleThreads;
    atomic<int> m_exitNumber; 
    queue<function<void()>> m_tasks;
    mutex m_idsMutex; 
    mutex m_queueMutex;
    condition_variable m_condition;
};
```
// 大丙的代码 类声明分离