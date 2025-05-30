// B4060 位运算 1

#include <iostream>

using namespace std;

int main() {
    int a, b, k;
    int ans;
    cin >> a >> b >> k;
    ans = a & b;
    cout << ans << endl;
    ans = a | b;
    cout << ans << endl;
    ans = a ^ b;
    cout << ans << endl;
    ans = ~a;
    cout << ans << endl;
    ans = a << k;
    cout << ans << endl;
    ans = a >> k;
    cout << ans << endl;

    return 0;
}
