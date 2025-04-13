#include <iostream>
#include <vector>
using namespace std;

// 试着把这个函数写成支持多类型的函数模板
template<typename T>
void printVector(vector<T>& v) {

	for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
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

	vector<int> v2(v1.begin(), v1.end());  // 开始和结尾构造
	printVector(v2);

	vector<char> v3(10, 'V');  // 元素和数量构造
	printVector(v3);
	
	vector<char> v4(v3);  // 拷贝构造
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
	v2 = v1;  // 对象拷贝
	printVector(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end());  // 对象赋值
	printVector(v3);

	vector<int>v4;
	v4.assign(10, 6);  // 指定数量和元素内容赋值
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
	printVector(v1);  // 填充数据
	// 判断为空 执行else
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
	v1.resize(15,6);
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

	//插入 指定位置和元素
	v1.insert(v1.begin(), 66);
	printVector(v1);
	
	// 指定位置、数量、元素
	// iterator insert( const_iterator pos,size_type count, const T& value );
	v1.insert(v1.begin(), 2, 6);
	printVector(v1);
	
	//尾删
	v1.pop_back();
	printVector(v1);

	//删除 指定某一个元素位置
	v1.erase(v1.begin() + 2);
	printVector(v1);

	//清空 指定开始和结尾位置
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

	// []
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << "use []" << endl;

	// at()
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << "use at()" << endl;
	
	cout << "v1 first element is: " << v1.front() << endl;
	cout << "v1 last element is: " << v1.back() << endl;
}


// 互换容器
void test06()
{
	vector<int>v1, v2;
	for (int i = 0; i < 10; i++)  // 不对称边界 最后一个i是9
	{
		v1.push_back(i);
		v2.push_back(9 - i);
	}
	printVector(v1);
	printVector(v2);

	//互换容器
	cout << "v1.swap(v2)" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

// 互换容器 收缩内存
void test07()
{
	vector<int> v;
	for (int i = 0; i < 9999; i++) {
		v.push_back(i);
	}
	cout << "v capacity: " << v.capacity() << endl;
	cout << "v size: " << v.size() << endl;

	// resize() 重新改变容器大小 改变的貌似是capacity
	v.resize(3);
	cout << "v capacity: " << v.capacity() << endl;
	cout << "v size: " << v.size() << endl;

	// 交换容器收缩容量
	// vector<int> v2(v);  原理在于v2的capacity优化缩减，可能为size
	vector<int>(v).swap(v);  // 临时匿名对象

	cout << "v capacity: " << v.capacity() << endl;
	cout << "v size: " << v.size() << endl;
	// 总结：swap可以使两个容器互换
	// 创建临时对象再swap可以达到收缩内存效果
}


// 预留空间
void test08()
{
	vector<int> v;
	// v.reserve(100000);  // 预留空间

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}

	cout << "num: " << num << endl;
	// 如果数据量较大，可以一开始利用reserve预留空间
	// p指向v对象首地址，循环过程中v的内存位置会发生变化，num记录变化次数，代表内存安置的次数
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
//     // v.begin()返回迭代器，指向容器中的首元素
//     // v.end()返回迭代器，指向容器中的末元素再往下一个元素
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
//     // 不要有前两个参数写不同的容器对象的想法，这样的想法容易造成记忆混乱，只针对同一容器记忆即可
// }

// 遍历方式无关紧要，区区几行代码不足挂齿，按照自己的编程需要选择一个方便的即可