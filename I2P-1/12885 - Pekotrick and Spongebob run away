#include <stdio.h>

int main ()
{
    int n, m;
    int a[510][510];
    int i = 0, j = 0;
    int ans = 0, b = 0;

    scanf("%d%d", &n, &m);
    int x, y;
    x = n * m;
    y = x - n;

    if(n > 0 && m > 0 && n <= 500 && m <= 500 && m % 2 == 0) {
        while (b >= 0 && b < (m / 2)) {
            if (j <= m) {
                j++;
                for (i++; i <= n; i++) {
                    ans++;
                    a[i][j] = ans;
                }
                j++;
                for (i-- ; i > 0; i--) {
                    ans++;
                    a[i][j] = ans;
                }
            }
            b++;
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if(a[i][j] != x) {
                    printf("%d ", a[i][j]);
                }
                else if (a[i][j] == x && x > y) {
                    printf("%d\n", a[i][j]);
                    x--;
                }
            }
        }
    }
    return 0;
}
