#include <stdio.h>

char store[1050000];

int check(int, int, int, int);

int main() {
    int casenum;
    scanf("%d", &casenum);
    while(casenum--) {
        int n, total;
        scanf("%d%d", &n, &total);
        for(int i = 0; i < (1<<n); i++) {
            store[i] = -1;
        }
        if(check(n, total, 0, 0)) printf("True\n");
        else printf("False\n");
    }
    return 0;
}

int check(int n, int total, int index, int sum) {
    if(sum >= total) return store[index] = 0;
    if(store[index] != -1) return store[index];
    int next;
    for(int i = 0; i < n; i++) {
        if(!(index & (1<<i))) {
            next = check(n, total, index | (1<<i), sum+i+1);
            if(next == 0) return store[index] = 1;
        }
    }
    return store[index] = 0;
}
