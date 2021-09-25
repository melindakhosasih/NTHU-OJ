#include <stdio.h>

int seq[15] = {0};
int arr[15] = {0};
int count = 0;
int total, sum, k, len, flag = 0;
void check(int, int, int, int, int);

int main() {
    int casenum;
    scanf("%d", &casenum);
    for(int i = 0; i < casenum; i++) {
        scanf("%d%d", &len, &k);
        total = 0;
        count = 0;
        flag = 0;
        for(int j = 0; j < len; j++) {
            scanf("%d", seq+j);
            total += seq[j];
        }
        sum = total / k;
        check(0, 1, 0, 0, 0);
        if(flag) printf("True\n");
        else printf("False\n");
    }
    return 0;
}

void check(int index, int i, int count, int cursum, int sumset) {
    if(index == len) {
        if(count == 0) return;
        else if(i == 1) check(0, i+1, 0, 0, cursum);
        else if(cursum != sumset) return;
        else if(i < k) check(0, i+1, 0, 0, sumset);
        else if(i == k) {
            for(int j = 0; j < len; j++) if(arr[j] == 0) return;
            flag = 1;
        }
        return;
    }

    check(index+1, i, count, cursum, sumset);

    if(!arr[index]) {
        arr[index] = i;
        check(index+1, i, count+1, cursum + seq[index], sumset);
        arr[index] = 0;
    }
    return;
}
