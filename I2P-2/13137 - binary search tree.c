#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct _Tree_Node{
    int number;
    struct _Tree_Node* parent;
    struct _Tree_Node* left;
    struct _Tree_Node* right;
}Tree_Node;

Tree_Node* tree_head = NULL, *temp;

void add_node(int n){
    temp = tree_head;
    if(tree_head == NULL){
        temp = tree_head = (Tree_Node*)malloc(sizeof(Tree_Node));
        temp->number = n;
        temp->parent = temp->left = temp->right = NULL;
    }
    else{
        while(temp){
            if(n < temp->number){
                if(temp->left == NULL){
                    temp->left = (Tree_Node*)malloc(sizeof(Tree_Node));
                    temp->left->number = n;
                    temp->left->parent = temp;
                    temp->left->left = temp->left->right = NULL;
                    break;
                }
                else temp = temp->left;
            }
            else{
                if(temp->right == NULL){
                    temp->right = (Tree_Node*)malloc(sizeof(Tree_Node));
                    temp->right->number = n;
                    temp->right->parent = temp;
                    temp->right->left = temp->right->right = NULL;
                    break;
                }
                else temp = temp->right;
            }
        }
    }
}
void showtree(Tree_Node* treenow){
    if(treenow == NULL)
        return;
    showtree(treenow->left);
    printf("%d ", treenow->number);
    showtree(treenow->right);
}

#endif


