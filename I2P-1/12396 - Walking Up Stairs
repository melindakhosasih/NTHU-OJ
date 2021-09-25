#include <stdio.h>

int main () {
   long long a[120];
   int n, x = 0, i = 0;

   scanf("%d", &n);

   if (n > 0 && n <= 116) {
       a[0] = 1;
       a[1] = 1;
       a[2] = 1;

       for(i = 3; i <= n; i++)
           a[i] = a[i-1] + a[i-3];

       printf("%llu\n", a[n]);
   }

   return 0;
}
