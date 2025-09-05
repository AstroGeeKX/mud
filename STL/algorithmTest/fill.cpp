#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class myPrint {
   public:
    void operator()(int val) { cout << val << " "; }
};

void test01() {
    vector<int> v;
    v.resize(10);
    // 范围填充
    fill(v.begin(), v.begin() + v.size() / 2, 100);

    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}

int main() {
    test01();

    return 0;
}
