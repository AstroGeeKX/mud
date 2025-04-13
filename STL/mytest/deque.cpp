#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

template <typename T>
void printDeque(const T& d) 
{
	for (auto x : d) {
		cout << *x << " ";
	}
	cout << endl;
}


//deque构造
void test01()
{
	deque<int> d1; //无参构造函数
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int> d2(d1.begin(),d1.end());
	printDeque(d2);

	deque<int>d3(10,100);
	printDeque(d3);

	deque<int>d4 = d3;
	printDeque(d4);
}


//赋值操作
void test02()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2;
	d2 = d1;
	printDeque(d2);

	deque<int>d3;
	d3.assign(d1.begin(), d1.end());  // 条条道路通罗马
	printDeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);
}


// 大小操作
void test03()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++) {
        d1.push_back(i);
    }
    printDeque(d1);

    // 判断容器是否为空
    if (d1.empty()) {
        cout << "d1 is empty!" << endl;
    } else {
        cout << "d1 is not empty!" << endl;
        // 统计大小
        cout << "d1 size: " << d1.size() << endl;
    }

    // 重新指定大小
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}


//两端操作 插入和删除
void test04()
{
	deque<int> d;
	//尾插
	d.push_back(10);
	d.push_back(20);
	//头插
	d.push_front(300);
	d.push_front(500);

	printDeque(d);

	//尾删
	d.pop_back();
	//头删
	d.pop_front();
	printDeque(d);
}


//插入
void test05()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	// insert(position, x)
	d.insert(d.begin(), 1000);
	printDeque(d);

	// insert(position, size, x)
	d.insert(d.begin(), 2, 10000);
	printDeque(d);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d.insert(d.end(), d2.begin(), d2.end());
	printDeque(d);
}


//删除
void test06()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	d.erase(d.begin());
	printDeque(d);

	d.erase(d.begin(), d.end());
	d.clear(); // 删了又删
	printDeque(d);
}


//数据存取
void test07()
{
    deque<int> d{1, 2, 3, 4, 5};

	// 使用[]运算符访问
    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
	}
	cout << endl;

	// 使用at()函数访问
	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "front:" << d.front() << endl;

	cout << "back:" << d.back() << endl;

}


// 排序
void test08()
{
    deque<int> d{1, 2, 5, 3, 6, 7, 9, 8};

    printDeque(d);
    sort(d.begin(), d.end());
    printDeque(d);
}


int main() {

	test07();

	return 0;
}

// 双端队列
//  2024年6月3日 下午