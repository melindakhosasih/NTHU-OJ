#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> //for isdigit()

typedef struct _Node {
    int value;
    char OP;
    struct _Node *left;
    struct _Node *right;
} Node;

char expr[120];
int pos;
Node *head;

Node* Factor();
Node* Expr();
void PrefixPrint(Node* node);

Node* CreateNode(int value , char ch) {
    Node *newNode;
    newNode = (Node*) malloc(sizeof(Node));

    if(ch == 'N') {
        newNode->value = value;
        newNode->OP = 'N';
    }
    else {
        newNode->value = -1;
        newNode->OP = ch;
    }
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    while((scanf("%s" , expr)) != EOF) {
        pos = strlen(expr) - 1;
        head = Expr();
        PrefixPrint(head);
        printf("\n");
        head = NULL;
    }

    return 0;
}

Node* Factor(){
    char c;
    Node *node;
    if(pos >= 0){
        c = expr[pos--];
        int idx = 1;
        int sum = 0;
        if(isdigit(c)){
            while(isdigit(c)){
                sum = sum + (c - '0')*idx;
                idx *= 10;
                c = expr[pos--];
            }
            pos++;
            node = CreateNode(sum, 'N');
        }
        else if(c == ')'){
            node = Expr();
            if(expr[pos--] != '('){
                printf("Error!\n");
            }
        }
    }
    return node;
}
Node* Expr(){
    char c;
    Node *right, *node;
    if(pos >= 0){
        right = Factor();
        if(pos > 0){
            c = expr[pos];
            if(c == '+' || c == '-'){
                node = CreateNode(0, c);
                node->right = right;
                pos--;
                node->left = Expr();
            }
            else node = right;
        }
        else node = right;
    }
    return node;
}
void PrefixPrint(Node* node){
    if(node == NULL) return;
    if(node->OP == 'N') printf("%d ", node->value);
    else printf("%c ", node->OP);
    PrefixPrint(node->left);
    PrefixPrint(node->right);
}
