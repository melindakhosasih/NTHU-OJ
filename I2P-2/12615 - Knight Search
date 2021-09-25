#include <stdio.h>
#include <math.h>
int flag = 0;
char string[15] = "ICPCASIASG", board[105][105];
int valid(int a, int b, int c, int d){
    if(pow((a-c),2) + pow((b-d),2) == 5) return 1;
    return 0;
}

int check(int index, int n, int start_x, int start_y){
    if(index == 10) {flag = 1; return;}
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(board[row][col] == string[index]){
                if(valid(row, col, start_x, start_y)){
                    check(index+1, n, row, col);
                }
            }
        }
    }
}

int main(){
    int n, row[105], col[105], idx = -1;
    char str[100005];
    scanf("%d%s", &n, str);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i][j] = str[i*n + j];
            if(board[i][j] == 'I'){
                idx++;
                row[idx] = i, col[idx] = j;
            }
        }
    }
    for(int i = 0; i <= idx; i++) {
        check(1, n, row[i], col[i]);
        if(flag) break;
    }
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
