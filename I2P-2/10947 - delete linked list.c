#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** head, int data){
    Node *del = *head, *temp = NULL;
    while(--data && del->next){
        temp = del;
        del = del->next;
    }
    if(!data){
        if(!temp) *head = (*head)->next;
        else{
            temp->next = temp->next->next;
            free(del);
        }
    }
}
Node* createList(){
    Node* head, *temp = NULL;
    int data;
    while(1){
        scanf("%d", &data);
        if(data != -1){
            if(temp == NULL) head = temp = (Node*)malloc(sizeof(Node));
            else temp = temp->next = (Node*)malloc(sizeof(Node));
            temp->data = data;
        }
        else break;
    }
    temp->next = NULL;
    return head;
}
