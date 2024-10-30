#include <iostream> // std::cout
#include <future>   // std::async, std::future, std::shared_future

int do_get_value() { return 10; }

int main()
{
    std::future<int> fut = std::async(do_get_value);
    std::shared_future<int> shared_fut = fut.share();

    // 共享的 future 对象可以被多次访问.
    std::cout << "value: " << shared_fut.get() << '\n';
    std::cout << "its double: " << shared_fut.get() * 2 << '\n';
    std::cout << "now fut is valid? " << fut.valid() << std::endl;

    // 下面是gemini的示例代码 future和shared_future嵌套使用 并且多次调用get
    std::future<std::shared_future<int>> future = std::async(std::launch::async, [](){ return 42; });
    // 主线程可以多次 get()
    int result1 = future.get().get();
    int result2 = future.get().get();

    return 0;
}

// future的示例代码 介绍了如何使用future对象声明和get获取值
// 用于多线程之间值的传递和同步 这里的值可能是最基本的内置类型值 int char
// future对象用于检索 类似取餐的服务员 std::get
// promise和packaged_task类似后厨 提供数据同步操作 std::set_value()

// operator=
// get
// valid
// wait
// wait_for
// wait_until