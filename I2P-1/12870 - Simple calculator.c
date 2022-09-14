#include <stdio.h>

int main () {
    double a, b;
    char x;

    scanf("%lf%c%lf", &a, &x, &b);

    if(a >= 0 && b >= 0 && a < 1000 && b < 1000) {
        if (x == '+') {
            printf("%.3f\n", a + b);
        }
        else if (x == '-') {
            printf("%.3f\n", a - b);
        }
        else if (x == '*') {
            printf("%.3f\n", a * b);
        }
        else if (x == '/') {
            if (b == 0) {
                printf("Error\n");
            }
            else {
                printf("%.3f\n", a / b);
            }
        }
    }

    return 0;
}
