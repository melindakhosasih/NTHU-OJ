#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree{
    int data;
    struct tree *left, *right;
} Tree;
typedef struct level{
    int data;
    struct level *next;
} Level;
void printInOrder(Tree *head);
int arr[10005] = {0};
int level[10005] = {0};
int height = 0;
int main(){
    int n, data, idx;
    Tree *head = NULL, *temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        temp = head;
        idx = 1;
        scanf("%d", &data);
        if(head == NULL){
            head = temp = (Tree*)malloc(sizeof(Tree));
            head->data = data;
            head->left = head->right = NULL;
            arr[idx] += data;
            level[idx]++;
            height++;
        }
        else {
            while(temp){
                if(temp->data > data) {
                    idx++;
                    if(temp->left == NULL){
                        temp->left = (Tree*)malloc(sizeof(Tree));
                        temp->left->data = data;
                        temp->left->left = temp->left->right = NULL;
                        arr[idx] += data;
                        level[idx]++;
                        if(idx > height) height = idx;
                        break;
                    }
                    else temp = temp->left;
                }
                else if(temp->data < data){
                    idx++;
                    if(temp->right == NULL){
                        temp->right = (Tree*)malloc(sizeof(Tree));
                        temp->right->data = data;
                        temp->right->left = temp->right->right = NULL;
                        arr[idx] += data;
                        level[idx]++;
                        if(idx > height) height = idx;
                        break;
                    }
                    else temp = temp->right;
                }
                else break;
            }
        }
    }
    int casenum, lvl;
    char type[25];
    scanf("%d", &casenum);
    while(casenum--){
        scanf("%s", type);
        if(strcmp(type, "P") == 0){
            if(head) printInOrder(head);
            else printf("NULL");
            printf("\n");
        }
        else if(strcmp(type, "GetMax") == 0){
            printf("%d\n", height);
        }
        else if(strcmp(type, "SumLevel") == 0){
            scanf("%d", &lvl);
            printf("%d\n", arr[lvl]);
        }
        else if(strcmp(type, "AverLevel") == 0){
            scanf("%d", &lvl);
            if(level[lvl] == 0) printf("0\n");
            else printf("%.3f\n", (float)arr[lvl]/level[lvl]);
        }
    }
}

void printInOrder(Tree *head){
    if(head == NULL) return;
    printInOrder(head->left);
    printf("%d ", head->data);
    printInOrder(head->right);
}
