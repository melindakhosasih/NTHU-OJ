#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node **next;
} Node;

int check(int);
int number[100005] = {0}, roots[100005] = {0};
Node *tree[100005];

int main(){
    int n;
    scanf("%d", &n);
    int a[100005], b[100005];
    for(int i = 1; i < n; i++){
        scanf("%d%d", &a[i], &b[i]);
        roots[a[i]]++;
        if(roots[b[i]] != 0) roots[b[i]]++;
    }
    for(int i = 1; i <= n ;i++){
        tree[i] = (Node*)malloc(sizeof(Node));
        tree[i]->data = i;
        tree[i]->next = (Node**)malloc(sizeof(Node)*roots[i]);
    }
    for(int i = 1; i < n; i++) tree[a[i]]->next[number[a[i]]++] = tree[b[i]];
    for(int i = 1; i <= n; i++){
        int count = 0;
        count = check(i);
        count += number[i];
        if(i != n) printf("%d ", count);
        else printf("%d\n", count);
    }
    return 0;
}

int check(int head){
    int sum = 0;
    for(int i = 0; i < number[head]; i++){
        int index = tree[head]->next[i]->data;
        //printf("index %d\n", index);
        if(number[index]){
            sum += number[index];
            sum += check(index);
        }
    }
    return sum;
}
