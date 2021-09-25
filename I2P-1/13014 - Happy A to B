#include <stdio.h>
#define swap(a,b) {a^=b; b^=a; a^=b;}

char A[5][5] = {}, B[5][5] = {};
int roww[4] = {1, 0, -1, 0}, coll[4] = {0, 1, 0, -1}, result;

int check(int, int, int);
int flag();

int main() {
    int casenum;
    scanf("%d", &casenum);
    for(int i = 0; i < casenum; i++) {
        int row, col, step;
        result = 0;
        scanf("%d", &step);
        for(int j = 0; j < 3; j++) scanf("%s", A[j]);
        for(int j = 0; j < 3; j++) scanf("%s", B[j]);
        for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++) if(A[j][k] == 'x') row = j, col = k;
        check(row, col, step);
        if(result) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

int check(int row, int col, int step) {
    if(flag()) result = 1;
    else if(step) {
        for(int i = 0; i < 4; i++) {
            if(A[row+roww[i]][col+coll[i]]){
                swap(A[row][col], A[row+roww[i]][col+coll[i]]);
                check(row+roww[i], col+coll[i], step-1);
                swap(A[row][col], A[row+roww[i]][col+coll[i]]);
            }
        }
    }
}

int flag() {
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) if(A[i][j] != B[i][j]) return 0;
    return 1;
}
