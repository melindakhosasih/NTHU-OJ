#include <stdlib.h>
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* Merge_lists(Node* head1, Node* head2){
    Node *start = NULL, *temp = NULL;
    while(head1 != NULL || head2 != NULL){
        if(temp == NULL) start = temp = (Node*)malloc(sizeof(Node));
        else{
            while (head1 && temp->data == head1->data) head1 = head1->next;
            while (head2 && temp->data == head2->data) head2 = head2->next;
            if(head1 == NULL && head2 == NULL) break;
            temp = temp->next = (Node*)malloc(sizeof(Node));
        }
        if(head1 == NULL){
            temp->data = head2->data;
            head2 = head2->next;
        }
        else if(head2 == NULL){
            temp->data = head1->data;
            head1 = head1->next;
        }
        else if(head1->data <= head2->data){
            temp->data = head1->data;
            head1 = head1->next;
        }
        else{
            temp->data = head2->data;
            head2 = head2->next;
        }
    }
    temp->next = NULL;
    return start;
}
