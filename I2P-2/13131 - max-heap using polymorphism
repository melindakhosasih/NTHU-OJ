#include <iostream>
#include "function.h"

Array_MAX_HEAP::Array_MAX_HEAP() : MAX_HEAP() {}

void Array_MAX_HEAP::PUSH(const int &a) {
    Count++;
    array[Count] = a;
    for(int i = Count; array[i] > array[i/2] && i/2 >= 1; i/=2) {
        int temp = array[i];
        array[i] = array[i/2];
        array[i/2] = temp;
    }
}

int Array_MAX_HEAP::POP() {
    if(Count == 0) return -1;
    else {
        int ans = array[1];
        array[1] = array[Count];
        Count--;
        for(int i = 1; i*2 <= Count;) {
            int temp;
            if((i*2+1) <= Count) {
                if(array[i*2] > array[i*2 + 1] && array[i] < array[i*2]) {
                    temp = array[i];
                    array[i] = array[i*2];
                    array[i*2] = temp;
                    i = i*2;
                }
                else if(array[i*2] < array[i*2 + 1] && array[i] < array[i*2+1]) {
                    temp = array[i];
                    array[i] = array[i*2+1];
                    array[i*2+1] = temp;
                    i = i*2+1;
                }
                else break;
            }
            else {
                if(array[i] < array[i*2]) {
                    temp = array[i];
                    array[i] = array[i*2];
                    array[i*2] = temp;
                    i = i*2;
                }
                else break;
            }
        }
        return ans;
    }
}

int Array_MAX_HEAP::MAX() const {
    if(Count == 0) return -1;
    else return array[1];
}

List_MAX_HEAP::List_MAX_HEAP() : MAX_HEAP() {
    root = NULL;
}

void List_MAX_HEAP::PUSH(const int &a) {
    Count++;
    if(root == NULL) {
        root = new ListNode(a);
        root->left = root->right = root->parent = NULL;
    }
    else {
        ListNode* curr = NULL;
        ListNode* par = this->findparent(Count, root);
        if(par->left != NULL) {
            par->right = new ListNode(a);
            curr = par->right;
            curr->parent = par;
            curr->left = curr->right = NULL;
        }
        else {
            par->left = new ListNode(a);
            curr = par->left;
            curr->parent = par;
            curr->left = curr->right = NULL;
        }
        while(curr->parent != NULL) {
            if(curr->value > curr->parent->value) {
                int temp = curr->value;
                curr->value = curr->parent->value;
                curr->parent->value = temp;
                curr = curr->parent;
            }
            else break;
        }
    }
}

int List_MAX_HEAP::POP() {
    if(Count == 0) return -1;
    else {
        int ans = root->value;
        ListNode *par = findparent(Count, root);
        Count--;
        if(par->left == NULL && par->right == NULL) {
            root = NULL;
            delete root;
        }
        else if(par->left != NULL && par->right == NULL) {
            root->value = par->left->value;
            par->left = NULL;
            delete par->left;
        }
        else {
            root->value = par->right->value;
            par->right = NULL;
            delete par->right;
        }
        ListNode *curr = root;
        while(curr != NULL) {
            if(curr->left != NULL && curr->right != NULL) {
                if(curr->left->value > curr->right->value && curr->value < curr->left->value) {
                    int temp = curr->value;
                    curr->value = curr->left->value;
                    curr->left->value = temp;
                    curr = curr->left;
                }
                else if(curr->left->value < curr->right->value && curr->value < curr->right->value) {
                    int temp = curr->value;
                    curr->value = curr->right->value;
                    curr->right->value = temp;
                    curr = curr->right;
                }
                else break;
            }
            else if (curr->left != NULL){
                if(curr->value < curr->left->value) {
                    int temp = curr->value;
                    curr->value = curr->left->value;
                    curr->left->value = temp;
                    curr = curr->left;
                }
                else break;
            }
            else break;
        }
        return ans;
    }
}

int List_MAX_HEAP::MAX() const{
    if(Count == 0) return -1;
    else return root->value;
}

void List_MAX_HEAP::deleteTree(ListNode* root) {
    if(root == NULL) return;
    if(root->left) deleteTree(root->left);
    if(root->right) deleteTree(root->right);
    delete root;
}
