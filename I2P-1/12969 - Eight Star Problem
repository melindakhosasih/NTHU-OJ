#include <stdio.h>

int a[15][15] = {0};
int b[15] = {0};
long long int ans = -1e18;
int n;

int main () {
    scanf("%d", &n);
    for(int row = 0; row < n; row++) for(int col = 0; col < n; col++) scanf("%d", &a[row][col]);
    star(0, 0);
    if(ans == -1e18) printf("no solution\n");
    else printf("%lld\n", ans);
}

void star (long long int score, int index) {
    if(index == n) {
        if(score > ans) ans = score;
        else ans = ans;
        return;
    }
    for(int row = 0; row < n; row++) {
        int valid = 1;
        for(int col = 0; col < index; col++) {
            if(b[col] == row || b[col] == row + col - index || b[col] == row + index - col) valid = 0;
        }
        if(valid) {
            b[index] = row;
            star(score+a[row][index], index+1);
        }
    }
    return;
}
