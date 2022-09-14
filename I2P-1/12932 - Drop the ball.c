#include <stdio.h>

int main ()
{
    int n, m;
    char a[505][505] = {0};
    int b[105] = {0};
    int row = 0, col = 0;
    int i = 0;
    int flag;

    scanf("%d%d", &n, &m);

    for (row = 1; row <= n; row++) {
        for (col = 1; col <= m; col++) {
            scanf(" %c", &a[row][col]);
        }
    }

    int q;

    scanf("%d", &q);

    for (i = 1; i <= q; i++) {
        scanf("%d", &b[i]);
        col = b[i];
        flag = 1;
        for (row = 1; row <= n; row++) {
            if(a[row][col] == '\\') {
                if(a[row][col+1] == '\\') {
                    flag = 0;
                    col++;
                }
                else if (a[row][col+1] == '/') {
                    flag = 1;
                    printf("Stuck QQ\n");
                    break;
                }
                else {
                    flag = 1;
                    printf("Right!\n");
                    break;
                }
            }
            else if (a[row][col] == '/') {
                if(a[row][col-1] == '/') {
                    flag = 0;
                    col--;
                }
                else if (a[row][col-1] == '\\') {
                    flag = 1;
                    printf("Stuck QQ\n");
                    break;
                }
                else {
                    flag = 1;
                    printf("Left!\n");
                    break;
                }
            }
        }
        if (flag == 0) {
            printf("Position: %d\n", col);
        }
    }

    return 0;
}
