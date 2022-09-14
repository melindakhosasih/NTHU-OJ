#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    unsigned long long idx, level;
    Node *left, *right, *parent;
    Node() : data(0), idx(1), level(0), left(NULL), right(NULL), parent(NULL) {}
};

template <class T>
class Stack {
public:
    Stack() {
        size = -1;
        capacity = 10000;
        stack = new T [capacity];
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
    void push (T val) {
        if(size == capacity - 1) {
            capacity *= 2;
            T *arr = new T [capacity];
            for(int i = 0; i < size; i++) arr[i] = stack[i];
            delete [] stack;
            stack = arr;
        }
        stack[++size] = val;
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
    int stack_size() const {
        return size;
    }
private:
    T *stack;
    int size;
    int capacity = 10000;
};

class Tree {
public:
    Tree() : root(NULL), jump(0), max_jump(0) {}
    ~Tree() {
        delete_tree(root);
    }
    void Construct_tree (string str);
    void delete_tree(Node *curr);
    void jump_count(Node *a, Node *b);
    unsigned long long ans ();

private:
    Node *root;
    unsigned long long jump;
    unsigned long long max_jump;
};

void Tree::Construct_tree(string str) {
    Stack<char> parenthesis;
    int len = str.length();
    int going_up[10005] = {0};
    unsigned long long lvl[80000][3] = {0};
    int right = 0;
    Node *curr = NULL;
    for(int i = 0; i < len; i++) {
        char c = str[i];
        if(c == '(') {
            parenthesis.push(c);
            going_up[parenthesis.stack_size()]++;
        } else if (c == ')') {
            if(going_up[parenthesis.stack_size()] == 2 && curr->parent != NULL) {
                going_up[parenthesis.stack_size()] = 0;
                curr = curr->parent;
            }
            right = 1;
            parenthesis.pop();
        } else {
            int neg = 0;
            int val = 0;
            if(c == '-') {
                neg = 1;
                c = str[++i];
            }
            while(isdigit(c)) {
                val = val*10 + (c - '0');
                c = str[++i];
            }
            i--;
            if(neg) val *= -1;

            Node *temp = new Node;
            temp->data = val;
            //temp->idx = 1;
            if(root == NULL) {
                root = curr = temp;
            } else {
                temp->parent = curr;
                temp->level = temp->parent->level + 1;
                if(!right) {
                    temp->idx = curr->idx * 2;
                    curr->left = temp;
                    curr = curr->left;
                } else {
                    temp->idx = curr->idx * 2 + 1;
                    curr->right = temp;
                    curr = curr->right;
                }
            }
            if(lvl[curr->level][0] == 0 && lvl[curr->level][1] == 0) {
                lvl[curr->level][0] = lvl[curr->level][1] = curr->idx;
            } else {
                if(lvl[curr->level][1] < curr->idx) {
                    lvl[curr->level][1] = curr->idx;
                    if(max_jump < (curr->idx - lvl[curr->level][0] + 1)) max_jump = curr->idx - lvl[curr->level][0] + 1;
                }
            }
            right = 0;
        }
    }
}

void Tree::delete_tree(Node *root) {
    if(root == NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

void Tree::jump_count(Node *a, Node *b) {
    if((!a || !b) || (a->level != b->level)) return;
    else {
        if((b->idx - a->idx) + 1 > max_jump) max_jump = b->idx - a->idx + 1;
    }
    jump_count(a->left, a->right);
    jump_count(b->left, b->right);
    jump_count(a->left, b->right);
    jump_count(a->right, b->left);
    jump_count(a->left, b->left);
    jump_count(a->right, b->right);
}

unsigned long long Tree::ans () {
    if(root == NULL) return 0;
    //jump_count(root->left, root->right);
    return max_jump;
}

int main () {
    string str;
    while(cin >> str) {
        Tree tree;
        tree.Construct_tree(str);
        cout << tree.ans() << endl;
    }
}
