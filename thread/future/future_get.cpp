// future::get
#include <iostream>       // std::cout, std::ios
#include <future>         // std::async, std::future
#include <exception>      // std::exception

int get_int() {
  std::cin.exceptions (std::ios::failbit);   // throw on failbit set
  int x;
  std::cin >> x;                             // sets failbit if invalid
  return x;
}

int main ()
{
  std::future<int> fut = std::async (get_int);

  std::cout << "Please, enter an integer value: ";

  try {
    int x = fut.get();
    std::cout << "You entered: " << x << '\n';
  }
  catch (std::exception&) {
    std::cout << "[exception caught]";
  }

  return 0;
}

// https://cplusplus.com/reference/future/future/get/
// 这个示例主要说明future类里get成员函数的使用
// get会阻塞到成功ready为止 如果fut对象为invalid为非定义行为

// if(fut.valid() == false) return; else fut.get();