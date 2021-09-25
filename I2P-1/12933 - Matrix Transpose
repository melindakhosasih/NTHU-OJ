#include <stdio.h>

int main () {
    int x, y, i = 0, j = 0;
    signed char a[1000][1000];

    scanf("%d%d", &x, &y);

    for(i = 1; i <= x; i++) {
        for(j = 1; j <= y; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(j = 1; j <= y; j++) {
        for (i = 1; i < x; i++) {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][j]);
    }

    return 0;

}

