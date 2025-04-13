#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void test01()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);

	//查找相邻重复元素
	vector<int>::reverse_iterator it = adjacent_find(v.rbegin(), v.rend());
	if (it == v.rend()) {
		cout << "not found" << endl;
	}
	else {
		cout << "adjacent found: " << *it << endl;
	}
}

int main() {
    test01();
    return 0;
}