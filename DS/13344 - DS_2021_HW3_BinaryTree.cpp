#include <iostream>
#include <limits>
#include <string>
using namespace std;

struct Node {
    int data, sum, alliance_path;
    Node *left, *right, *parent;
    Node() : data(0), sum(0), alliance_path(0), left(NULL), right(NULL), parent(NULL) {}
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

//template <class T>
class Tree {
public:
    Tree() : root(NULL), weight(0), max_path_weight(INT8_MIN), binary_tower(0), foldable(true), kingdom(0), invert(0) {}
    ~Tree() {
        deleteTree(root);
    }
    void deleteTree(Node *curr);
    void Construct_tree (string str);
    void Traverse ();
    void preorder (Node *curr);
    void inorder (Node *curr);
    void postorder (Node *curr);
    long long WeightSum ();
    long long MaximumPathSum ();
    void SearchMax(Node *curr);
    int BinaryTower ();
    void CheckTower();
    int BuildTower(Node *curr);
    void Foldable();
    void fold();
    bool mirror(Node *a, Node *b);
    int KingdomUnitedPath();
    void CheckKingdom(Node *curr);
    void DeleteLeaf();
    void deleteleaf(Node *curr);
    void Invert();
private:
    Node *root;
    long long weight;
    long long max_path_weight;
    int binary_tower;
    bool foldable;
    int kingdom;
    int invert;
};

void Tree::deleteTree(Node *root) {
    if(root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void Tree::Construct_tree(string str) {
    Stack<char> parenthesis;
    int len = str.length();
    int going_up[10005] = {0};
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
            temp->sum = val;
            if(root == NULL) root = curr = temp;
            else {
                temp->parent = curr;
                if(!right) {
                    curr->left = temp;
                    curr = curr->left;
                } else {
                    curr->right = temp;
                    curr = curr->right;
                }
                curr->sum += curr->parent->sum;
            }
            right = 0;
            weight += val;
        }
    }
    SearchMax(root);
    fold();
    CheckTower();
    CheckKingdom(root);
}

void Tree::Traverse() {
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
}

void Tree::preorder(Node *curr) {
    if(curr == NULL) return;
    if(!invert) {
        cout << curr->data << " ";
        preorder(curr->left);
        preorder(curr->right);
    } else {
        cout << curr->data << " ";
        preorder(curr->right);
        preorder(curr->left);
    }
}

void Tree::inorder(Node *curr) {
    if(curr == NULL) return;
    if(!invert) {
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    } else {
        inorder(curr->right);
        cout << curr->data << " ";
        inorder(curr->left);
    }
}

void Tree::postorder(Node *curr) {
    if(curr == NULL) return;
    if(!invert) {
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << " ";
    } else {
        postorder(curr->right);
        postorder(curr->left);
        cout << curr->data << " ";
    }
}

long long Tree::WeightSum() {
    if(root == NULL) return 0;
    return weight;
}

long long Tree::MaximumPathSum() {
    if(root == NULL) return 0;
    else return max_path_weight;
}

void Tree::SearchMax(Node *curr) {
    if(curr == NULL) return;
    if(!curr->left && !curr->right && (curr->sum > max_path_weight)) max_path_weight = curr->sum;
    SearchMax(curr->left);
    SearchMax(curr->right);
}

int Tree::BinaryTower() {
    return binary_tower;
}

void Tree::CheckTower() {
    if(root == NULL) binary_tower = 0;
    else {
        if(BuildTower(root) == 0) binary_tower++;
    }
}

int Tree::BuildTower(Node *curr) {
    if(curr == NULL) return 1;
    else {
        int left = BuildTower(curr->left);
        int right = BuildTower(curr->right);
        if(left == 0 || right == 0) {
            binary_tower++;
            return 2;
        } else if (left == 2 || right == 2) return 1;
        else return 0;
    }
}

void Tree::Foldable() {
    if(foldable) cout << "Yes" << endl;
    else cout << "No" << endl;
}

void Tree::fold() {
    if(root == NULL) foldable = true;
    else {
        if(mirror(root->left, root->right)) foldable = true;
        else foldable = false;
    }
}

bool Tree::mirror(Node *a, Node *b) {
    if(!a && !b) return true;
    if((!a && b) || (a && !b)) return false;
    return (mirror(a->left, b->right) && mirror(a->right, b->left));
}

int Tree::KingdomUnitedPath() {
    return kingdom;
}

void Tree::CheckKingdom(Node *curr) {
    if(curr == NULL) return;
    CheckKingdom(curr->left);
    CheckKingdom(curr->right);
    if(curr->parent) {
        if(curr->data == curr->parent->data) {
            if(curr->parent->left == curr) {
                curr->parent->alliance_path = curr->alliance_path + 1;
                if(curr->parent->alliance_path > kingdom) kingdom = curr->parent->alliance_path;
            } else if (curr->parent->right == curr) {
                if(curr->parent->alliance_path == 0) {
                    curr->parent->alliance_path = curr->alliance_path + 1;
                    if(curr->parent->alliance_path > kingdom) kingdom = curr->parent->alliance_path;
                } else {
                    if(kingdom < (curr->parent->alliance_path + curr->alliance_path + 1)) kingdom = curr->parent->alliance_path + curr->alliance_path + 1;
                    if(curr->parent->alliance_path < curr->alliance_path + 1) {
                        curr->parent->alliance_path = curr->alliance_path + 1;
                    }
                }
            }
        }
    }
}

void Tree::DeleteLeaf() {
    if(root == NULL) return;
    else {
        max_path_weight = INT8_MIN;
        kingdom = 0;
        deleteleaf(root);
        fold();
        CheckTower();
        CheckKingdom(root);
    }
}

void Tree::deleteleaf (Node *curr) {
    if(curr == NULL) return;
    if(!curr->left && !curr->right) {
        if(!curr->parent) {
            delete root;
            root = NULL;
            return;
        } else if(curr->parent->left == curr) {
            curr->parent->left = NULL;
            if(curr->parent->right) if(binary_tower) binary_tower--;
        } else if(curr->parent->right == curr) curr->parent->right = NULL;
        weight -= curr->data;
        delete curr;
        curr = curr->parent;
        if(max_path_weight < curr->sum) max_path_weight = curr->sum;
    } else {
        curr->alliance_path = 0;
        deleteleaf(curr->left);
        deleteleaf(curr->right);
    }
}

void Tree::Invert() {
    if(invert) invert = 0;
    else invert = 1;
}

int main() {
    string str, cmd;
    while(cin >> str) {
        Tree tree;
        tree.Construct_tree(str);
        while (cin >> cmd) {
            if(cmd == "Traverse") tree.Traverse();
            else if(cmd == "WeightSum") cout << tree.WeightSum() << endl;
            else if(cmd == "MaximumPathSum") cout << tree.MaximumPathSum() << endl;
            else if(cmd == "BinaryTower") cout << tree.BinaryTower() << endl;
            else if(cmd == "Foldable") tree.Foldable();
            else if(cmd == "KingdomUnitedPath") cout << tree.KingdomUnitedPath() << endl;
            else if(cmd == "DeleteLeaf") tree.DeleteLeaf();
            else if(cmd == "Invert") tree.Invert();
            else if(cmd == "End") {
                cout << endl;
                break;
            }
        }

    }
}
