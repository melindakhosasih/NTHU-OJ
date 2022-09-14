#include <stdio.h>

int main () {
    int n, x, i = 0, j = 0;
    int flag = 0, b;
    int N, lala, p[100] = {0};
    long long int ans, a = 1;

    scanf("%lld", &n);
    N = n;

    if (n >= 2 && n <= 100) {
        while (n > 1) {
            for (i = 2; i < n; i++) {
                if(n % i == 0) {
                    flag = 1;
                    break;
                }
                else {
                    flag = 0;
                    b = n;
                }
            }

            if (flag == 0) {
                lala = n;
                while(lala <= N) {
                    p[j] = p[j] + (N / lala);
                    lala = lala * n;
                }
                j++;
            }
            n--;
        }

        for (j-- ; j >= 0; j--) {
            p[j]++;
            ans = p[j] * a;
            a = ans;
        }

        printf("%lld", a);
    }

    return 0;
}
