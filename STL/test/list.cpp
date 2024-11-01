#include <list>
#include <iostream>
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

	list<int>L2(L1.begin(),L1.end());
	printList(L2);

	list<int>L3(L2);
	printList(L3);

	list<int>L4(5, 114);
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

	//赋值
	list<int>L2;
	L2 = L1;

	list<int>L3;
	L3.assign(L2.begin(), L2.end());

	list<int>L4;
	L4.assign(5, 514);

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

	list<int>L2;
	L2.assign(10, 100); // assign 赋值函数

	cout << "before swap: " << endl;
	printList(L1);
	printList(L2);

	cout << endl;

	L1.swap(L2);

	cout << "after swap: " << endl;
	printList(L1);
	printList(L2);

}


//大小操作
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

	printList(L);

	//尾删
	L.pop_back();
	printList(L);

	//头删
	L.pop_front();
	printList(L);

	//插入
	list<int>::iterator it = L.begin();
	L.insert(++it, 114);
	printList(L);

	//删除
	it = L.begin();
	L.erase(++it);
	printList(L);

	//移除
	L.push_back(514);
	L.push_back(514);
	L.push_back(514);
	printList(L);

	L.remove(514);
	printList(L);
    
    //清空
	L.clear();
	printList(L);
}


// 数据存取
void test06()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	
	//cout << L1.at(0) << endl;//错误 不支持at访问数据
	//cout << L1[0] << endl; //错误  不支持[]方式访问数据
	cout << "first element : " << L1.front() << endl;
	cout << "last element : " << L1.back() << endl;

	//list容器的迭代器是双向迭代器，不支持随机访问
	list<int>::iterator it = L1.begin();
	//it = it + 1;//错误，不可以跳跃访问，即使是+1
}
// * list容器中不可以通过[]或者at方式访问数据
// * 返回第一个元素   --- front
// * 返回最后一个元素   --- back



//反转和排序
bool myCompare(int val1 , int val2)
{
	return val1 > val2;
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
	L.sort(); //默认的排序规则 从小到大
	printList(L);

	L.sort(myCompare); //指定规则，从大到小
	printList(L);
}


int main() {

	test07();

	return 0;
}