#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
    int a;
    int b;
    struct _node *next;
} Node;
int main(){
    int n, a, b, degree[5005] = {0}, min;
    Node *head = NULL, *temp;
    Node *print, *link;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &a, &b);
        if(head == NULL) head = temp = (Node*)malloc(sizeof(Node));
        else temp = temp->next = (Node*)malloc(sizeof(Node));
        temp->a = a;
        temp->b = b;
        degree[a]++;
        degree[b]++;
    }
    temp->next = NULL;
    for(int i = 0; i < n-2; i++){
        temp = head;
        min = 5005;
        if(degree[temp->a] == 1){
            if(min > temp->a){
                min = temp->a;
                print = temp;
            }
        }
        else if(degree[temp->b] == 1){
            if(min > temp->b){
                min = temp->b;
                print = temp;
            }
        }
        while(temp->next){
            if(degree[temp->next->a] == 1){
                if(min > temp->next->a){
                    min = temp->next->a;
                    print = temp->next;
                    link = temp;
                }
            }
            else if(degree[temp->next->b] == 1){
                if(min > temp->next->b){
                    min = temp->next->b;
                    print = temp->next;
                    link = temp;
                }
            }
            temp = temp->next;
        }
        if(print == head) head = head->next;
        else link->next = temp->next;
        if(min == print->a) printf("%d ", print->b);
        else printf("%d ", print->a);
        degree[print->a]--;
        degree[print->b]--;
        free(print);
    }
    printf("\n");
}
