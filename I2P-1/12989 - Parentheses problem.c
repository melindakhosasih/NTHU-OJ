#include <stdio.h>

char str[105];
int len;

long long value(int);
int close(int);

int main() {
    scanf("%d%s", &len, str+1);
    str[0] = '(', str[len+1] = ')';
    printf("%lld\n", value(0)/2);
}

long long value(int first) {
    if(str[first] == '(' && str[first+1] == ')') return 1;
    int last = close(first);
    long long sum = 0;
    for(int i = first + 1; i < last; i++) {
        sum += value(i);
        i = close(i);
    }
    return sum*2;
}

int close(int start) {
    int layer = 0;
    for(int i = start; i <= len+1; i++) {
        if(str[i] == '(') layer++;
        else if(str[i] == ')') layer--;
        if(layer == 0) return i;
    }
    return len-1;
}
