#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int index;
    struct node *next[4];
} Cell;

int reverse[4] = {2, 3, 0, 1};
Cell *Create(Cell*, int, int);

int main(){
    Cell *loc, *portal;
    int cases, type, direction, num;
    loc = portal = Create(NULL, 0, 0);
    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &type);
        switch(type){
            case 1:
                scanf("%d%d", &direction, &num);
                loc->next[direction] = Create(loc, num, reverse[direction]);
                break;
            case 2:
                scanf("%d", &direction);
                loc = loc->next[direction];
                break;
            case 3:
                scanf("%d", &num);
                loc->index = num;
                break;
            case 4:
                printf("%d\n", loc->index);
                break;
            case 5:
                portal = loc;
                break;
            case 6:
                loc = portal;
                break;
        }
    }
    return 0;
}

Cell *Create (Cell* value, int num, int direction){
    Cell *temp = (Cell*)malloc(sizeof(Cell));
    temp->index = num;
    temp->next[direction] = value;
    return temp;
}
