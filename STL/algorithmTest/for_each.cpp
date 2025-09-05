#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 普通函数
void print01(int val) { cout << val << " "; }
void (*p_print01)(int) = print01;  // 函数指针

// 函数对象
class print02 {
   public:
    void operator()(int val) { cout << val << " "; }
};

// 函数模板
template <typename T>
void print03(T val) { cout << val << " "; }
void (*p_print03)(int) = print03<int>;  // 函数模板指针

// for_each算法基本用法
void test01() {
    // 初始化一个容器变量 数字序列0-9
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    // 遍历算法
    for_each(v.begin(), v.end(), p_print01);
    cout << endl;

    for_each(v.begin(), v.end(), print02());
    cout << endl;

    for_each(v.begin(), v.end(), p_print03);
    cout << endl;
}

int main() {
    test01();

    return 0;
}
