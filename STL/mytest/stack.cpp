#include <stack>
#include <iostream>
using namespace std;

//栈容器常用接口
void test01()
{
	//创建栈容器 栈容器必须符合先进后出
	stack<int> s;

	//向栈中添加元素，叫做 压栈 入栈
	s.push(10);
	s.push(20);
	s.push(30);

	cout << "stack size: " << s.size() << endl;
	while (!s.empty()) {
		//输出栈顶元素
		cout << "stack element: " << s.top() << endl;
		//弹出栈顶元素
		s.pop();
	}
	cout << "stack size: " << s.size() << endl;

}


int main() {

	test01();

	system("pause");

	return 0;
}


/*
* 总结：
* 入栈   --- push
* 出栈   --- pop
* 返回栈顶   --- top
* 判断栈是否为空   --- empty
* 返回栈大小   --- size
*/