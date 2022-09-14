#include <stdlib.h>
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* Partial_sort(Node*, int);
Node* Split_and_Swap(Node*, int, int);

Node* Partial_sort(Node* head, int max){
    Node *temp1 = NULL, *front, *mid = NULL, *temp2 = NULL;
    while(head != NULL){
        if(head->data < max){
            Node *del = head;
            if(temp1 == NULL) front = temp1 = (Node*)malloc(sizeof(Node));
            else temp1 = temp1->next = (Node*)malloc(sizeof(Node));
            temp1->data = head->data;
            head = head->next;
            free(del);
        }
        else{
            if(temp2 == NULL) mid = temp2 = (Node*)malloc(sizeof(Node));
            else temp2 = temp2->next = (Node*)malloc(sizeof(Node));
            temp2->data = head->data;
            head = head->next;
        }
    }
    if(temp2 != NULL) temp2->next = NULL;
    if(temp1 != NULL) temp1->next = mid;
    if(temp1 == NULL) return mid;
    return front;
}

Node* Split_and_Swap(Node* head, int a, int b){
    Node *temp1, *temp2, *front, *mid, *clone = NULL, *del, *end;
    if(b - a != 1) mid = clone = (Node*)malloc(sizeof(Node));
    end = temp1 = (Node*)malloc(sizeof(Node));
    front = temp2 = (Node*)malloc(sizeof(Node));
    while(a-- && b--){
            del = head;
            temp1->data = head->data;
            temp1 = temp1->next = (Node*)malloc(sizeof(Node));
            head = head->next;
            free(del);
    }
    if(a == -1){
        del = head;
        temp1->data = head->data;
        temp1->next = NULL;
        head = head->next;
        free(del);
        b--;
    }
    while(b != 0){
        del = head;
        clone->data = head->data;
        if(b != 1) clone = clone->next = (Node*)malloc(sizeof(Node));
        head = head->next;
        free(del);
        b--;
    }
    if(clone != NULL) clone->next = end;
    while(head != NULL){
        del = head;
        temp2->data = head->data;
        if(head->next != NULL) temp2 = temp2->next = (Node*)malloc(sizeof(Node));
        head = head->next;
        free(del);
    }
    if(clone != NULL) temp2->next = mid;
    else temp2->next = end;
    return front;
}
