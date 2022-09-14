#include <stdio.h>
int main(){
    int n, data[5005][5], degree[5005] = {0};
    int min, idx;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d%d", &data[i][0], &data[i][1]);
        degree[data[i][0]]++;
        degree[data[i][1]]++;
    }
    for(int i = 1; i < n - 1; i++){
        min = 10000;
        for(int j = 1; j < n; j++){
            if(degree[data[j][0]] == 1 && degree[data[j][1]] > 0){
                if(min > data[j][0]){
                    min = data[j][0];
                    idx = j;
                }
            }
            else if(degree[data[j][1]] == 1 && degree[data[j][0]] > 0){
                if(min > data[j][1]){
                    min = data[j][1];
                    idx = j;
                }
            }
        }
        degree[data[idx][0]]--;
        degree[data[idx][1]]--;
        if(min == data[idx][0]) printf("%d ", data[idx][1]);
        else printf("%d ", data[idx][0]);
    }
    printf("\n");
}
