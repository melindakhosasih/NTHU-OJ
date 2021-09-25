#include <stdio.h>

int main ()
{
    int month1, day1, hh1, mm1, ss1;
    int month2, day2, hh2, mm2, ss2;
    char a, b, c, d, e ,f;

    scanf("%d%c%d %d%c%d%c%d", &month1, &a, &day1, &hh1, &b, &mm1, &c, &ss1);
    scanf("%d%c%d %d%c%d%c%d", &month2, &d, &day2, &hh2, &e, &mm2, &f, &ss2);

    int x1, x2, month, day, hour, minute, second, y1, y2;
    int max, min, MAX, MIN;

    x1 = (month1 * 30) + day1;
    x2 = (month2 * 30) + day2;
    y1 = (hh1 * 3600) + (mm1 * 60) + ss1;
    y2 = (hh2 * 3600) + (mm2 * 60) + ss2;

    max = (x1 >= x2) ? x1 : x2;
    min = (x1 < x2) ? x1 : x2;
    MAX = (y1 >= y2) ? y1 : y2;
    MIN = (y1 < y2) ? y1 : y2;

    month = (max - min)/30;
    day = (max - min) % 30;
    hour = (MAX - MIN)/3600;
    minute = ((MAX - MIN)%3600)/60;
    second = (MAX - MIN) % 60;

    printf("%d %d\n", month, day);
    printf("%02d:%02d:%02d\n", hour, minute, second);

    return 0;
}
