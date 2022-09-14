#include <stdio.h>

int main ()
{
    int D;
    char C, x, X;

    scanf("%c%d", &C, &D);

    if (D >= -25 && D <= 25) {
        if (C <= 90) {
            C -= D;
            if (C >= 65 && C <= 90) {
                x = C + 32;
                printf("%c\n", x);
            }
            else if (C < 65) {
                x = C + 58;
                printf("%c\n", x);
            }
            else if (C > 90) {
                x = C + 6;
                printf("%c\n", x);
            }
        }
        else if (C >= 97) {
            C -= 32;
            x = C - D;
            if (x < 65) {
                x += 26;
                printf("%c\n", x);
            }
            else if (x >= 65 && x <= 90) {
                printf("%c\n", x);
            }
            else if (x > 90) {
                x -= 26;
                printf("%c\n", x);
            }
        }
    }

    return 0;
}
