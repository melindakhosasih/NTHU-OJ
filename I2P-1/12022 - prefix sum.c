#include <stdio.h>

long long int a[1000001] = {0};

int main () {
    int n, m;

    int i = 0;
    int x, y;

    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] = a[i-1] + a[i];
    }

    scanf("%d", &m);

    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        printf("%lld\n", a[y] - a[x-1]);
    }

    return 0;
}
