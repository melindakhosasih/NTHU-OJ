#include <iostream>
using namespace std;

typedef struct Node{
  int value;
  struct Node *next, *prev;
} Node;

int main () {
    int n;
    cin >> n;
    Node *head = NULL, *tail = NULL;
    long long sum = 0;
    while(n--) {
        int index;
        cin >> index;
        if(!head) {
            head = new Node;
            head->value = index;
            head->prev = head->next = head;
            tail = head;
        } else {
            Node *temp = new Node;
            temp->value = index;
            temp->prev = tail;
            temp->next = head;
            tail->next = temp;
            head->prev = temp;
            tail = tail->next;
        }
        sum++;
    }

    while(1) {
        unsigned long long i, j;
        cin >> i >> j;
        if(i == -1 && j == -1) break;
        if(i == 1) {
            if(sum) {
                //if(sum == 1) break;
                unsigned long long mod = j % sum;
                if(sum == 1) {
                    head = tail = NULL;
                } else {
                    //cout << head->value << " MOD " << mod << endl;
                    while(mod--) {
                        head = head->next;
                    }
                    //cout << head->value << endl;
                    Node *del = head;
                    head = head->next;
                    head->prev = del->prev;
                    del->prev->next = head;
                    delete del;
                }
                sum--;
                if(sum == 1) break;
            }
        } else if (i == 2) {
            Node *temp = new Node;
            temp->value = j;
            temp->prev = temp->next = temp;
            if(sum == 0) {
                head = temp;
            } else  {
                temp->prev = head;
                temp->next = head->next;
                head->next->prev = temp;
                head->next = temp;
            }
            sum++;
        }
    }
    if (head && sum != 1) {
        tail = head->prev;
        while(head != tail) {
            cout << head->value << " ";
            head = head->next;
        }
        cout << tail->value << endl;
    } else if(head && sum == 1) {
        cout << head->value << endl;
    }
}
