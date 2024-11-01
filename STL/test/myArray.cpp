// 类模板案例—数组类封装.cpp中

#include "myArray.hpp"
#include <string>

void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//测试内置数据类型
void test01()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.Push_back(i);
	}
	cout << "array1 print out: " << endl;
	printIntArray(array1);
	cout << "array1 size: " << array1.getSize() << endl;
	cout << "array1 volume: " << array1.getCapacity() << endl;

	cout << "--------------------------" << endl;

	MyArray<int> array2(array1);
	array2.Pop_back();
	cout << "array2 print out: " << endl;
	printIntArray(array2);
	cout << "array2 size: " << array2.getSize() << endl;
	cout << "array2 volume: " << array2.getCapacity() << endl;
}

//测试自定义数据类型
class Person {
public:
	Person() {} 
		Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) {
		cout << "name: " << personArr[i].m_Name << " age: " << personArr[i].m_Age << endl;
	}

}

void test02()
{
	//创建数组
	MyArray<Person> pArray(10);
	Person p1("SWK", 30);
	Person p2("HX", 20);
	Person p3("DJ", 18);
	Person p4("WZJ", 15);
	Person p5("ZY", 24);

	//插入数据
	pArray.Push_back(p1);
	pArray.Push_back(p2);
	pArray.Push_back(p3);
	pArray.Push_back(p4);
	pArray.Push_back(p5);

	printPersonArray(pArray);

	cout << "pArray size " << pArray.getSize() << endl;
	cout << "pArray volume " << pArray.getCapacity() << endl;

}

int main() {

	test01(); // 测试基本数据类型 int

	//test02(); // 测试Person类型 （包含一个name和一个age

	system("pause");

	return 0;
}