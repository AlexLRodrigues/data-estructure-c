#include<stdio.h>
#include<stdlib.h>

struct Node {
    int number;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNewNode(int number) {
    Node* node = (Node*)malloc(sizeof(struct Node));
    node->number = number;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void insertAtHead(Node** head, int number) {
    Node* newNode = createNewNode(number);

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    (*head)->prev = newNode;
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(Node** head, int number) {
    Node* newNode = createNewNode(number);

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    newNode->prev = temp;
    temp->next = newNode;
}

void printList(Node* node) {

    if(node == NULL) {
        printf("\n");
        return;
    }

    printf("%d ", node->number);
    
    printList(node->next);
}

void reversePrintList(Node* head) {

    struct Node* temp = head;

    if(temp == NULL) return;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    while(temp != NULL) {
        printf("%d ", temp->number);
        temp = temp->prev;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;

    // insertAtHead(&head, 1);
    // insertAtHead(&head, 2);

    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);

    // printList(head);

    reversePrintList(head);
}
