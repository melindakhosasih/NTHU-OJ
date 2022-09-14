#include <stdio.h>

int main(){
    int casenum;
    scanf("%d", &casenum);
    while(casenum--){
        long long int num;
        int start = 1, len = 0, max = 0;
        scanf("%lld", &num);
        while(num){
            if(start) len = 0;
            if(num & 1){
                start = 0;
                if(len > max) max = len;
                len = 0;
            }
            len++;
            num = num >> 1;
        }
        printf("%d\n", max-1);
    }
}
