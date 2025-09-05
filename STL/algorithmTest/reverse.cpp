#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class myPrint {
   public:
    void operator()(int val) { cout << val << " "; }
};

void test01() {
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);

    cout << "反转前： " << endl;
    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
    cout << "反转后： " << endl;
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint());
    cout << endl;
}

int main() {
    test01();

    return 0;
}
