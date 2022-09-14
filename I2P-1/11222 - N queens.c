#include <stdio.h>
int a[15];
int count = 0;

int valid(int row, int col){
    for(int i = 0; i < row; i++) if(a[i] == col || a[i] == (col - row + i) || a[i] == (col + row - i)) return 0;
    return 1;
}

int place(int row, int n){
    if(row == n) count++;
    else{
        for(int col = 0; col < n; col++){
            if(valid(row, col)){
                a[row] = col;
                place(row+1, n);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    place(0, n);
    printf("%d", count);
    return 0;
}
