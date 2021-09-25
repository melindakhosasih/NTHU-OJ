#include <stdio.h>
int main(){
    int n, m, count = 0,  mark = 0, ans = 0;
    int cost[1005], budget[1005];
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &cost[i]);
    for(int i = 0; i < m; i++) scanf("%d", &budget[i]);
    for(int i = 0; i < m; i++){
        if(i && !count) break;
        for(int j = 0 + mark; j < n; j++){
            count = 0;
            if(budget[i] >= cost[j]){
                count++;
                ans++;
                mark = j+1;
                break;
            }
        }
    }
    printf("%d\n", ans);
}
