#include <stdio.h>

int main () {
    int n, m, q;
    int i = 1;
    int j = 1;
    int a[100][100];
    int u, d, l, r;

    scanf("%d%d", &n, &m);
    if (n >= 1, m >= 1, q >= 1, n <= 100, m <= 100, q <= 100) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        scanf("%d", &q);

        for(int x = 0; x < q; x++) {
            scanf("%d%d%d%d", &u, &d, &l, &r);
            int ans = 0;
            for (i = u; i <= d; i++) {
                for (j = l; j <= r; j++) {
                    if(a[i][j] > ans) {
                        ans = a[i][j];
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
