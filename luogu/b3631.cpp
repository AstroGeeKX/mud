// B3631 单向链表

#define SOLUTIOIN_2

#ifdef SOLUTIOIN_1
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int q = 0;
    int choice = 0;
    vector<int> mylist;
    mylist.push_back(1);
    cin >> q;

    while (q--) {
        cin >> choice;

        // 插入y到x后面
        if (choice == 1) {
            int x, y;
            cin >> x >> y;
            auto it = find(mylist.begin(), mylist.end(), x);
            // if (it != mylist.end()) { // 确保找到 x
                mylist.insert(next(it), y);
            // }
        }

        // 输出x后面的数
        if (choice == 2) {
            int x;
            cin >> x;
            auto it = find(mylist.begin(), mylist.end(), x);
            // 确保找到 x 且 x 不是最后一个元素
            if (/*it != mylist.end() && */next(it) != mylist.end()) {
                cout << *next(it) << endl;
            } else {
                cout << 0 << endl; // 如果 x 是最后一个元素，输出 0
            }
        }

        // 删除x后面的那个元素
        if (choice == 3) {
            int x;
            cin >> x;
            auto it = find(mylist.begin(), mylist.end(), x);
            // 确保找到 x 且 x 不是最后一个元素
            // if (it != mylist.end() && next(it) != mylist.end()) {
                mylist.erase(next(it)); // 删除 x 后面的那个元素
            // }
        }
    }

    return 0;
}
/*
所有的it迭代器都进行end()判断，这是常规操作，
但是choice 2中确保x不是最后一个元素关乎题目逻辑，（最后一个元素输出0）
choice 3中可以不判断，因为erase(end())是合法的

提示：如果做题编码时，思维跳动得太快，请每次都思考和处理一个简单的问题
逐渐堆积解决简单问题的量，可以量变产生质变。如果过于急躁，很可能导致
头脑发胀，无法有效做题。

每天只做三道题，变成每次只做一道题
*/
#endif /* SOLUTION_1 */


#ifdef SOLUTIOIN_2
#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int main() {
    int q = 0;
    int choice = 0;
    list<int> mylist;
    unordered_map<int, list<int>::iterator> pos; // 哈希表记录每个元素的位置
    mylist.push_back(1);
    pos[1] = mylist.begin(); // 初始化哈希表 pos[key] = value
    cin >> q;

    while (q--) {
        cin >> choice;

        // 插入y到x后面
        if (choice == 1) {
            int x, y;
            cin >> x >> y;
            auto it = pos[x]; // O(1) 查找 x 的位置
            if (it != mylist.end()) {
                pos[y] = mylist.insert(next(it), y); // 插入 y，并更新哈希表
            }
        }

        // 输出x后面的数
        if (choice == 2) {
            int x;
            cin >> x;
            auto it = pos[x]; // O(1) 查找 x 的位置
            // 哈希表里找到x的位置，将这个位置放到线性表里面查找
            // 哈希表是辅助加速查找某一个元素位置，链表才能保证原始顺序
            if (it != mylist.end() && next(it) != mylist.end()) {
                cout << *next(it) << endl;
            } else {
                cout << 0 << endl; // 如果 x 是最后一个元素，输出 0
            }
        }

        // 删除x后面的那个元素
        if (choice == 3) {
            int x;
            cin >> x;
            auto it = pos[x]; // O(1) 查找 x 的位置
            if (it != mylist.end() && next(it) != mylist.end()) {
                pos.erase(*next(it));
                mylist.erase(next(it));
                // 务必先删除哈希表中的位置，如果先删除链表中的元素，迭代器也会被删除
                // 哈希表删除提供的key
                // list删除提供迭代器
            }
        }
    }

    return 0;
}
/*
思维被旁边的声音干扰的时候，不要吝惜刚刚所思考的内容，果断舍弃
这些内容长期以来就不是什么重点，而是需要更多的内容来搭建知识长城
*/
/*
这类代码优化的思路还是不难的，之前没有概念是因为没有认真看，没有认真学习，
多学之后是可以学会的
*/
/*
不要过度在乎代码格式中的各种空格，以及注释的语言表述优美，不要过度完善注释
*/
/*
计算机中化繁为整很重要，例如list<int>::iterator简化为it
*/
/*
unordered_map<int, list<int>::iterator> pos;
引入了一个哈希表，储存值和迭代器，加速查找迭代器的过程，原理很简单，哈希表同步链表数据，
当需要查找迭代器的时候，不使用链表的find，而是使用哈希表的find
找到迭代器之后，在链表里进行访问。加速的是查找的过程。
为什么不直接使用哈希表呢，因为哈希表无法保证元素的顺序，还需要链表保证原来的顺序
*/
#endif /* SOLUTION_2 */
