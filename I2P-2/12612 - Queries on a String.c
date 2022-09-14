#include <stdio.h>
int main(){
    char string[10005], str[10005];
    int casenum, left, right, k, len, index;
    scanf("%s%d", string+1, &casenum);
    while(casenum--){
        scanf("%d%d%d", &left, &right, &k);
        index = 0;
        len = right - left + 1;
        if(len != 1) k %= len;
        for(int i = left; i <= right; i++) index++, str[index] = string[i];
        if(k){
            while(k--){
                str[0] = str[index];
                if(k){
                    for(int i = len; i > 0; i--) str[i] = str[i-1];
                    str[index] = str[index];
                }
            }
            index = 0;
            for(int i = left; i <= right; i++) string[i] = str[index], index++;
        }
    }
    printf("%s\n", string+1);
}
