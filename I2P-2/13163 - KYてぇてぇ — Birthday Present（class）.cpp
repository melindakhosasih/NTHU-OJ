#include <iostream>
#include "function.h"
using namespace std;
int idx = 0;
KuoYangPresent::KuoYangPresent(int k) {
    sz = 0;
    this->k = k;
    head = mid = tail = NULL;
}

void KuoYangPresent::Push(int x) {
    Node *node = new Node;
    node->val = x;
    node->tag = idx;
    node->prev = node->next = NULL;
    if(head == NULL)
        head = mid = tail = node;
    else {
        tail->next = node;
        node->prev = tail;
        tail = tail->next;
        if(sz % 2 == 0) mid = mid->next;
    }
    sz++;
}

void KuoYangPresent::Pop(void) {
    if(sz != 0) {
        Node *del = mid;
        if (mid == tail) head = head->next, mid = mid->next, tail = tail->next;
        else if (mid == head) head = head->next, mid = mid->next;
        else {
            mid->next->prev = mid->prev;
            mid->prev->next = mid->next;
            if (sz % 2 == 0) mid = mid->next;
            else mid = mid->prev;
        }
        sz--;
        delete del;
    }
}

void KuoYangPresent::ProgrammingTanoshi(void) {
    idx++;
}

void KuoYangPresent::KuoYangTeTe(void) {
    Node *curr = head;
    if (idx) {
        while (curr != NULL) {
            if (curr->tag < idx)
                curr->val %= k;
            curr = curr->next;
        }
    }
}

void KuoYangPresent::PrintList(void) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->val << ' ';
        curr = curr->next;
    }
    cout << endl;
}
