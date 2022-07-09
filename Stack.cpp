#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct Node {
    int number;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNewNode(int number) {
    Node* node = (Node*)malloc(sizeof(struct Node));
    node->number = number;
    node->next = NULL;

    return node;
}

void push(int number) {
    Node* newNode = createNewNode(number);
    newNode->next = head;
    head = newNode;
}

void pop() {
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    free(temp);
}

struct Node* top() {
    return head;
}

bool isEmpty() {
    return head == NULL;
}

void printList() {
    struct Node* temp = head;
    printf("Stack elements: [ ");

    while(temp != NULL){
        printf("%d ",temp->number);
        temp = temp->next;
    }

    printf("]\n");
}

int main(){
    push(1);
    push(2);
    push(3);
    printList();
    pop();
    pop();
    printList();
    push(4);
    printList();
    pop();
    pop();
    // printf("%d ",top()->number);
    printf("%d ",isEmpty());
}
