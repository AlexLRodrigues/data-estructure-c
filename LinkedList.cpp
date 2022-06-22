#include<stdio.h>
#include<stdlib.h>

struct Node {
    int number;
    struct Node* next;
};

void addAtTheBeggin(Node** head, int number) {
    
    Node* temp = (Node*)malloc(sizeof(struct Node));

    temp->number = number;
    
    if(*head != NULL) {
        temp->next = *head;
    }
    *head = temp;
}

void addInPosition(Node** head, int number, int position) {

    Node* temp1 = (Node*)malloc(sizeof(struct Node));
    temp1->number = number;
    temp1->next = NULL;

    if(position == 1) {
        temp1->next = *head;
        *head = temp1;
        return;
    }

    Node* temp2 = *head;
    int i;

    for(i=0; i<position-2; i++){
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;

}

void removeInPosition(Node** head, int position) {

    struct Node* temp1 = *head;

    if(position == 1) { 
        *head = temp1->next;
        free(temp1);
        return;
    }

    int i;

    for(i=0; i<position-2; i++){
        temp1 = temp1->next;
    }

    struct Node* temp2 = temp1->next;
    
    temp1->next = temp2->next;
    free(temp2);
}

void printList(Node* head) {
    struct Node* temp = head;
    printf("List elements: [ ");

    while(temp != NULL){
        printf("%d ",temp->number);
        temp = temp->next;
    }

    printf("]\n");
}

void printListRecursion(Node* node) {
    if(node == NULL) {
        printf("\n");
        return;
    } 

    printf("%d ",node->number);
    printListRecursion(node->next);
}

void reversePrintListRecursion(Node* node) {
    if(node == NULL) {
        return;
    } 
    reversePrintListRecursion(node->next);
    printf("%d ",node->number);
}

void reverseRecursion(Node** head, Node* p) {
    if(p->next == NULL) {
       *head = p;
       return;
    } 

    reverseRecursion(head, p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

void reverse(Node** head) {
    struct Node* current;
    struct Node* prev;
    struct Node* next;

    current = *head;
    prev = NULL;

    if(current == NULL || current->next == NULL) return;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

int main(){
    struct Node* head = NULL;
    // int n,i,x;
    
    // printf("What is the size of the list?\n");
    // scanf("%d", &n);
    
    // for(i=0; i<n; i++) {
    //     printf("Enter the number...\n");
    //     scanf("%d", &x);
    //     addAtTheBeggin(&head, x);
    // }

    addInPosition(&head, 2,1);
    addInPosition(&head, 3,2);
    addInPosition(&head, 4,3);
    addInPosition(&head, 5,4);

    reverseRecursion(&head, head);

    // reversePrintListRecursion(head);

    // reverse(&head);

    // reversePrintListRecursion(head);

    // removeInPosition(&head, 2);
    // removeInPosition(&head, 2);

    printList(head);
}
