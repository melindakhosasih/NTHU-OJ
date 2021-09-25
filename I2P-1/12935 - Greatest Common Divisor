#include <stdio.h>

int main () {
    int x, y, gcd, a, i = 1;

    scanf("%d%d", &x, &y);

    a = (x > y) ? y : x;

    while (i <= a) {
        if (x % i == 0 && y % i == 0) {
            gcd = i;
        }
        i++;
    }

    printf("%d\n", gcd);

    return 0;
}
