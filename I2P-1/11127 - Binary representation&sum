#include <stdio.h>

int main ()
{
    unsigned int N, fakeN;
    int binary[11];
    int i, j, count = 0;
    scanf ("%u", &N);
    fakeN = N +1;

    for (i = 0; fakeN > 0; i++) {
        binary[i] = N % 2;
        binary[i + 1] = 0;
        N /= 2;
        fakeN /= 2;
    }

    binary[0] += 1;

    for (j = 0; binary[j] > 1; j++) {
        binary[j] = 0;
        binary[j + 1] += 1;
        count++;
    }

    for (i = i - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    printf(" %d", count);

    return 0;
}
