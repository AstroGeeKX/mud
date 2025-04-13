#include <queue>
#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		m_Name = name; // this在这里只是当作一个提示词 实际上是形参和成员变量同名时才使用
		this->m_Age = age;
	}

	Person&& hello();
	// {
	// 	cout << "hello :";
	// 	return q.front();
	// }

	string m_Name;
	int m_Age;
};
// 这里就是用户自定义类型 可以放进容器里 容器里每一个元素都是此类型对象
// 基本数据类型 结构体类型 类类型。其中结构体和类就是用户自定义类型
// 甚至是模板类类型 也可以放容器里，实际上是一个模板嵌套的写法
// 但我认为不应该纠结模板类还是类模板，同一词汇在不同情况具有不同意义，我将重点放在类上

// 模板类类型表示用户自定义的template class类型
// class就不应该翻译为“类” 因为和“类型”词汇冲突，造成混淆

// 不把基本数据类型的变量叫做 对象object 可能是历史原因，object表示实体的意思，对int等同样适用

// 准备数据
Person p1("p1", 1);
Person p2("p2", 2);
Person p3("p3", 3);
Person p4("p4", 4);

// 创建队列
queue<Person> q;
// queue为容器类型 Person规定了所存放数据的类型 q是这个容器对象的对象名
// 通常一批数据用一个容器对象来存储 不同类型、不同用途的数据，就另起容器对象
// 一个具体的容器对象，存储的数据是同一种类型 泛型的实现是要另起容器对象
// 一个q存放多个Person object对象 1:m的关系

Person&& Person::hello()
{
	cout << "hello : ";
	return move(q.front());
}

void test01()
{

	// 向队列中添加元素  入队操作  队列push只能尾增（尾插
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	// 队列不提供迭代器，更不支持随机访问
	while (!q.empty())
	{
		// 输出队头元素
		cout << "front name: " << q.front().m_Name
			 << " age: " << q.front().m_Age << endl;

		cout << "back name: " << q.back().m_Name
			 << " age: " << q.back().m_Age << endl;

		cout << endl;
		// 弹出队头元素
		q.pop();
	}

	cout << "queue size: " << q.size() << endl;
}
// 输出结果队尾不变，队头一个接一个删除

void test02()
{

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "use front() and pop() read queue elements" << endl;

	while (!q.empty())
	{
		auto temp = q.front();
		cout << temp.m_Name << " " << temp.m_Age << " " << endl;
		q.pop();
	}
}

void test03()
{

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	cout << "use Person hello() to do sth" << endl;

	if (!q.empty())
	{
		Person&& temp = q.front().hello();
		cout << temp.m_Name << " " << temp.m_Age << " " << endl;
		temp.hello();
		q.pop();
	}
}
// 对于Person temp = 而言 temp 是一个新的 Person 对象 （拷贝构造函数
// front()返回值只能用以下三种类型获取
// Person值类型 通过拷贝构造函数
// Person&& 右值引用类型
// const Person& 左值常量引用类型 后面的代码不能有修改，否则报错

void test04()
{

	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	if (!q.empty()) // 因为有这句if判断是否为空，所以Person& 不报错了
	{
		// 获取队列中第一个元素的引用
		// 因为生命周期的缘故，要用右值引用&&
		// Person &&Person::hello() 函数原型 返回值 const Person& 和 Person&& 二选一
		Person&& firstPerson = q.front().hello();

		// 现在可以使用 firstPerson 直接访问和修改队列中第一个元素的成员
		firstPerson.m_Name = "firstName";
		cout << firstPerson.m_Name << " " << firstPerson.m_Age << endl;
	}
}

int main()
{

	test04();

	return 0;
}