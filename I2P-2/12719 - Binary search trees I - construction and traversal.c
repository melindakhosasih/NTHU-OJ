#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000006

typedef struct Node
{
    int key;
    struct Node *ltree;
    struct Node *rtree;
} Node ;

Node *head, *temp;
// build a binary search tree with given pre-order traversal
// return pointer to root
Node *buildBST(int n, int *preOrder){
    static int min = -1, max = 2147483647, idx = 0;
    if(preOrder[idx] == -1 || preOrder[idx] < min || preOrder[idx] > max) return NULL;
    Node *root = (Node*)malloc(sizeof(Node));
    root->key = preOrder[idx];
    preOrder[idx++] = -1;
    if(idx >= n){
        min = -1;
        max = 2147483647;
        idx = 0;
        root->ltree = root->rtree = NULL;
        return root;
    }
    int temp = max;
    max = root->key;
    root->ltree = buildBST(n, preOrder);
    max = temp;

    temp = min;
    min = root->key;
    root->rtree = buildBST(n, preOrder);
    min = temp;
    return root;
}

// print the in-order traversal of a given tree
// it is suggested to implement using recursion
void printInOrder(Node *ptr){
    if(ptr == NULL) return;
    printInOrder(ptr->ltree);
    printf("%d ", ptr->key);
    printInOrder(ptr->rtree);
}

// print the post-order traversal of a given tree
// it is suggested to implement using recursion
void printPostOrder(Node *ptr){
    if(ptr == NULL) return;
    printPostOrder(ptr->ltree);
    printPostOrder(ptr->rtree);
    printf("%d ", ptr->key);
}

// delete the binary search tree in case of memory leak
// it is suggested to implement using recursion
void freeTree(Node *ptr){
    Node *del = ptr;
    if(ptr == NULL) return;
    freeTree(ptr->ltree);
    freeTree(ptr->rtree);
    free(del);
}

#endif // FUNCTION_H_