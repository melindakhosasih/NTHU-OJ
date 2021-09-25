#include <stdio.h>
#define swap(a,b) {a^=b; b^=a; a^=b;}

char A[5][5];
char B[5][5];
int str[1025][10] = {0};
int count = 0, result = 0;

int check(int, int, int);

int main(){
    int casenum, step, dec[100005] = {0}, pos[100005] = {0};
    int row, col;
    scanf("%d%d", &casenum, &step);
    for(int i = 0 ; i <= casenum; i++){
        if(i != casenum){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    scanf(" %c", &A[j][k]);
                    if(A[j][k] == 'x') pos[i] = (j*3)+k;
                    else{
                        dec[i] = dec[i] << 1;
                        dec[i] += A[j][k] - '0';
                    }
                }
            }
        }
        else{
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    scanf(" %c", &B[j][k]);
                    if(B[j][k] == 'x') row = j, col = k;
                }
            }
        }
    }
    check(row, col, step);
    for(int i = 0; i < casenum; i++) if(str[dec[i]][pos[i]]) count++;
    printf("%d\n", count);
    return 0;
}

int check(int row, int col, int step){
    int roww[4] = {0, 1, 0, -1};
    int coll[4] = {1, 0, -1, 0};
    int dec = 0, pos = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(B[i][j] == 'x') pos = (i*3)+j;
            else{
                dec = dec << 1;
                dec += B[i][j] - '0';
            }
        }
    }
    str[dec][pos]++;
    if (step){
        for(int i = 0; i < 4; i++){
            if(B[row+roww[i]][col+coll[i]]){
                swap(B[row][col], B[row+roww[i]][col+coll[i]]);
                check(row+roww[i], col+coll[i], step-1);
                swap(B[row][col], B[row+roww[i]][col+coll[i]]);
            }
        }
    }
    return 0;
}
