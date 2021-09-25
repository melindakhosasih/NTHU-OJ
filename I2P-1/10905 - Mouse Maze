#include <stdio.h>

char maze[505][505];
int row, col, result, count, way2;

int check(int, int, int);

int main() {
    int casenum;
    int x, y;
    scanf("%d", &casenum);
    for(int i = 0; i < casenum; i++) {
        scanf("%d%d", &row, &col);
        result = 250005;
        way2 = 250005;
        count = 0;
        for(int j = 0; j < row; j++) {
            for(int k = 0; k < col; k++) {
                scanf(" %c", &maze[j][k]);
                if(maze[j][k] == 'S') {
                    x = j;
                    y = k;
                }
            }
        }
        check(x, y, 0);
        if(result != 250005) printf("%d\n", count);
        else printf("-1\n");
    }
    return 0;
}

int check(int x, int y, int way) {
    if(way == 250005) return;
    if(maze[x][y] == 'F') {
        count++;
        result = way;
        return;
    }
    maze[x][y] = '#';
    if(maze[x+1][y] != '#' && x+1 < row) check(x+1, y, way+1);
    if(maze[x][y+1] != '#' && y+1 < col) check(x, y+1, way+1);
    if(maze[x-1][y] != '#' && x-1 >= 0) check(x-1, y, way+1);
    if(maze[x][y-1] != '#' && y-1 >= 0) check(x, y-1, way+1);
    maze[x][y] = '$';
    return;
}
