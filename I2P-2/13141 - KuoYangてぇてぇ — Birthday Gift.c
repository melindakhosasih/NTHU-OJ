#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdlib.h>
#include <math.h>

int all_operation[300009];

typedef struct _Node{
    struct _Node *prev;
    struct _Node *next;
    int val;
    int tag; // use this variable to store which operation will be performed on this element
}Node;

Node *head = NULL, *temp, *mid;
int idx = 0, tag = 0;

void push(int x);
void pop();
void programming_tanoshi(int k);
void IP2_sugoi();
void KuoYangTeTe(); //You can either use this function or not depending on how you solve this problem

void push(int x){
    if(head == NULL){
        head = temp = (Node*)malloc(sizeof(Node));
        temp->val = x;
        temp->tag = tag;
        temp->prev = temp->next = NULL;
        mid = temp;
        idx++;
        return;
    }
    else{
        temp->next = (Node*)malloc(sizeof(Node));
        temp->next->val = x;
        temp->next->tag = tag;
        temp->next->next = NULL;
        temp->next->prev = temp;
        idx++;
        if(idx % 2 == 1) mid = mid->next;
        temp = temp->next;
    }
}
void pop(){
    if(idx){
        Node *del = mid;
        if(mid->prev) mid->prev->next = mid->next;
        else head = head->next;
        if(mid->next) mid->next->prev = mid->prev;
        if(idx % 2 == 1) mid = mid->prev;
        else mid = mid->next;
        idx--;
        free(del);
    }
}
void programming_tanoshi(int k){
    all_operation[tag] = k;
    tag++;
}
void IP2_sugoi(){
    tag++;
}
void KuoYangTeTe(){
    Node* curr = head;
    while(curr){
        for(int i = curr->tag; i < tag; i++){
            if(curr->val == 1) break;
            if(all_operation[i]) curr->val = ceil(((double) (curr->val)/all_operation[i]));
            else curr->val = sqrt(curr->val);
        }
        curr = curr->next;
    }
}

#endif
