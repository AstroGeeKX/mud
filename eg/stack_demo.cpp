#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
 
using namespace std;
 
template <class T>
class Stack { 
  private: 
    vector<T> m_elems;          // 元素 
 
  public: 
    void push(T const&);      // 入栈
    void pop();               // 出栈
    T top() const;            // 返回栈顶元素
    bool empty() const { return m_elems.empty(); } // 如果为空则返回真。
}; // class Stack结束声明
 
template <class T>
void Stack<T>::push (T const& elem) 
{ 
    // 追加传入元素的副本
    m_elems.push_back(elem);    
} 
 
template <class T>
void Stack<T>::pop () 
{ 
    if (m_elems.empty()) { 
        throw out_of_range("Stack<>::pop(): empty stack"); 
    }
    // 删除最后一个元素
    m_elems.pop_back();         
} 
 
template <class T>
T Stack<T>::top () const 
{ 
    if (m_elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
    if (m_elems.empty()) {
        throw out_of_range("something is wrong");
    }
    // 返回最后一个元素的副本 
    return m_elems.back();      
} 
 
int main() 
{ 
    try { 
        Stack<int>         intStack;       // int 类型的栈 
        Stack<string>      stringStack;    // string 类型的栈 
 
        // 操作 int 类型的栈 
        intStack.push(7); 
        cout << intStack.top() <<endl; 

        // 操作 string 类型的栈 
        stringStack.push("hello"); 
        cout << stringStack.top() << std::endl; 
        stringStack.pop(); 
        // stringStack.pop(); // 这里将出现错误，因为栈已经空了
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
}