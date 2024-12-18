#include <unistd.h>

#include <cstdlib>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

static const int kItemRepositorySize  = 10; // Item buffer size.
static const int kItemsToProduce  = 1000;   // How many items we plan to produce.

struct ItemRepository {
    int item_buffer[kItemRepositorySize]; // 产品缓冲区, 配合 read_position 和 write_position 模型环形队列.
    size_t read_position; // 消费者读取产品位置.
    size_t write_position; // 生产者写入产品位置.
    std::mutex mtx; // 互斥量,保护产品缓冲区
    std::condition_variable repo_not_full; // 条件变量, 指示产品缓冲区不为满.
    std::condition_variable repo_not_empty; // 条件变量, 指示产品缓冲区不为空.
} gItemRepository; // 产品库全局变量, 生产者和消费者操作该变量.

typedef struct ItemRepository ItemRepository; // 重命名结构体名称 省略了struct这个词

/*
    用读写位置下标标记的方式来模拟环形队列，是这份代码中比较容易产生思维陷阱的地方,
    容易干扰学者学习 生产消费过程的线程处理原理 这一主要内容
    模拟队列化简为 队列读写 队列空满 没了
*/
void ProduceItem(ItemRepository *ir, int item)
{
    std::unique_lock<std::mutex> lock(ir->mtx);
    while(((ir->write_position + 1) % kItemRepositorySize)
        == ir->read_position) { // 类似循环队列的判定方法，仓满则等待，消费到有空余时才可继续生产产品
        std::cout << "Producer is waiting for an empty slot...\n";
        (ir->repo_not_full).wait(lock); // 生产者等待"产品库缓冲区不为满"这一条件发生.not_full表示要等到的结果
    }

    (ir->item_buffer)[ir->write_position] = item; // 写入产品.
    (ir->write_position)++; // 写入位置后移.

    if (ir->write_position == kItemRepositorySize) // 写入位置若是越界了则迂回到首位
        ir->write_position = 0;

    (ir->repo_not_empty).notify_all(); // 通知消费者产品库不为空.
    lock.unlock(); // 解锁.
}

int ConsumeItem(ItemRepository *ir)
{
    int data;
    std::unique_lock<std::mutex> lock(ir->mtx);
    // 读写位置重合，说明已经空了，需要等待生产
    while(ir->write_position == ir->read_position) {
        std::cout << "Consumer is waiting for items...\n";
        (ir->repo_not_empty).wait(lock); // 消费者等待"产品库缓冲区不为空"这一条件发生.
    }

    data = (ir->item_buffer)[ir->read_position]; // 读取某一产品
    (ir->read_position)++; // 读取位置后移

    if (ir->read_position >= kItemRepositorySize) // 读取位置若越界了，则重新置位.
        ir->read_position = 0;

    (ir->repo_not_full).notify_all(); // 通知消费者产品库不为满.not_full表示要通知到对面的消息
    lock.unlock(); // 解锁.

    return data; // 返回产品.
}

// 湿代码
// 生产者任务
void ProducerTask() 
{
    for (int i = 1; i <= kItemsToProduce; ++i) {
        // sleep(1);
        std::cout << "Produce the " << i << "^th item..." << std::endl;
        ProduceItem(&gItemRepository, i); // 循环生产 kItemsToProduce 个产品.
    }
}

// 湿代码
// 消费者任务
void ConsumerTask() 
{
    static int cnt = 0;
    while(1) {
        sleep(1); // 一秒钟
        int item = ConsumeItem(&gItemRepository); // 消费一个产品.
        std::cout << "Consume the " << item << "^th item" << std::endl;
        if (++cnt == kItemsToProduce) break; // 如果产品消费个数为(1000个) kItemsToProduce, 最大消费数量则退出.
    }
}

// 两行语句没必要封装成一个函数
void InitItemRepository(ItemRepository *ir)
{
    ir->write_position = 0; // 初始化产品写入位置.
    ir->read_position = 0; // 初始化产品读取位置.
}

int main()
{
    InitItemRepository(&gItemRepository);   // 没必要函数

    // 下面创建线程其实可以用std::async的方式来简化代码，当然std::thread方式就很简单了

    std::thread producer(ProducerTask); // 创建生产者线程.
    std::thread consumer(ConsumerTask); // 创建消费之线程.
    producer.join();
    consumer.join();
}

// 单生产者单消费者模型
// 博客园https://www.cnblogs.com/haippy/p/3252092.html

// 条件变量的语义总结： wait等待结果（当前不是）     notify通知状态（当前就是）
// 例如等待not_full（不满）的时候才继续任务，猜出这是生产的线程，因为只有不满，仓库才有空余，才能继续生产