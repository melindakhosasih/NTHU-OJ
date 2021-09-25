#include <stdio.h>

int main () {
    int A, B;
    char s1[105] = {0}, s2[105] = {0};
    int a[105] = {0}, b[105] = {0}, r[105] = {0};
    int i = 0, j = 0;

    scanf("%d%s%d%s", &A, &s1, &B, &s2);

    for(i = 105 - A, j = 0; i < 105, j < A; i++, j++) {
        a[i] = s1[j] - '0';
    }
    for(i = 105 - B, j = 0; i < 105, j < B; i++, j++) {
        b[i] = s2[j] - '0';
    }

    if (A >= B) {
        for(i = 104; i >= 105 - A; i--) {
            r[i] = a[i] + b[i];
            if(r[105 - A] > 9) {
                A++;
            }
            if (r[i] > 9) {
                r[i] -= 10;
                a[i-1]++;
            }
        }
        for(i = 105 - A; i < 105; i++) {
            printf("%d", r[i]);
        }
    }
    else {
        for(i = 104; i >= 105 - B; i--) {
            r[i] = a[i] + b[i];
            if(r[105 - B] > 9) {
                B++;
            }
            if (r[i] > 9) {
                r[i] -= 10;
                b[i-1]++;
            }
        }
        for(i = 105 - B; i < 105; i++) {
            printf("%d", r[i]);
        }
    }
    return 0;
}
