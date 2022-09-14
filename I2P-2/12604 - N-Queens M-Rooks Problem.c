#include <stdio.h>
int count, board[15], board2[15], queen, rook, n, m;

int place(int row, int queen, int rook){
    if(row == n+m){count++; return;}
    for(int col = 0; col < n+m; col++){
        board2[row] = col;
        if(queen < n){
            board[row] = 1;
            if(valid(row)) place(row+1, queen+1, rook);
            board[row] = 0;
            if(valid(row) && rook < m) place(row+1, queen, rook+1);
        }
        else{
            if(valid(row) && rook < m) place(row+1, queen, rook+1);
        }
        board2[row] = -1;
    }
    return 0;
}

int valid(int row){
    for(int i = 0; i < row; i++){
        if(board[i] || board[row]){
            if(board2[i] == board2[row] || board2[i] - (row - i) == board2[row] || board2[i] + (row - i) == board2[row]) return 0;
        }
        else
            if(board2[i] == board2[row]) return 0;
    }
    return 1;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
        count = 0, queen = 0, rook = 0;
        place(0, queen, rook);
        printf("%d\n", count);
    }
}
