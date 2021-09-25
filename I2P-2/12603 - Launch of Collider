#include <stdio.h>
int main(){
    int casenum, index1 = 0, index2 = 0;
    char type[200005];
    int left[200005], right[200005];
    scanf("%d", &casenum);
    scanf("%s", type);
    for(int i = 0; i < casenum; i++){
        if(type[i] == 'L') scanf("%d", &left[index1]), index1++;
        else if (type[i] == 'R') scanf("%d", &right[index2]), index2++;
    }
    int collide, ans = -1;
    for(int i = 0; i < index1; i++){
        for(int j = 0; j < index2; j++){
            if(left[i] > right[j]){
                collide = (left[i] - right[j])/2;
                if(ans == -1)
                    ans = collide;
                else if(ans > collide)
                    ans = collide;
            }
        }
    }
    printf("%d\n", ans);
}
