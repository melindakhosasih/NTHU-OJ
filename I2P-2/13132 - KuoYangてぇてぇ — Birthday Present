#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdlib.h>

typedef struct _Node{
    struct _Node *prev;
    struct _Node *next;
    int val;
    int tag;
}Node;

int n, k, q, idx = 0, mod = 0;
Node *head = NULL, *temp, *mid;

void push(int x);
void pop();
void programming_tanoshi();
void KuoYangTeTe();

void push(int x){
    if(head == NULL) {
        head = temp = (Node*)malloc(sizeof(Node));
        head->val = x;
        head->tag = mod;
        head->prev = head->next = NULL;
        mid = head;
        idx++;
    }
    else{
        while(temp){
            if(temp->next == NULL) {
                temp->next = (Node*)malloc(sizeof(Node));
                temp->next->val = x;
                temp->next->tag = mod;
                temp->next->prev = temp;
                temp->next->next = NULL;
                idx++;
                if(idx % 2) mid = mid->next;
                break;
            }
            else temp = temp->next;
        }
    }
}
void pop(){
    Node *del = mid;
    if(mid->prev) mid->prev->next = mid->next;
    if(mid->next) mid->next->prev = mid->prev;
    if(idx % 2 == 0) mid = mid->next;
    else mid = mid->prev;
    idx--;
    free(del);
}
void programming_tanoshi(){
    mod++;
}
void KuoYangTeTe(){
    Node *curr = head;
    if(mod){
        while(curr){
            if(curr->tag < mod) curr->val %= k;
            curr = curr->next;
        }
    }
}
#endif
