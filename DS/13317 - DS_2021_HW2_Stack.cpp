#include <iostream>
using namespace std;

class Stack {
public:
    Stack() {
        top = -1;
        stack = new int [capacity];
    }
    ~Stack() {}
    bool isEmpty() const {
        if(top == -1) return true;
        else return false;
    }
    bool isFull() const {
        if(top+1 == capacity) return true;
        else return false;
    }
    void push (int height) {
        stack[++top] = height;
    }
    void pop() {
        if(!isEmpty()) top--;
    }
    int Top() const {
        return stack[top];
    }
    int element (int idx) {
        return stack[idx-1];
    }
    int top_idx() const {return top+1;}
private:
    int *stack;
    int top;
    int capacity = 200005;
};

int main () {
    int n;
    cin >> n;
    Stack player, answer;
    int min = INT8_MAX;
    for(int i = 1; i <= n; i++) {
        int height;
        cin >> height;
        int ans = 0;
        if(!player.isEmpty()) {
            if(min < height) {
                int idx = answer.Top();
                if(player.element(i-1) < height) ans = i-1;
                while(ans == 0) {
                    if(player.element(idx) < height) ans = idx;
                    idx = answer.element(idx);
;                }
            } else min = height;
        } else min = height;
        player.push(height);
        answer.push(ans);
        cout << ans << " ";
    }
    cout << endl;
}
