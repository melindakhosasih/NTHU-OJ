#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdio.h>

typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void printInfix(Node *root){
    if(root == NULL) return;
    printInfix(root->left);
    printf("%c", root->data);
    if(root->right && root->right->left) printf("(");
    printInfix(root->right);
    if(root->right && root->right->left) printf(")");
}

#endif
