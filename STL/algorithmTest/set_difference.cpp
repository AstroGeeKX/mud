#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class myPrint {
   public:
    void operator()(int val) { cout << val << " "; }
};

void test01() {
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> vTarget;
    // 取两个里面较大的值给目标容器开辟空间
    vTarget.resize(max(v1.size(), v2.size()));

    // 输出两个容器的内容
    for_each(v1.begin(), v1.end(), myPrint());
    cout << endl;
    for_each(v2.begin(), v2.end(), myPrint());
    cout << endl;

    // 求差集 返回目标容器的最后一个元素的迭代器地址
    cout << "v1与v2的差集为： " << endl;
    vector<int>::iterator itEnd = set_difference(
        v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;

    cout << "v2与v1的差集为： " << endl;
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(),
                           vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;
}

int main() {
    test01();

    return 0;
}
