#include <stdio.h>

int main() {
    int n;
    int arr[105], chosen[105][105], sum[105];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    sum[1] = arr[1];
    chosen[1][1] = 1;
    for(int i = 1; i < n; i++) {
        if(sum[i] > sum[i-1]+arr[i+1]) {
            sum[i+1] = sum[i];
            for(int j = 1; j <= n; j++) chosen[i+1][j] = chosen[i][j];
        }
        else {
            sum[i+1] = sum[i-1] + arr[i+1];
            for(int j = 1; j <= n; j++) chosen[i+1][j] = chosen[i-1][j];
            chosen[i+1][i+1] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        if (chosen[n][i]) printf("%d ", i);
    }

}
