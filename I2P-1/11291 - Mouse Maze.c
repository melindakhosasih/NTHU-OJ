#include <stdio.h>
#include <stdlib.h>
char map[505][505];
int result = 250005;

int check(int x, int y, int R, int C, int way) {
    if(way == result) return;
    else if(map[x][y] == 'F') {
        result = way;
        return;
    }
    map[x][y] = '#';
    if(map[x+1][y] != '#' && x+1 < R) check(x+1, y, R, C, way+1);
    if(map[x][y+1] != '#' && y+1 < C) check(x, y+1, R, C, way+1);
    if(map[x-1][y] != '#' && x-1 >= 0) check(x-1, y, R, C, way+1);
    if(map[x][y-1] != '#' && y-1 >= 0) check(x, y-1, R, C, way+1);
    map[x][y] = '$';
    return;
}

int main() {
    int i, j, k;
    int N, R, C;
    int x, y;
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d%d", &R, &C);
        result = 250005;
        for(j = 0; j < R; j++) {
            for(k = 0; k < C; k++) {
                scanf(" %c", &map[j][k]);
                if(map[j][k] == 'S') {
                    x = j;
                    y = k;
                }
            }
        }
        check(x, y, R, C, 0);
        if(result != 250005) {
            printf("%d\n", result);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
