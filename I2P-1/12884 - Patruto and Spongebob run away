#include <stdio.h>

int main () {
    int n, i = 0, j = 0;
    int a[510][510];
    int b = 0;
    int ans = 0;

    scanf("%d", &n);
    int t = 2*n;
    int y = 2*n;

    if(n > 0 && n <= 250) {
        while(b >= 0 && b < n) {
            if (i <= y - b) {
                i = 1 + b;
                for(j = 1 + b; j <= y - b; j++) {
                    ans++;
                    a[i][j] = ans;
                }
                for(i = i, j--, ans--; i <= y - b; i++) {
                    ans++;
                    a[i][j] = ans;
                }
                for(i = i - 1, ans--; j > 0 + b; j--) {
                    ans++;
                    a[i][j] = ans;
                }
                for(i--, j++; i > 1 + b; i--) {
                    ans++;
                    a[i][j] = ans;
                }
                i++;
            }
            b++;
        }

        for(i = 1; i <= y; i++) {
            for(j = 1; j <= y; j++) {
                if(a[i][j] != t) {
                    printf("%d ", a[i][j]);
                }
                else if(a[i][j] == t && t < 2*y) {
                    printf("%d\n", a[i][j]);
                    t++;
                }
            }
        }

    }

    return 0;
}
