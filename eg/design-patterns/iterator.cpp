#include <iostream>
#include <string>
using namespace std;

// 定义一个链表节点
struct Node {
    Node(string n) : name(n) {}
    string name = string();
    Node* next = nullptr;
    Node* prev = nullptr;
};

// 前向声明
class Iterator;

// 双向链表类
class MyList {
   public:
    inline int getCount() { return m_count; }

    inline Node* head() { return m_head; }

    inline Node* tail() { return m_tail; }

    Node* insert(Node* item, string data);
    Node* pushFront(string data);
    Node* pushBack(string data);
    Iterator* getIterator(bool isReverse = false);

   private:
    Node* m_head = nullptr;
    Node* m_tail = nullptr;
    int m_count = 0;
};

// 抽象的迭代器类
class Iterator {
   public:
    Iterator(MyList* mylist) : m_list(mylist) {}
    Node* current() { return m_current; }
    virtual Node* first() = 0;
    virtual Node* next() = 0;
    virtual bool isDone() = 0;
    virtual ~Iterator() {}

   protected:
    MyList* m_list = nullptr;
    Node* m_current = nullptr;
};

// 正向迭代器
class ForwardIterator : public Iterator {
   public:
    using Iterator::Iterator;
    Node* first() override {
        m_current = m_list->head();
        return m_current;
    }
    Node* next() override {
        m_current = m_current->next;
        return m_current;
    }
    bool isDone() override { return m_current == nullptr; }
};

// 逆向迭代器
class ReverseIterator : public Iterator {
   public:
    using Iterator::Iterator;
    Node* first() override {
        m_current = m_list->tail();
        return m_current;
    }
    Node* next() override {
        m_current = m_current->prev;
        return m_current;
    }
    bool isDone() override { return m_current == nullptr; }
};

// MyList类方法实现
Node* MyList::insert(Node* item, string data) {
    Node* node = nullptr;
    if (item == m_head) {
        node = pushFront(data);
    } else {
        node = new Node(data);
        node->next = item;
        node->prev = item->prev;
        // 重新连接
        item->prev->next = node;
        item->prev = node;
        m_count++;
    }
    return node;
}

Node* MyList::pushFront(string data) {
    Node* node = new Node(data);
    // 空链表
    if (m_head == nullptr) {
        m_head = m_tail = node;
    } else {
        node->next = m_head;
        m_head->prev = node;
        m_head = node;
    }
    m_count++;
    return node;
}

Node* MyList::pushBack(string data) {
    Node* node = new Node(data);
    // 空链表
    if (m_tail == nullptr) {
        m_head = m_tail = node;
    } else {
        m_tail->next = node;
        node->prev = m_tail;
        m_tail = node;
    }
    m_count++;
    return node;
}

Iterator* MyList::getIterator(bool isReverse) {
    Iterator* iterator = nullptr;
    if (isReverse) {
        iterator = new ReverseIterator(this);
    } else {
        iterator = new ForwardIterator(this);
    }
    return iterator;
}

// 测试代码示例
int main() {
    MyList list;

    // 添加一些数据
    list.pushBack("凯多");
    list.pushBack("烬");
    list.pushBack("奎因");
    list.pushBack("杰克");

    cout << "正向遍历：" << endl;
    Iterator* forwardIter = list.getIterator(false);
    for (Node* node = forwardIter->first(); !forwardIter->isDone();
         node = forwardIter->next()) {
        cout << node->name << " ";
    }
    cout << endl;

    cout << "逆向遍历：" << endl;
    Iterator* reverseIter = list.getIterator(true);
    for (Node* node = reverseIter->first(); !reverseIter->isDone();
         node = reverseIter->next()) {
        cout << node->name << " ";
    }
    cout << endl;

    delete forwardIter;
    delete reverseIter;

    return 0;
}
