#include <stdio.h>

int arr[5][25] = {0};
int n, count = 0;

int ans (int, int);

int main()
{
    scanf("%d", &n);
    count = ans(0, 0);
    printf("%d\n", count);
}

int ans(int row, int col)
{
    if(col == n){
        row++;
        col = 0;
    }
    if(row == 3){
        count++;
        return;
    }
    if(arr[row][col] == 0){
        if(arr[row][col+1] == 0 && row < 3 && col + 1 < n){
            arr[row][col] = arr[row][col+1] = 1;
            ans(row, col+1);
            arr[row][col] = arr[row][col+1] = 0;
        }
        if(arr[row+1][col] == 0 && row + 1 < 3 && col < n){
            arr[row][col] = arr[row+1][col] = 1;
            ans(row, col+1);
            arr[row][col] = arr[row+1][col] = 0;
        }
    }
    else ans(row, col+1);
    return count;
}
