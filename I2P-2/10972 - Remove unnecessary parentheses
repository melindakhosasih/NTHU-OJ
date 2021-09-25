#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXEXPR 256
char expr[MAXEXPR], sym[6] = "ABCD&|";
int pos;
typedef struct _node{
    char data;
    struct _node *left, *right;
} BTNode;
BTNode *EXPR();
BTNode *FACTOR();
BTNode *makeNode(char c);
void printPrefix (BTNode *root);
void freeTree(BTNode *root);

int main(){
    scanf("%s", expr);
    pos = strlen(expr) - 1;
    BTNode *root = EXPR();
    printPrefix(root);
    freeTree(root);
    return 0;
}
BTNode *EXPR(){
    char c;
    BTNode *node = NULL, *right = NULL;
    if (pos >= 0){
        right = FACTOR();
        if (pos > 0){
            c = expr[pos];
            if(c == '&' | c == '|'){
                node = makeNode(c);
                node->right = right;
                pos--;
                node->left = EXPR();
            }
            else node = right;
        }
        else node = right;
    }
    return node;
}
BTNode *FACTOR(){
    char c;
    BTNode *node = NULL;
    if(pos >= 0){
        c = expr[pos--];
        if(c >= 'A' && c <= 'D') node = makeNode(c);
        else if(c == ')'){
            node = EXPR();
            if(expr[pos--] != '('){
                printf("Error!\n");
                freeTree(node);
            }
        }
    }
    return node;
}
BTNode *makeNode(char c){
    BTNode *node = (BTNode*)malloc(sizeof(BTNode));
    for(int i = 0; i < 6; i++)
        if(c == sym[i]) {node->data = sym[i]; break;}
    node->left = node->right = NULL;
    return node;
}
void printPrefix(BTNode *root){
    if(root == NULL) return;
    printPrefix(root->left);
    printf("%c", root->data);
    if(root->right && root->right->left) printf("(");
    printPrefix(root->right);
    if(root->right && root->right->left) printf(")");
}
void freeTree(BTNode *root){
    if(root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
