#include <stdio.h>

long long func(const long long *a, const long long *b){
    return *a > *b;
}

int main(){
    long long arr[200005];
    int n;
    long long data, start;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) scanf("%lld", &arr[i]);
    start = arr[0];
    qsort(arr, n+1, sizeof(long long), func);

    long long distance;
    distance = (2*(start - arr[0])) + (2*(arr[n] - start));
    printf("%lld\n", distance);
}
