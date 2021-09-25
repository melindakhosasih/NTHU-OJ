#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node{
    int data;
    struct _node *next;
} Node;
int main(){
    int n, casenum, data, a, b;
    char type[5];
    Node *head, *temp = NULL;
    scanf("%d%d", &n, &casenum);
    while(n--){
        scanf("%d", &data);
        if(temp == NULL) head = temp = (Node*)malloc(sizeof(Node));
        else temp = temp->next = (Node*)malloc(sizeof(Node));
        temp->data = data;
    }
    temp->next = NULL;
    while(casenum--){
        scanf("%s%d%d", type, &a, &b);
        temp = head;
        if(strcmp(type, "ADD") == 0){
            Node* add = (Node*)malloc(sizeof(Node));
            add->data = b;
            if(!a){
                add->next = temp;
                head = add;
            }
            else{
                while(--a) temp = temp->next;
                add->next = temp->next;
                temp->next = add;
            }
        }
        else if(strcmp(type, "CUT") == 0){
            if(a){
                Node *cut = NULL, *curr, *link;
                while(a--){
                    link = temp;
                    temp = temp->next;
                }
                while(b--){
                    Node *del;
                    if(cut == NULL) cut = curr = (Node*)malloc(sizeof(Node));
                    else curr = curr->next = (Node*)malloc(sizeof(Node));
                    curr->data = temp->data;
                    del = temp;
                    temp = temp->next;
                    free(del);
                }
                link->next = temp;
                curr->next = head;
                head = cut;
            }
        }
    }
    while(head != NULL) printf("%d\n", head->data), head = head->next;
}
