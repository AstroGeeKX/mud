#include <iostream>
#include <string>
#include <utility>
using namespace std;

// pair<T1, T2> p1;            //创建一个空的pair对象（使用默认构造），采用值初始化。
// pair<T1, T2> p1(v1, v2);    //创建一个pair对象，它的两个元素分别是T1和T2类型
// make_pair(v1, v2);          // 以v1和v2的值创建一个新的pair对象

//对组创建
void test01()
{
	pair<string, int> p(string("Tom"), 20);  // 两个元素类型可以不一致
	cout << "name: " <<  p.first << " age: " << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "name: " << p2.first << " age: " << p2.second << endl;
}

int main() {

	test01();

	return 0;
}