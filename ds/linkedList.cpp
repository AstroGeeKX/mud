#include <iostream>

using namespace std;

// 单向链表代码demo 自己改动了很多

// 链表节点结构体
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(const int& x) : val(x), next(NULL) {}
    // 结构体构造函数 防止野指针初始化next为NULL
};

// 链表插入结点函数
ListNode *insertNode(ListNode *head, int val)
{
    ListNode *newNode = new ListNode(val); // 新节点存储的空间地址
    ListNode *p = head; // 主链表地址
    // if (head == NULL){
    //     head = newNode;
    // } else{
    //     while (p->next != NULL){
    //         p = p->next;
    //     }
    //     p->next = newNode;
    // }
    // return head;

    if (head) // 如果头节点有东西
    {
        while (p->next) // 下一个节点不空，就一往下移
            p = p->next; // 移到表尾
        p->next = newNode; // 下一个节点为空了，可以正式放置在元素尾了
    }
    else
    {
        head = newNode; // 如果头为空，直接就放置在头节点这里
    }
    return head;
}

// 节点删除函数
ListNode *deleteNode(ListNode *head, int val)
{
    if (head == NULL)
        return NULL;

    ListNode *prev = NULL; // 前个节点
    ListNode *curr = head; // 当前节点
    // 根据val数据寻找节点
    while (curr->next != NULL && curr->next->val != val)
    {
        curr = curr->next;
    }
    prev = curr;
    curr = curr->next;

    // 找不到节点 返回head
    if (curr == NULL)
    {
        return head;
    }
    // 前一个节点为空说明该结点就是head节点 适用有头链表
    // 否则前一个节点指向下两个节点
    if (prev == NULL)
    {
        head = curr->next;
    }
    else
    {
        // cout << prev->next << " " << curr << endl;
        // printf("1删除函数里,现在prev的值是：%d,prev->next的值是%d\n",prev->val,prev->next->val);
        prev->next = curr->next;
        // printf("2删除函数里,现在prev的值是：%d,prev->next的值是%d\n",prev->val,prev->next->val);
        // system("pause");
    }
    // 删除节点
    delete curr;
    return head;
}

// 链表打印函数
void printList(const ListNode* ptf_head)
{
    // const ListNode* p = head; // p是临时的head，虽然没必要
    cout << "[ ";
    while (ptf_head)
    {
        cout << ptf_head->val << " ";
        ptf_head = ptf_head->next;
    }
    cout << "]";
    cout << endl;
}

// 反转链表打印2
void reservePrint2(ListNode *p)
{
    if (p->next)
        reservePrint2(p->next);
    printf("%d ", p->val);
    return;
}

// 反转链表 （常规方法
ListNode *reserveList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *nextp;

    while (cur != NULL)
    {
        nextp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextp;
    }
    return prev; // 此时cur和nextp都是NULL cur的前一个节点prev才是头节点
}

// 反转链表 （递归实现
// 坏的函数
void Reverse(ListNode* p)
{
    if (p->next == NULL)
    {
        return;
    }
    Reverse(p->next);
    ListNode *q = p->next;
    q->next = p;
    p->next = NULL;
}

ListNode *myReserve(ListNode *head)
{
    ListNode *p = head;
    ListNode *q = NULL;
    ListNode *l = NULL;
    int i = 1;
    while (1)
    { // 自己写的，属于是垃圾代码
        p = head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        q = p->next;
        q->next = p;
        p->next = NULL;
        if (p == head)
            break;
        if (i)
        {
            l = q;
            i = 0;
        }
    }
    return l;
}

// 返回值重新赋值，所以不需要二级指针修改外部指针变量
ListNode *myReverse2(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    // ai生成的，改了一下就变回原来的了
    ListNode *current = head;
    ListNode *previous = nullptr;
    ListNode *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

int main()
{
    // 手动暴力创建链表
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(); // 无参构造函数

    // 当前链表是
    printList(head);
    // head = myReverse2(head);
    // cout << "myReserve2:" << endl;
    // printList(head);
    reservePrint2(head);

    // cout << "现在测试链表和插入函数\n";
    // cout << "Original list: ";
    // printList(head);
    // head = insertNode(head,6);
    // cout << "List after insertion: ";
    // printList(head);
    // cout << "这里测试链表节点删除函数\n";
    // deleteNode(head,3);
    // printList(head);
    // cout << "这里测试递归链表反转函数\n";
    // Reserve(head);
    // printList(head);
    // cout << "这里测试递归反转打印链表" << endl;
    // reservePrint2(head);

    return 0;
}

// 这个单向链表写得有点乱
// 增添了很多自己写的元素进去