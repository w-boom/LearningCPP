#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct Node {
    int data;
    struct Node* next;
};

// 创建新节点
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 插入节点到链表头部
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// 打印链表
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);
    
    printf("Linked List: ");
    printList(head);  // 输出：30 -> 20 -> 10 -> NULL
    
    return 0;
}
