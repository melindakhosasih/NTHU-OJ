#include <stdio.h>

int main () {
    int a, n, d, i = 1;
    int x, y;

    scanf("%d%d%d", &a, &n, &d);
    if (-1000 < a && a < 1000 && n > 0 && n < 1000 && -1000 < d && d < 1000) {
        x = a;
        y = a;
        while (i < n) {
            x += d;
            y += x;
            ++i;
        }
        printf("%d %d", x, y);
    }

    return 0;
}
