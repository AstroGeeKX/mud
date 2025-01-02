#include <cstdio>
#include <cstdlib>
#include <memory>

using namespace std;

struct Resource {
    void *p;

    Resource() {
        puts("分配资源");
        p = malloc(1);
    }

    Resource(Resource &&that) : p(that.p) {
        that.p = nullptr;  // 一定要把对方置空！
    }

    Resource(Resource const &) = delete;

    ~Resource() {
        if (p) {
            puts("释放资源");
            free(p);
        }
    }
};

void func(Resource x) {
}

int main() {
    auto x = Resource();
    func(std::move(x));
}

// 本程序示范了关于资源管理类的移动，手动编写移动构造函数实现移动
// 总结就是 1、移动构造中将对方的资源置空 2、析构函数中判断资源是否已经被置空
// 防止二次释放资源