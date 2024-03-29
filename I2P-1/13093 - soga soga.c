#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
} block;
int main(){
    int n, cases, type, direction, num;
    block *temp, *loc, *start, *mid;
    start = temp = (block*)malloc(sizeof(block));
    temp->data = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        temp->next = (block*)malloc(sizeof(block));
        temp->next->data = num;
        temp->next->prev = temp;
        temp = temp->next;
    }
    temp->next = (block*)malloc(sizeof(block));
    temp->next->data = NULL;

    loc = mid = start->next;
    int del;
    if(n % 2 == 0) del = n/2;
    else del = n/2 + 1;
    del--;
    while(del--) mid = mid->next;

    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d", &direction);
            if(direction == -1) loc = loc->prev;
            else loc = loc->next;
        }
        else if(type == 2){
            printf("%d\n", loc->data);
        }
        else if(type == 3){
            block *remove = mid;
            block *clone = mid;
            if (n % 2 == 0) mid = mid->next;
            else mid = mid->prev;
            n -= 1;
            if(loc == remove) loc = loc->next;
            clone->next->prev = clone->prev;
            clone->prev->next = clone->next;
            clone = clone->next;
            free(remove);
        }
    }
}
