#include <stdio.h>

int w[25], v[25];
long long arr[1005] = {0}, ans = 0;

int main()
{
    int number, total;
    scanf("%d%d", &number, &total);
    for(int i = 1; i <= number; i++) scanf("%d%d", &w[i], &v[i]);

    for(int i = 1; i <= number; i++)
    {
        for(int j = total; j >= 0; j--)
        {
            if(j - w[i] >= 0)
            {
                if(arr[j - w[i]] + v[i] > arr[j])
                {
                    arr[j] = arr[j-w[i]] + v[i];
                }
                else arr[j] = arr[j];
            }
        }
    }

    for(int i = 1; i <= total; i++)
    {
        if(arr[i] > ans) ans = arr[i];
        else ans == ans;
    }
    printf("%lld\n", ans);
}
