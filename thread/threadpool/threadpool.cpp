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

// 线程池类
class ThreadPool
{
public:
    ThreadPool(int min = 4, int max = thread::hardware_concurrency());
    ~ThreadPool();
    void addTask(function<void()> f);

private:
    void manager();
    void worker();
private:
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


ThreadPool::ThreadPool(int min, int max) : m_maxThreads(max),
m_minThreads(min), m_stop(false), m_exitNumber(0)
{
    //m_idleThreads = m_curThreads = max / 2;
    m_idleThreads = m_curThreads = min;
    cout << "线程数量: " << m_curThreads << endl;
    m_manager = new thread(&ThreadPool::manager, this);
    for (int i = 0; i < m_curThreads; ++i)
    {
        thread t(&ThreadPool::worker, this);
        m_workers.insert(make_pair(t.get_id(), move(t)));
    }
}

ThreadPool::~ThreadPool()
{
    m_stop = true;
    m_condition.notify_all();
    for (auto& it : m_workers)
    {
        thread& t = it.second;
        if (t.joinable())
        {
            cout << "******** 线程 " << t.get_id() << " 将要退出了..." << endl;
            t.join();
        }
    }
    if (m_manager->joinable())
    {
        m_manager->join();
    }
    delete m_manager;
}

void ThreadPool::addTask(function<void()> f)
{
    {
        lock_guard<mutex> locker(m_queueMutex);
        m_tasks.emplace(f);
    }
    m_condition.notify_one();
}

void ThreadPool::manager()
{
    while (!m_stop.load())
    {
        this_thread::sleep_for(chrono::seconds(2));
        int idle = m_idleThreads.load();
        int current = m_curThreads.load();
        if (idle > current / 2 && current > m_minThreads)
        {
            m_exitNumber.store(2);
            m_condition.notify_all();
            unique_lock<mutex> lck(m_idsMutex);
            for (const auto& id : m_ids)
            {
                auto it = m_workers.find(id);
                if (it != m_workers.end())
                {
                    cout << "############## 线程 " << (*it).first << "被销毁了...." << endl;
                    (*it).second.join();
                    m_workers.erase(it);
                }
            }
            m_ids.clear();
        }
        else if (idle == 0 && current < m_maxThreads)
        {
            thread t(&ThreadPool::worker, this);
            cout << "+++++++++++++++ 添加了一个线程, id: " << t.get_id() << endl;
            m_workers.insert(make_pair(t.get_id(), move(t)));
            m_curThreads++;
            m_idleThreads++;
        }
    }
}

void ThreadPool::worker()
{
    while (!m_stop.load())
    {
        function<void()> task = nullptr;
        {
            unique_lock<mutex> locker(m_queueMutex);
            while (!m_stop && m_tasks.empty())
            {
                m_condition.wait(locker);
                if (m_exitNumber.load() > 0)
                {
                    cout << "----------------- 线程任务结束, ID: " << this_thread::get_id() << endl;
                    m_exitNumber--;
                    m_curThreads--;
                    unique_lock<mutex> lck(m_idsMutex);
                    m_ids.emplace_back(this_thread::get_id());
                    return;
                }
            }

            if (!m_tasks.empty())
            {
                cout << "取出一个任务..." << endl;
                task = move(m_tasks.front());
                m_tasks.pop();
            }
        }

        if (task)
        {
            m_idleThreads--;
            task();
            m_idleThreads++;
        }
    }
}

void calc(int x, int y)
{
    int res = x + y;
    cout << "res = " << res << endl;
    this_thread::sleep_for(chrono::seconds(2));
}

int main()
{
    ThreadPool pool(4);
    for (int i = 0; i < 10; ++i)
    {
        auto func = bind(calc, i, i * 2);
        pool.addTask(func);
    }
    getchar();
    return 0;
}


// 作者: 苏丙榅
// 链接: https://subingwen.cn/cpp/threadpool/#2-1-%E5%A4%B4%E6%96%87%E4%BB%B6
// 来源: 爱编程的大丙
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。