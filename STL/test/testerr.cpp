#include <queue>
#include <iostream>

using namespace std;

queue<int> q; // 全局变量q

int main()
{
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "use front() and pop() read: " << endl;

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}