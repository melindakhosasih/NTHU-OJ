#include <stdio.h>

int a[1000005] = {0};
int b[1000005] = {0};
int main () {
    int n, i = 0, j = 0;

    long long int count = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 1; i <= n; i++) {
        count += b[a[i]];
        b[a[i]]++;
    }
    printf("%lld\n", count);

    return 0;
}
