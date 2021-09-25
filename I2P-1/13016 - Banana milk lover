#include <stdio.h>
#define maxx(a,b) ((a > b) ? a : b)

int member[2005], *milk[2005], max_milk[2005], used[2005];
long long sum[2005];

int main() {
    int casenum;
    scanf("%d", &casenum);
    while(casenum--) {
        int group;
        scanf("%d", &group);
        for(int i = 0; i < group; i++) {
            scanf("%d", &member[i]);
            sum[i] = max_milk[i] = used[i] = 0;
            milk[i] = (int*)malloc(member[i]*sizeof(int));
            for(int j = 0; j < member[i]; j++) {
                scanf("%d", &milk[i][j]);
                sum[i] += milk[i][j];
                max_milk[i] = maxx(max_milk[i], milk[i][j]);
            }
        }
        for(int i = 0; i < group; i++) {
            int index = -1;
            for(int j = 0; j < group; j++) {
                if(used[j]) continue;
                if(index == -1) index = j;
                if(sum[j] > sum[index]) index = j;
                else if(sum[j] == sum[index] && max_milk[j] > max_milk[index]) index = j;
                else if(sum[j] == sum[index] && max_milk[j] == max_milk[index] && member[j] > member[index]) index = j;
            }
            used[index] = 1;
            int j = 0;
            for(j = 0; j < member[index]-1; j++) {
                printf("%d ", milk[index][j]);
            }
            printf("%d\n", milk[index][j]);
        }
        for(int i = 0; i < group; i++) free(milk[i]);
    }
    return 0;
}
