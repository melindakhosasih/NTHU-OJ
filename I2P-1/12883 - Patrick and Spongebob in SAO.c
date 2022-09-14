#include <stdio.h>

int main () {
    int n, q, i, x;
    int a[500], count[500];
    int l, r, ans, check;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);

    for(x = 0; x < q; x++) {
        check = 0;
        scanf("%d%d", &l, &r);

        for(i = 0; i < 500; i++) {
            count[i] = 0;
        }

        for (i = l - 1; i < r; i++) {
            count[a[i]]++;
        }

        for(i = 1; i < 500; i++) {
            if(count[i] > check) {
                check = count[i];
                ans = i;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
