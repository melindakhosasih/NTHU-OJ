#ifndef FUNCTION_H
#define FUNCTION_H

#define MAXEXPR 256
#define NUMSYM 6
#include <stdio.h>
#include <stdlib.h>

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

BTNode* EXPR(){
    char c;
    BTNode *node = NULL, *right = NULL;
    if(pos >= 0){
        right = FACTOR();
        if(pos > 0){
            c = expr[pos];
            if(c == '&' || c == '|'){
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
BTNode* FACTOR(){
    char c;
    BTNode *node = NULL;
    if(pos >= 0){
        c = expr[pos--];
        if(c >= 'A' && c <= 'D') node = makeNode(c);
        else if(c == ')'){
            node = EXPR();
            if(expr[pos--] != '('){
                printf("Error\n");
                freeTree(node);
            }
        }
    }
    return node;
}
BTNode* makeNode(char c){
    BTNode *node = (BTNode*)malloc(sizeof(BTNode));
    for(int i = 0; i < NUMSYM; i++)
        if(c == sym[i]) node->data = i;
    node->left = node->right = NULL;
    return node;
}

#endif
