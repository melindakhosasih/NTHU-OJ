#include <stdio.h>
#include <stdlib.h>
#define maxn 200010
typedef struct Node{
    int val, op;
    struct Node *left, *right, *parent;
} Node;
int idx;
char str[maxn * 5];
Node *node[maxn];
Node *build(Node*);
Node *newNode(int, Node*);
int main(){
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        int n, m;
        scanf("%d%d%s", &n, &m, str);
        idx = 0;
        Node *root = build(NULL);
        for(int i = 0; i < m; i++){
            int x;
            scanf("%d", &x);
            Node *curr = node[x];
            curr->val ^= 1;
            while(curr != root){
                Node* par = curr->parent;
                if(par->op == '&')
                    par->val = par->left->val & par->right->val;
                else
                    par->val = par->left->val | par->right->val;
                curr = par;
            }
            printf("%d\n", root->val);
        }
    }
}
Node *build(Node* par){
    if(str[idx] == '|' || str[idx] == '&'){
        Node *op = newNode(str[idx], par);
        idx++;
        op->left = build(op);
        op->right = build(op);
        return op;
    }
    idx++;
    int sum = 0;
    while(str[idx] >= '0' && str[idx] <= '9'){
        sum = sum * 10 + str[idx] - '0';
        idx++;
    }
    idx++;
    node[sum] = newNode(0, par);
    return node[sum];
}
Node *newNode(int ch, Node* par){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->op = ch;
    temp->val = 0;
    temp->parent = par;
    temp->left = temp->right = NULL;
    return temp;
}
