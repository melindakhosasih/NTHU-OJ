#include <stdio.h>

int main () {
    int A, B, C, i = 0, j = 0;
    char s1[105] = {0}, s2[105] = {0};
    int a[105] = {0}, b[105] = {0}, r[105];

    scanf("%d%s%d%s", &A, &s1, &B, &s2);

    for (i = (105-A), j = 0; i < 105, j < A; i++, j++) {
        a[i] = s1[j] - '0';
    }
    for (i = (105-B), j = 0; i < 105, j < B; i++, j++) {
        b[i] = s2[j] - '0';
    }

    if(A >= B) {
        C = A;
    }
    else {
        C = B;
    }

    for (i = 105 - C; i < 105; i++) {
        if(a[i] > b[i]) {
            for (i = 104; i >= 105-C; i--) {
                r[i] = a[i]-b[i];

                if(r[i] >= 0) {
                    r[i] = r[i];
                }
                else {
                    r[i] = r[i] + 10;
                    a[i-1]--;
                }
            }
            for(i = 105 - C; i < 105; i++) {
                printf("%d", r[i]);
            }
            break;
        }
        else if (b[i] > a[i]) {
            for (i = 104; i >= 105-C; i--) {
                r[i] = b[i]-a[i];

                if(r[i] >= 0) {
                    r[i] = r[i];
                }
                else {
                    r[i] = r[i] + 10;
                    b[i-1]--;
                }
            }
            printf("-");
            for(i = 105 - C; i < 105; i++) {
                printf("%d", r[i]);
            }
            break;
        }
        else {
            int flag = 1;
            for (i = 104; i >= 105-C; i--) {
                r[i] = b[i]-a[i];

                if(r[i] >= 0) {
                    r[i] = r[i];
                }
                else {
                    r[i] = r[i] + 10;
                    b[i-1]--;
                }
            }
            for(i = 105 - C; i < 105; i++) {
                if(r[i] != 0) {
                    flag = 0;
                }
            }
            if(flag) printf("%d", 0);
            break;
        }
    }

    return 0;
}
