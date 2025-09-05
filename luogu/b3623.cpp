// B3623 枚举排列（递归实现排列型枚举）

#include <iostream>
using namespace std;

void foo(int num) {
    if (num > 1) {
        foo(num - 1);
    }
    cout << num << ' ';
}

int main() {
    int n = 0;
    cin >> n;
    foo(n);
    cout << endl;

    return 0;
}
