#include <stdio.h>

int main () {
    int N;
    char x, y, z;
    int r1, r2, r3;

    scanf("%d", &N);

    r1 = (N/100) % 2;
    r2 = (N/10) % 2;
    r3 = N % 2;

    if (r1 == 0) {
        x = 'A';
    }
    else {
        x = 'B';
    }

    if (r2 == 0) {
        y = 'C';
    }
    else {
        y = 'D';
    }

    if (r3 == 0) {
        z = 'E';
    }
    else {
        z = 'F';
    }

    printf("%c%c%c", x, y, z);

    return 0;
}
