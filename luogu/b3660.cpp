// B3660 [语言月赛202209] 集卡

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    int n = 0;
    int temp = 0;
    vector<int> cards;
    cin >> t;  // 集卡次数

    for (int i = 0; i < t; i++) {
        cin >> n;  // 每次集卡的数量
        for (int j = 0; j < n; j++) {
            cin >> temp;
            cards.push_back(temp);
        }
        vector<int>::iterator it = find(cards.begin(), cards.end(), 0);
        if (it != cards.end()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
        cards.clear();
    }

    return 0;
}
