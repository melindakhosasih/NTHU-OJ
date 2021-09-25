#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
    struct _Node* prev;
}Node;

Node* head, *temp;
int flag;
Node* createList(int n){
    head = NULL;
    for(int i = 1; i <= n; i++){
        if(head == NULL) head = temp = (Node*)malloc(sizeof(Node));
        else{
            temp->next->prev = temp;
            temp = temp->next;
        }
        temp->number = i;
        if(i != n) temp->next = (Node*)malloc(sizeof(Node));
        else temp->next = head, head->prev = temp;
    }
    flag = 1;
    return head;
}
void solveJosephus(int n, int m){
    int idx;
    for(int i = 0; i < m; i++){
        scanf("%d", &idx);
        if(idx % 2 == 0) flag = 0;
        else flag = 1;
        if(i){
            if(flag) head = head->next;
            else head = head->prev;
        }
        idx %= n;
        if(!idx) idx = n;
        if(flag) while(--idx) head = head->next;
        else while(--idx) head = head->prev;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        printf("%d\n", head->number);
        n--;
    }
}


#endif // FUNCTION_H_INCLUDED
