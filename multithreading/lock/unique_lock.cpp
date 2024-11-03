/*std::unique_lock 主要成员函数
本节我们来看看 std::unique_lock 的主要成员函数。由于 std::unique_lock 比 std::lock_guard 操作灵活，因此它提供了更多成员函数。具体分类如下：
上锁/解锁操作：lock，try_lock，try_lock_for，try_lock_until 和 unlock
修改操作：移动赋值(move assignment)(前面已经介绍过了)，交换(swap)（与另一个 std::unique_lock 对象交换它们所管理的 Mutex 对象的所有权），释放(release)（返回指向它所管理的 Mutex 对象的指针，并释放所有权）
获取属性操作：owns_lock（返回当前 std::unique_lock 对象是否获得了锁）、operator bool()（与 owns_lock 功能相同，返回当前 std::unique_lock 对象是否获得了锁）、mutex（返回当前 std::unique_lock 对象所管理的 Mutex 对象的指针）。*/

        #if 0
#include <iostream> // std::cout
#include <thread>   // std::thread
#include <mutex>    // std::mutex, std::lock, std::unique_lock
                    // std::adopt_lock, std::defer_lock
std::mutex foo,bar;

void task_a () {
  std::lock (foo,bar);         // simultaneous lock (prevents deadlock)
  std::unique_lock<std::mutex> lck1 (foo,std::adopt_lock);
  std::unique_lock<std::mutex> lck2 (bar,std::adopt_lock);
  std::cout << "task a\n";
  // (unlocked automatically on destruction of lck1 and lck2)
}

void task_b () {
  // foo.lock(); bar.lock(); // replaced by:
  std::unique_lock<std::mutex> lck1, lck2;
  lck1 = std::unique_lock<std::mutex>(bar,std::defer_lock);
  lck2 = std::unique_lock<std::mutex>(foo,std::defer_lock);
  std::lock (lck1,lck2);       // simultaneous lock (prevents deadlock)
  std::cout << "task b\n";
  // (unlocked automatically on destruction of lck1 and lck2)
}


int main ()
{
  std::thread th1 (task_a);
  std::thread th2 (task_b);

  th1.join();
  th2.join();

  return 0;
}
        #endif
// unique_lock 示例代码
// 默认构造函数  unique_lock() noexcept;
// 移动复制操作  unique_lock& operator= (unique_lock&& x) noexcept;
// 收养构造函数  adopting (5)	unique_lock(mutex_type& m, adopt_lock_t tag);


        #if 0
#include <iostream> // std::cout
#include <thread>   // std::thread
#include <mutex>    // std::mutex, std::unique_lock

std::mutex mtx; // mutex for critical section

void print_fifty(char c)
{
  std::unique_lock<std::mutex> lck;        // default-constructed
  lck = std::unique_lock<std::mutex>(mtx); // move-assigned
  for (int i = 0; i < 50; ++i)
  {
    std::cout << c;
  }
  std::cout << '\n';
}

int main()
{
  std::thread th1(print_fifty, '*');
  std::thread th2(print_fifty, '$');

  th1.join();
  th2.join();

  return 0;
}
        #endif
// unique_lock 示例代码
// 博客园 C++11 并发指南三(Lock 详解)
// 默认构造函数和移动赋值操作简单示例


        #if 0
#include <iostream>       // std::cout
#include <vector>         // std::vector
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock, std::defer_lock

std::mutex mtx;           // mutex for critical section

void print_star () {
  std::unique_lock<std::mutex> lck(mtx,std::defer_lock);
  // print '*' if successfully locked, 'x' otherwise: 
  if (lck.try_lock()) // 返回lck对象是否已经上锁 这里因为defer_lock的原因没有上锁
    std::cout << '*';
  else                    
    std::cout << 'x';
}

int main ()
{
  std::vector<std::thread> threads;
  for (int i=0; i<500; ++i)
    threads.emplace_back(print_star);

  for (auto& x: threads) x.join();

  return 0;
}
        #endif
// try_lock 示例代码


        
#include <iostream>       // std::cout
#include <chrono>         // std::chrono::milliseconds
#include <thread>         // std::thread
#include <mutex>          // std::timed_mutex, std::unique_lock, std::defer_lock

std::timed_mutex mtx;

void fireworks (int i) {
  std::unique_lock<std::timed_mutex> lck(mtx,std::defer_lock);
  // waiting to get a lock: each thread prints "-" every 200ms:
  while (!lck.try_lock_for(std::chrono::milliseconds(200))) {
    std::cout << i;
  } // 每次判断的同时也会等待200ms 大概不能成功lock 循环为真 输出i
  // got a lock! - wait for 1s, then this thread prints "*"
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::cout << "*\n";
}

int main ()
{
  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = std::thread(fireworks, i);

  for (auto& th : threads) th.join();

  return 0;
}
        
// try_lock_for 示例代码
// 如果上锁成功，则返回 true，否则返回 false


        #if 0
// timed_mutex::try_lock_until example
#include <iostream>       // std::cout
#include <chrono>         // std::chrono::system_clock
#include <thread>         // std::thread
#include <mutex>          // std::timed_mutex
#include <ctime>          // std::time_t, std::tm, std::localtime, std::mktime

std::timed_mutex cinderella;

// gets time_point for next midnight:
std::chrono::time_point<std::chrono::system_clock> midnight() {
  using std::chrono::system_clock;
  std::time_t tt = system_clock::to_time_t (system_clock::now());
  struct std::tm * ptm = std::localtime(&tt);
  ++ptm->tm_mday; ptm->tm_hour=0; ptm->tm_min=0; ptm->tm_sec=0;
  return system_clock::from_time_t (mktime(ptm));
}

void carriage() {
  if (cinderella.try_lock_until(midnight())) {
    std::cout << "ride back home on carriage\n";
    cinderella.unlock();
  }
  else
    std::cout << "carriage reverts to pumpkin\n";
}

void ball() {
  cinderella.lock();
  std::cout << "at the ball...\n";
  cinderella.unlock();
}

int main ()
{
  std::thread th1 (ball);
  std::thread th2 (carriage);

  th1.join();
  th2.join();

  return 0;
}
        #endif
// try_lock_until 示例
// try_lock_until的示例代码比较长，有很多时间处理的函数，没怎么看懂

// 总结 std::unique_lock<std::mutex> 的构造函数
// std::unique_lock 的尖括号 <> 中的类型参数指定了要与 std::unique_lock 对象关联的互斥量类型。
// mutex_type 类型参数可以是任何满足要求的类型，例如 std::mutex 或自定义互斥量类型。
// 尖括号中的写法遵循 template <typename mutex_type> 语法，其中 mutex_type 是类型参数。
// mutex_type 本质上经历了一个 typedef 过程，使你可以将互斥量类型直接传递给尖括号。