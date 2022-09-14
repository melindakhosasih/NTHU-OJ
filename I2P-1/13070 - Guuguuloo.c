#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int index;
    struct node *next;
} Node;

Node *create(int number){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->index = number;
    temp->next = NULL;
    return temp;
}

int cmp (const void *a, const void *b){
    return *(int*)a > *(int*)b;
}

int main(){
    int n, arr[100005], cases;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    Node *np, *nq, *na, *nb, *end;
    np = na = nb = create(0);
    for(int i = 0; i < n; i++) np = np->next = create(arr[i]);
    end = np = np->next = create(0);
    scanf("%d", &cases);
    int type, number;
    while(cases--){
        scanf("%d%d", &type, &number);
        switch(type){
            case 1:
                while(na->next != end && na->next->index < number) na = na->next;
                if(na->next->index == number){
                    nq = na->next;
                    na->next = na->next->next;
                    free(nq);
                }
                break;
            case 2:
                while(nb->next != end && nb->next->index < number) nb = nb->next;
                if(nb->next->index == number) printf("Yes\n");
                else printf("No\n");
                break;
        }
    }
}
