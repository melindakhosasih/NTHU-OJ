#include <iostream>
#include <string>
using namespace std;
template <class T>
class Stack {
public:
    Stack() {
        size = -1;
        stack = new T [capacity][5];
    }
    ~Stack() {}
    bool isEmpty() const {
        if(size == -1) return true;
        else return false;
    }
    bool isFull() const {
        if(size+1 == capacity) return true;
        else return false;
    }
    void push (T a, T b) {
        stack[++size][0] = a;
        stack[++size][1] = b;
    }
    void pop() {
        if(!isEmpty()) size--;
    }
    T top() const {
        return stack[size];
    }
    T element (int idx) {
        return stack[idx];
    }
    int stack_size() const {return size;}
private:
    T **stack;
    int size;
    int capacity = 200005;
};

int calculate(int a, int b) {
    int ans = a*b;
    cout << a << " " << b << " " /*<< c << " "*/ << ans << endl;
    return ans;
}

int main () {
    int n;
    cin >> n;
    int arr[30][5];
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        int idx = c-65;
        cin >> arr[idx][0] >> arr[idx][1];
    }
    int q;
    cin >> q;
    while(q--) {
        Stack<char> *op;
        Stack<int> *ans;
        string str;
        cin >> str;
        int cnt = 0;
        int len = str.length();
        for(int i = 0; i < len; i++) {
        }
    }
    cout << endl;
}
