#include <stdio.h>
long long cur, len[55];
int execute (int k, long long l, long long r){
    if(cur + len[k] < l){
        cur += len[k];
        return;
    }
    if(cur > r) return;
    if(cur >= l && cur <= r) printf("O");
    cur++;
    if(k!= 1 && cur <= r) execute(k-1, l, r);
    if(cur >= l && cur <= r) printf("u");
    cur++;
    if(k!= 1 && cur <= r) execute(k-1, l, r);
    if(cur >= l && cur <= r) printf("Q");
    cur++;
}

int main(){
    int k;
    long long l, r;
    len[1] = 3;
    for(int i = 2; i <= 50; i++) len[i] = 2*len[i-1] + 3;
    while(scanf("%d%lld%lld", &k, &l, &r) != EOF){
        cur = 0;
        execute(k, l, r);
        printf("\n");
    }
}
