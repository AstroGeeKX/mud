#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// list构造函数
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	// (start, end)拷贝构造
	list<int>L2(L1.begin(), L1.end());
	printList(L2);

	// 拷贝构造
	list<int>L3(L2);
	printList(L3);
	// (数量， 元素)初始化构造 
	list<int>L4(10, 6);
	printList(L4);
}


//赋值
void test02()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	// 整个对象赋值
	list<int>L2;
	L2 = L1;

	// (start, end)赋值
	list<int>L3;
	L3.assign(L2.begin(), L2.end());

	// (count, value)赋值
	list<int>L4;
	L4.assign(10, 514);

	printList(L1);
	printList(L2);
	printList(L3);
	printList(L4);

}


//交换
void test03()
{

	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	// assign 赋值函数
	list<int>L2;
	L2.assign(10, 6);

	cout << "before swap: " << endl;
	printList(L1);
	printList(L2);
	
	L1.swap(L2);
	cout << "after swap: " << endl;
	printList(L1);
	printList(L2);
}


// 容量大小操作
void test04()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	if (L1.empty())
	{
		cout << "L1 is empty" << endl;
	}
	else
	{
		cout << "L1 is not empty" << endl;
		cout << "L1 size: " << L1.size() << endl;
	}

	//重新指定大小
	L1.resize(10);
	printList(L1);

	L1.resize(2);
	printList(L1);
}


//插入和删除
void test05()
{
	list<int> L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	printList(L);  // line 1

	//尾删
	L.pop_back();
	printList(L);  // line 2

	//头删
	L.pop_front();
	printList(L);  // line 3

	//插入
	list<int>::iterator it = L.begin();  // it是首元素（迭代器）
	L.insert(it, 114);
	printList(L);  // line 4

	//删除
	it = L.begin();
	L.erase(it);
	printList(L);  // line 5

	//移除
	L.push_back(514);
	L.push_back(514);
	L.push_back(514);
	printList(L);  // line 6

	// 移除链表容器中所有514元素
	L.remove(514);
	printList(L);  // line 7
    
    //清空
	L.clear();
	printList(L);  // empty line 8
}


// 数据存取
void test06()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	// list容器的迭代器是双向迭代器，不支持随机访问
	//cout << L1.at(0) << endl;  // 错误  不支持at()访问数据
	//cout << L1[0] << endl;   // 错误  不支持[]访问数据
	cout << "first element, L1.front(): " << L1.front() << endl;
	cout << "last element, L1.back(): " << L1.back() << endl;
	// it = it + 1;  // 错误，不可以跳跃访问，只能是++ --这些
}


//反转和排序 函数谓词
bool myCompare(int l , int r)
{
	return l > r;
}
void test07()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);

	//反转容器的元素
	L.reverse();
	printList(L);

	//排序
	L.sort();  // 默认的排序规则 从小到大
	printList(L);

	L.sort(myCompare);  // 指定规则，从大到小
	printList(L);
}


// std::find查找
void test08() {
    std::list<int> myList = {1, 2, 3, 4, 5};
    int target = 4;

    auto it = find(myList.begin(), myList.end(), target);
    if (it != myList.end()) {
        std::cout << "Element found at position: "
                  << std::distance(myList.begin(), it) << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }
}

int main() {

	test08();

	return 0;
}
