// B3652 [语言月赛202208] 渡荆门送别

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long input;
    vector<long long> hight;

    // 输入数据
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        hight.push_back(input);
    }

    // 要使用max_element和min_element才支持long long
    auto high = hight;  // 最高差容器
    auto low = hight;   // 最低差容器
    vector<long long>::iterator maxIt = max_element(hight.begin(), hight.end());  // 最大值
    vector<long long>::iterator minIt = min_element(hight.begin(), hight.end());  // 最小值
    transform(high.begin(), high.end(), high.begin(), 
              [maxIt](long long x) { return *maxIt - x; });  // 最高差
    transform(low.begin(), low.end(), low.begin(),
              [minIt](long long x) { return x - *minIt; });  // 最低差

    // 输出结果
    for_each(high.begin(), high.end(), [](long long x) { cout << x << " "; });
    cout << endl;
    for_each(low.begin(), low.end(), [](long long x) { cout << x << " "; });

    return 0;
}
