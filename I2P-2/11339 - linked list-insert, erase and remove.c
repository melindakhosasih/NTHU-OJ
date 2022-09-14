#ifndef NODE
#define NODE
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct node
{
	struct node *next;
	struct node *prev;
	unsigned short val;
} Node;

void do_I(Node **head,size_t pos,unsigned short val);
void do_E(Node **head,size_t begin_pos,size_t end_pos);
void do_P(Node  *head,size_t pos);
void do_R(Node **head,unsigned short val);
void do_S(Node  *head);

void do_I(Node **head,size_t pos,unsigned short val){
    int idx = 0;
    Node *node = (Node*)malloc(sizeof(Node));
    Node *curr = *head;
    node->prev = node->next = NULL;
    node->val = val;
    if(*head == NULL){
        *head = node;
        return;
    }
    while(curr->next != NULL || idx == pos){
        if(idx == pos){
            if(curr->prev){
                curr->prev->next = node;
                node->next = curr;
                node->prev = curr->prev;
                curr->prev = node;
            }
            else {
                node->next = (*head);
                (*head)->prev = node;
                (*head) = node;
            }
            return;
        }
        curr = curr->next;
        idx++;
    }
    curr->next = node;
    node->prev = curr;
}
void do_E(Node **head,size_t begin_pos,size_t end_pos){
    Node *temp = *head;
    if(begin_pos == end_pos) return;
    int idx = end_pos - begin_pos;
    while(begin_pos-- && temp) temp = temp->next;
    while(idx-- && temp){
        Node *del = temp;
        if(temp->prev) temp->prev->next = temp->next;
        else (*head) = (*head)->next;
        if(temp->next) temp->next->prev = temp->prev;
        temp = temp->next;
        free(del);
    }
}
void do_P(Node  *head,size_t pos){
    Node *temp = head;
    while(pos-- && temp) {
        if(temp->next == NULL) break;
        temp = temp->next;
    }
    if(temp) printf("%d ", temp->val);
}
void do_R(Node **head,unsigned short val){
    Node *temp = *head;
    while(temp != NULL){
        if(temp->val == val){
            Node *del = temp;
            if(temp->prev) temp->prev->next = temp->next;
            else (*head) = (*head)->next;
            if(temp->next) temp->next->prev = temp->prev;
            temp = temp->next;
            free(del);
        }
        else temp = temp->next;
    }
}
void do_S(Node  *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
}
#endif
