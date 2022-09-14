#include <stdio.h>
#include <string.h>

int str[100005][15] = {0};

int main() {
    int n, pos;
    char arr[15];
    int count = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", arr);
        int dec = 0;
        for(int j = 0; j < 10; j++) {
            if(arr[j] == 'x') {pos = j; continue;}
            dec = dec << 1;
            dec += arr[j] - '0';
        }
        str[dec][pos]++;
    }

    for(int i = 0; i < 520; i++) for(int j = 0; j < 10; j++) if(str[i][j] != 0) count++;
    printf("%d\n", count);
    return 0;
}
