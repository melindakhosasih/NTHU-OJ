#include <stdio.h>

void combi (int a[], int combilen, int arrlen, int index, int ans[], int i) {
    if(index == combilen) {
        for(i = 0; i < combilen - 1; i++) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[i]);
        return;
    }
    
    if(i >= arrlen)
        return;
        
    ans[index] = a[i];
    combi(a, combilen, arrlen, index+1, ans, i+1);
    combi(a, combilen, arrlen, index, ans, i+1);
}

int main () {
    int n, m;
    int a[25];
    int ans[25];
    scanf("%d%d", &n, &m);

    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    combi(a, m, n, 0, ans,0);
    return 0;
}
