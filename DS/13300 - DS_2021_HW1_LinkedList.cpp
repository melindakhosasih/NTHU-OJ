#include <iostream>
using namespace std;

class Node {
public:
    int card;
    Node *head, *next;
    Node() {};
    Node(int start, int finish) {
        head = new Node();
        head->card = start;
        Node *curr = head;
        for(int i = 2; i <= finish; i++) {
            curr->next = new Node();
            curr->next->card = i;
            curr = curr->next;
        }
        curr->next = NULL;
    }
};

int main() {
    int n, m, k, player_joker[1005] = {0};
    cin >> n >> m >> k;
    Node *player[1005];
    while(k--) {
        int joker;
        cin >> joker;
        player_joker[joker-1]++;
        player[joker-1] = new Node(0, m);
    }
    for(int i = 0; i < n; i++) {
        if(!player[i]) {
            player[i] = new Node(1, m);
        }
    }
    int draw, put;
    int A = 0, B;
    while(1) {
        cin >> draw >> put;
        if(draw == -1 && put == -1) break;
        if(A != n-1) B = A+1;
        else B = 0;

        Node *temp = player[B]->head;
        int num;
        if(draw == 1 || !temp->next) {
            if(!temp->next) player[B]->head = NULL;
            else player[B]->head = player[B]->head->next;
            num = temp->card;
            delete temp;
        } else {
            draw--;
            Node* del = temp;
            while(draw-- && del->next) {
                temp = del;
                del = del->next;
            }
            num = del->card;
            temp->next = del->next;
            delete del;
        }
        if(num == 0) player_joker[B]--;

        temp = player[A]->head;
        Node *add = new Node();
        add->card = num;
        if(num == 0) player_joker[A]++;
        if(!temp) {
            add->next = NULL;
            player[A]->head = add;
        } else if(put == 1) {
            add->next = player[A]->head;
            player[A]->head = add;
        } else {
            put--;
            put--;
            while(put-- && temp->next) temp = temp->next;
            add->next = temp->next;
            temp->next = add;
        }
        A = B;
    }
    for(int i = 0; i < n; i++) {
        if(player_joker[i] == 0) {
            Node *temp = player[i]->head;
            while(temp) {
                if(temp->next) cout << temp->card << " ";
                else cout << temp->card;
                temp = temp->next;
            }
            break;
        }
    }
    cout << endl;
}
