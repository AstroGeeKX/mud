#include <iostream> // std::cout
#include <thread>   // std::thread

void my_func(void) {
    std::cout << "hello thread" << std::endl;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main()
{
    std::thread th1(my_func);
    th1.join();

    return 0;
}  /* ----------  end of function main  ---------- */

// 超级简单的多线程用法 虽然只有一个线程join