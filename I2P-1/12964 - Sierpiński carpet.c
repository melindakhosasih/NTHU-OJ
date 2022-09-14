#include <stdio.h>
#include <math.h>

char str[2200][2200];

void carpet(int size, int x, int y) {
    if(size < 3) return 0;
    for(int j = (size/3)+x; j < (size/3)*2+x; j++) for(int i = (size/3)+y; i < (size/3)*2+y; i++) str[j][i] = '#'; carpet(size/3, x, y);
    for(int j = x; j <= (size/3)*2 + x; j += (size/3)) for(int i = y; i <= (size/3)*2 + y; i += (size/3))
        if(j != size/3 || i != size/3) carpet(size/3, j, i);
}

int main () {
    int n;
    int size;
    scanf("%d", &n);
    size = pow(3,n);
    for(int i = 0; i < size; i++) for(int j = 0; j < size; j++) str[i][j] = '.';
    carpet(size, 0, 0);
    for(int i = 0; i < size; i++) printf("%s\n", str[i]);
}
