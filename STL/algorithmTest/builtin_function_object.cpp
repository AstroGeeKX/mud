#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// logical_not
void test01() {
    vector<bool> v{true, false, true, false, true, false, true, false};

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // 逻辑非  将v容器搬运到v2中，并执行逻辑非运算
    vector<bool> v2;
    v2.resize(v.size());
    /* 下方的logical_not<bool>() 就是内建逻辑仿函数 */
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

class MyCompare {
   public:
    bool operator()(int v1, int v2) { return v1 > v2; }
    // > 就是从大到小排序
};

// greater
void test02() {
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);
    v.push_back(20);
    for (auto &x : v) {
        cout << x << " ";
        x += 1;
    }
    cout << endl;

    // STL内建仿函数  大于排序仿函数
    // sort(v.begin(), v.end(), MyCompare());  // 自己实现仿函数
    sort(v.begin(), v.end(), std::greater<int>());

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

// negate plus
void test03() {
    std::negate<int> n;
    cout << n(50) << endl;
    std::plus<int> p;  // 模板类型是int，接受两个int参数进行加法运算
    cout << p(10, 20) << endl;
}
/*
1、填充模板类型，生成模板类
2、创建对象
3、调用对象的仿函数
template <typename T>
class plus {
   public:
    T operator()(T v1, T v2) { return v1 + v2; }
};
*/

int main() {
    test01();
    cout << "------------------" << endl;
    test02();
    cout << "------------------" << endl;
    test03();

    return 0;
}

/*
勇于尝试新的写法，而不是再三考虑是否合适，在各种小场合使用
*/
