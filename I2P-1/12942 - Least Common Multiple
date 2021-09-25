#include <stdio.h>

int main () {
    int x, y;
    int lcm, gcd = 1;
    int a, i = 1;

    scanf("%d%d", &x, &y);

    a = (x > y) ? y : x;

    while(i <= a) {
        if(x % i == 0 && y % i == 0) {
            gcd = i;
        }
        i++;
    }

    lcm = x*y/gcd;
    printf("%d\n", lcm);

    return 0;
}
