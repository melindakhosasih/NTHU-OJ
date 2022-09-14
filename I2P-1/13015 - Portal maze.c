#include <stdio.h>
#include <ctype.h>

char maze[305][305];
int n, m, portal[30][2], flag;

int check(int, int);

int main()
{
    int casenum;
    int row, col;

    scanf("%d", &casenum);

    for(int i = 0; i < casenum; i++){
        scanf("%d%d", &n, &m);
        flag = 0;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                scanf(" %c", &maze[j][k]);
                if(maze[j][k] == '$'){
                    row = j;
                    col = k;
                }
                if(isupper(maze[j][k])){
                    portal[maze[j][k]-'A'][0] = j;
                    portal[maze[j][k]-'A'][1] = k;
                }
            }
        }
        check(row, col);
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

int check(int row, int col)
{
    if(islower(maze[row][col])){
        check(portal[maze[row][col]-'a'][0], portal[maze[row][col]-'a'][1]);
        return;
    }
    if(maze[row][col] == '&'){
        flag = 1;
        return;
    }
    maze[row][col] = '#';
    if(maze[row+1][col] != '#' && row+1 < n) check(row+1, col);
    if(maze[row][col+1] != '#' && col+1 < m) check(row, col+1);
    if(maze[row-1][col] != '#' && row-1 >= 0) check(row-1, col);
    if(maze[row][col-1] != '#' && col-1 >= 0) check(row, col-1);
    return;
}
