#include <stdio.h>
int main(){
    int casenum;
    long long int a, b, count;
    scanf("%d", &casenum);
    while(casenum--){
        count = 0;
        scanf("%lld%lld", &a, &b);
        b++;
        while(b >= 10) b /= 10, count++;
        printf("%lld\n", count*a);
    }
}
