#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    int deg;
    struct node *next;
} Node;
Node *build(int a, int b);
Node *node[5005];
int flag[5005] = {0};
int main(){
    int vertix;
    scanf("%d", &vertix);
    for(int i = 0;i < vertix-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        build(a, b);
        build(b, a);
    }
    int idx = 0;
    for(int i = 0; i < vertix-2; i++){
        while(node[idx+1] == NULL) idx++;
        for(int j = 1 + idx; j <= vertix; j++){
            if(node[j]->deg == 1){
                while(flag[node[j]->data] == 1){
                    node[j] = node[j]->next;
                }
                printf("%d ", node[j]->data);
                node[node[j]->data]->deg--;
                free(node[j]);
                flag[j] = 1;
                break;
            }
        }
    }
    printf("\n");
}
Node *build(int a, int b){
    if(node[a] == NULL){
        node[a] = (Node*)malloc(sizeof(Node));
        node[a]->data = b;
        node[a]->deg = 1;
        node[a]->next = NULL;
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data = b;
        temp->deg = 0;
        temp->next = node[a]->next;
        node[a]->next = temp;
    }
    else{
        node[a]->deg++;
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data = b;
        temp->deg = 0;
        temp->next = node[a]->next;
        node[a]->next = temp;
    }
}
