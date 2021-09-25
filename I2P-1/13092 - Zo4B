#include <stdio.h>

void move(int way, int ans[4][4]){
    if(way == 0){
        for(int row = 3; row > 0; row--){
            for(int col = 0; col < 4; col++){
                if(ans[row-1][col] == 0){
                    ans[row-1][col] = ans[row][col];
                    for(int r = row; r < 3; r++) ans[r][col] = ans[r+1][col];
                    ans[3][col] = 0;
                }
            }
        }
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 4; col++){
                if(ans[row][col] && ans[row][col] == ans[row+1][col]){
                    ans[row][col] *= 2;
                    for(int r = row+1; r < 3; r++) ans[r][col] = ans[r+1][col];
                    ans[3][col] = 0;
                }
            }
        }
    }
    else if(way == 1){
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 4; col++){
                if(ans[row+1][col] == 0){
                    ans[row+1][col] = ans[row][col];
                    for(int r = row; r >= 0; r--) ans[r][col] = ans[r-1][col];
                    ans[0][col] = 0;
                }
            }
        }
        for(int row = 3; row > 0; row--){
            for(int col = 0; col < 4; col++){
                if(ans[row][col] && ans[row][col] == ans[row-1][col]){
                    ans[row][col] *= 2;
                    for(int r = row-1; r > 0; r--) ans[r][col] = ans[r-1][col];
                    ans[0][col] = 0;
                }
            }
        }
    }
    else if(way == 2){
        for(int col = 3; col > 0; col--){
            for(int row = 0; row < 4; row++){
                if(ans[row][col-1] == 0){
                    ans[row][col-1] = ans[row][col];
                    for(int c = col; c < 3; c++) ans[row][c] = ans[row][c+1];
                    ans[row][3] = 0;
                }
            }
        }
        for(int col = 0; col < 3; col++){
            for(int row = 0; row < 4; row++){
                if(ans[row][col] && ans[row][col] == ans[row][col+1]){
                    ans[row][col] *= 2;
                    for(int c = col+1; c < 3; c++) ans[row][c] = ans[row][c+1];
                    ans[row][3] = 0;
                }
            }
        }
    }
    else{
        for(int col = 0; col < 3; col++){
            for(int row = 0; row < 4; row++){
                if(ans[row][col+1] == 0){
                    ans[row][col+1] = ans[row][col];
                    for(int c = col; c > 0; c--) ans[row][c] = ans[row][c-1];
                    ans[row][0] = 0;
                }
            }
        }
        for(int col = 3; col > 0; col--){
            for(int row = 0; row < 4; row++){
                if(ans[row][col] && ans[row][col] == ans[row][col-1]){
                    ans[row][col] *= 2;
                    for(int c = col-1; c > 0; c--) ans[row][c] = ans[row][c-1];
                    ans[row][0] = 0;
                }
            }
        }
    }
}

int same (int ans[4][4], int board[4][4]){
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) if(ans[i][j] != board[i][j]) return 0;
    return 1;
}

int main (){
    int board[4][4], ans[4][4];
    while(scanf("%d", &board[0][0]) != EOF){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(i == 0 && j == 0){
                    ans[0][0] = board[0][0];
                    continue;
                }
                scanf("%d", &board[i][j]);
                ans[i][j] = board[i][j];
            }
        }
        for(int way = 0; way < 4; way++){
            move(way, ans);
            if(same(ans, board)){
                printf("Invalid\n");
                continue;
            }
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    printf("%d", ans[i][j]);
                    ans[i][j] = board[i][j];
                    if(j == 3) printf("\n");
                    else printf(" ");
                }
            }
        }
    }
    return 0;
}
