#include <stdio.h>

int main ()
{
    int n, q, i = 0, j = 0;
    char s[1005];
    int a, b, sz;

    scanf("%d %s", &n, s);
    scanf("%d", &q);

    for (i = 0; i < q; i++) {
        int A = 0, B = 0;
        scanf("%d%d%d", &a, &b, &sz);
        for(j = a; j < a+sz; j++) {
            A = A*10 + s[j] - '0';
            s[j] = '0';
        }
        for(j = b; j < b+sz; j++) {
            B = B*10 + s[j] - '0';
            s[j] = '0';
        }
        printf("%lld\n", (long long)A*B);

        int N = 0;

        for(j = 0; j < n; j++) {
            if (s[j] != '0') {
                s[N] = s[j];
                N++;
            }
        }
        n = N;
    }

    return 0;
}
