#include <stdio.h>

int main () {
    int n, m;
    int a[105][105];
    int b[105][105];
    int q, i = 0, j = 0;

    scanf("%d %d ", &n, &m);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    scanf("%d", &q);
    q = q % 4;

    switch (q) {
        case 0:
            for (i = 1; i <= n; i++) {
                for (j = 1; j < m; j++) {
                    printf("%d ", a[i][j]);
                }
                printf("%d\n", a[i][j]);
            }
            break;
        case 1:
            for (j = 1; j <= m; j++) {
                for (i = n; i > 1; i--) {
                    printf("%d ", a[i][j]);
                }
                printf("%d\n", a[i][j]);
            }
            break;
        case 2:
            for (i = n; i >= 1; i--) {
                for (j = m; j > 1; j--) {
                    printf("%d ", a[i][j]);
                }
                printf("%d\n", a[i][j]);
            }
            break;
        case 3:
            for (j = m; j >= 1; j--) {
                for (i = 1; i < n; i++) {
                    printf("%d ", a[i][j]);
                }
                printf("%d\n", a[i][j]);
            }
            break;
    }

    return 0;
}
