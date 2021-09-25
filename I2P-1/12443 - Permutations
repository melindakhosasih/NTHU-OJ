#include <stdio.h>

void permute(int ans[], int max, int n, int b) {
    int answer[7] = {0};
    if(n == 0) {
        for (int j = max - 1; j >= 0; j--) {
            answer[j] = b % 10;
            b = b/10;
        }
        for (int j = 0; j <= max - 1; j++) {
            printf("%d ", answer[j]);
        }
        printf("\n");
    }
    else {
        int i;
        for (i = 1; i <= max; i++) {
            if(!ans[i]) {
                ans[i] = i;
                permute(ans, max, n-1, b*10 + i);
                ans[i] = 0;
            }
        }
    }
}

int main () {
    int n;
    int a[7] = {0};

    scanf("%d", &n);

    permute(a, n, n, 0);
    return 0;
}
