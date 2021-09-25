#include <stdio.h>
#include <string.h>
int idx, len;
char str[35];
int calcu(int, int, int, int);
int main(){
    scanf("%s", str);
    len = strlen(str);
    for(int i = 0; i < 16; i++){
        printf("%d %d %d %d %d\n", (i&8)>>3, (i&4)>>2, (i&2)>>1, (i&1), calcu((i&8)>>3, (i&4)>>2, (i&2)>>1, (i&1)));
        idx = 0;
    }
}

int calcu(int a, int b, int c, int d){
    int op1, op2, ans;
    char input;
    if(idx == len) return;
    input = str[idx];
    idx++;
    if(input == '&'){
        op1 = calcu(a, b, c, d);
        op2 = calcu(a, b, c, d);
        ans = op1 & op2;
    }
    else if(input == '|'){
        op1 = calcu(a, b, c ,d);
        op2 = calcu(a, b, c ,d);
        ans = op1 | op2;
    }
    else if(input == 'A') ans = a;
    else if(input == 'B') ans = b;
    else if(input == 'C') ans = c;
    else if(input == 'D') ans = d;
    return ans;
}
