#include <iostream>                // std::cout
#include <future>                // std::async, std::future
//#include <chrono>                // std::chrono::milliseconds 这里是多余的代码

// a non-optimized way of checking for prime numbers:
bool do_check_prime(int x) // 为了体现效果, 该函数故意没有优化.
{
    for (int i = 2; i < x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    // call function asynchronously:
    std::future < bool > fut = std::async(do_check_prime, 194232491);

    std::cout << "Checking...\n";
    fut.wait();

    std::cout << "\n194232491 ";
    if (fut.get()) // guaranteed to be ready (and not block) after wait returns
        std::cout << "is prime.\n";
    else
        std::cout << "is not prime.\n";

    return 0;
}

// wait不读取共享状态或异常，但阻塞当前线程，直到共享状态的标志变为ready
// 一旦共享状态的标志变为ready wait()函数返回，当前线程被解除阻塞

// 194232491这个数字足够大 能有显著的阻塞运算的效果