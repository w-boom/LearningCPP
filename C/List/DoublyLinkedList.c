#include <stdio.h>
#include <stdlib.h>

// 定义双向链表节点结构
struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

// 创建新节点
struct DNode* createDNode(int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 插入节点到双向链表头部
void insertAtHead(struct DNode** head, int data) {
    struct DNode* newNode = createDNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// 打印双向链表
void printList(struct DNode* head) {
    struct DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 打印双向链表反向
void printReverse(struct DNode* head) {
    struct DNode* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    struct DNode* head = NULL;
    
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);
    
    printf("Doubly Linked List: ");
    printList(head);  // 输出：30 <-> 20 <-> 10 <-> NULL
    
    printf("Reverse Doubly Linked List: ");
    printReverse(head);  // 输出：10 <-> 20 <-> 30 <-> NULL
    
    return 0;
}
