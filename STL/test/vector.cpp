#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

// 构造函数
void test01()
{
	vector<int> v1; //无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	vector<int> v3(10, 100);
	printVector(v3);
	
	vector<int> v4(v3);
	printVector(v4);
}


//赋值操作
void test02()
{
	vector<int> v1; //无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	v2 = v1; //
	printVector(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end()); //
	printVector(v3);

	vector<int>v4;
	v4.assign(10, 100); //
	printVector(v4);
}


// 容量和大小
void test03()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	if (v1.empty())
	{
		cout << "v1 is empty" << endl;
	}
	else
	{
		cout << "v1 is not empty" << endl;
		cout << "v1 capacity = " << v1.capacity() << endl;
		cout << "v1 size = " << v1.size() << endl;
	}

	//resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
	v1.resize(15,114);
	printVector(v1);

	//resize 重新指定大小 ，若指定的更小，超出部分元素被删除
	v1.resize(5);
	printVector(v1);
}


// vector插入和删除
void test04()
{
	vector<int> v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//尾删
	v1.pop_back();
	printVector(v1);
	//插入
	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 2000);
	printVector(v1);

	//删除
	v1.erase(v1.begin());
	printVector(v1);

	//清空
	v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}


// vector数据存取
void test05()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " "; // []
	}
	cout << "[]" << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " "; // at()
	}
	cout << "at()" << endl;

	cout << "v1 first element is: " << v1.front() << endl;
	cout << "v1 last element is: " << v1.back() << endl;
}


// 互换容器
void test06()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	//互换容器
	cout << "swap ed" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}
// 互换容器 收缩内存
void test07()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}

	cout << "v capacity: " << v.capacity() << endl;
	cout << "v size: " << v.size() << endl;

	v.resize(3);

	cout << "v capacity: " << v.capacity() << endl;
	cout << "v size: " << v.size() << endl;

	//收缩内存
	vector<int>(v).swap(v); //匿名对象

	cout << "v capacity: " << v.capacity() << endl;
	cout << "v size: " << v.size() << endl;
	// 总结：swap可以使两个容器互换，可以达到实用的收缩内存效果
}


// 预留空间
void test08()
{
	vector<int> v;

	//预留空间
	v.reserve(100000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}

	cout << "num:" << num << endl;
	// 如果数据量较大，可以一开始利用reserve预留空间
}


int main()
{
    test08();

    return 0;
}








// void mytest()
// {
//     // 创建含有整数的 vector
//     // 创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
//     vector<int> v;
//     // 向容器中放数据
//     v.push_back(10);
//     v.push_back(20);
//     v.push_back(30);
//     v.push_back(40);

//     // 每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
//     // v.begin()返回迭代器，这个迭代器指向容器中第一个数据
//     // v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
//     // vector<int>::iterator 拿到vector<int>这种容器的迭代器类型

//     vector<int>::iterator pbegin = v.begin();
//     vector<int>::iterator pend = v.end();

//     // 第一种遍历方式：
//     // while (pbegin != pend)
//     // {
//     //     cout << *pbegin << endl;
//     //     pbegin++;
//     // }

//     // 第二种遍历方式：
//     vector<int>::iterator it = v.begin();
//     vector<int>::iterator it = v.end();
//     for (; it != v.end(); it++)
//     {
//         cout << *it << endl;
//     }
//     cout << endl;

//     // 第三种遍历方式：
//     // 使用STL提供标准遍历算法  头文件 algorithm
//     //for_each(v.begin(), v.end(), MyPrint);
// }