#include <stdio.h>
#include <stdlib.h>
#define swap(a,b) {a^=b^=a^=b;}
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;
Node* createList(int *a, int size){
    Node *start, *temp;
    start = temp = (Node*)malloc(sizeof(Node));
    for(int i = 0; i < size-1; i++){
        temp->data = a[i];
        temp = temp->next = (Node*)malloc(sizeof(Node));
    }
    temp->data = a[size-1];
    temp->next = NULL;
    return start;
}
void push_front(Node** head, int val){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = *head;
    *head = temp;
}
Node* copyList(Node* head){
    Node* start, *clone;
    start = clone = (Node*)malloc(sizeof(Node));
    while(head->next != NULL){
        clone->data = head->data;
        clone = clone->next = (Node*)malloc(sizeof(Node));
        head = head->next;
    }
    clone->data = head->data;
    clone->next = NULL;
    return start;
}
void deleteElementByIdx(Node** head, int idx){
    Node *temp, *del;
    temp = *head;
    if(idx == 0){
        del = *head;
        *head = (*head)->next;
        return;
    }
    idx -= 1;
    while(idx-- && temp->next != NULL) temp = temp->next;
    if(temp->next == NULL) return;
    del = temp->next;
    temp->next = temp->next->next;
    free(del);
}
void SwapElementByIdx(Node** head, int idx1, int idx2){
    Node *a, *b, *temp;
    temp = *head;
    if(idx1 == 0){
        a = *head;
    }
    else{
        idx1 -= 1;
        while(idx1-- && temp->next != NULL) temp = temp->next;
        if(temp->next == NULL) return;
        a = temp->next;
    }
    temp = *head;
    if(idx2 == 0){
        b = *head;
    }
    else{
        idx2 -= 1;
        while(idx2-- && temp->next != NULL) temp = temp->next;
        if(temp->next == NULL) return;
        b = temp->next;
    }
    swap(a->data, b->data);
}
