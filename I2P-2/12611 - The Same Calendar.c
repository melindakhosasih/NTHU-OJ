#include <stdio.h>
int main(){
    int casenum, year, day, leap, check;
    scanf("%d", &casenum);
    while(casenum--){
        scanf("%d", &year);
        if(year % 4 != 0) leap = 0;
        else if(year % 100 != 0) leap = 1;
        else if(year % 400 != 0) leap = 0;
        else leap = 1;
        day = 0;
        check = leap;
        while(year++){
            if(check) day++;
            if(year % 4 != 0) check = 0;
            else if(year % 100 != 0) check = 1;
            else if(year % 400 != 0) check = 0;
            else check = 1;
            day++;
            day %= 7;
            if(!day && leap == check) break;
        }
        printf("%d\n", year);
    }
}
