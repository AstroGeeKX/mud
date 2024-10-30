#include <stdio.h>
#include <stdlib.h>

// 定义双向循环链表结构体
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// 在链表末尾插入节点
void insert(struct Node** headRef, int data) {
    // 创建新节点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*headRef == NULL) {
        // 如果链表为空，让新节点成为唯一一个节点
        newNode->prev = newNode;
        newNode->next = newNode;
        *headRef = newNode;
    } else {
        // 如果链表不为空，在链表末尾插入新节点
        struct Node* lastNode = (*headRef)->prev;
        newNode->prev = lastNode;
        newNode->next = *headRef;
        lastNode->next = newNode;
        (*headRef)->prev = newNode;
    }
}

// 在链表中删除指定值的节点
void delete(struct Node** headRef, int data) {
    if (*headRef == NULL) {
        // 链表为空，无需删除
        return;
    }

    struct Node* current = *headRef;

    // 查找要删除的节点
    while (current->data != data && current->next != *headRef) {
        current = current->next;
    }

    if (current->data == data) {
        // 找到要删除的节点
        if (current->next == current) {
            // 要删除的节点是唯一一个节点
            *headRef = NULL;
        } else {
            // 从链表中删除节点
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (*headRef == current) {
                // 如果要删除的节点是头节点，更新头指针
                *headRef = current->next;
            }
        }
        free(current);
    }
}

// 打印链表
void printList(struct Node* head) {
    if (head != NULL) {
        struct Node* current = head;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }
    printf("\n");
}

// 测试代码
int main() {
    struct Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    printf("原始链表：");
    printList(head);  // 输出：1 2 3

    delete(&head, 2);

    printf("删除节点后的链表：");
    printList(head);  // 输出：1 3

    return 0;
}