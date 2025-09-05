#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void test01() {
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(3);

    // 查找相邻重复元素
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end()) {
        cout << "not found" << endl;
    } else {
        cout << "adjacent found: " << *it << endl;
		cout << "position: " << distance(v.begin(), it) << endl;
	}
}

int main() {
    test01();
    return 0;
}
