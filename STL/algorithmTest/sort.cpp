#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

void myPrint(int val) { cout << val << " "; }

void test01() {
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);

    // sort默认从小到大排序
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    // 从大到小排序
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main() {
    test01();

    return 0;
}
