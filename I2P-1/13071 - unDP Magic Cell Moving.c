#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next[4];
} Node;
int reverse[4] = {2, 3, 0, 1};
Node *create(Node* value, int direction, int number){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = number;
    temp->next[direction] = value;
    return temp;
}
int main(){
    Node *loc;
    loc = create(NULL, 0, 0);
    int cases, number, direction, type;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d%d", &direction, &number);
            if(loc->next[direction] == NULL) loc->next[direction] = create(loc, reverse[direction], number);
            else printf("Invalid\n");
        }
        else if(type == 2){
            scanf("%d", &direction);
            if(loc->next[direction] != NULL) loc = loc->next[direction];
            else printf("Invalid\n");
        }
        else if(type == 3){
            scanf("%d", &number);
            loc->data = number;
        }
        else if(type == 4){
            printf("%d\n", loc->data);
        }
    }
}
