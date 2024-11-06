#include <stdio.h>

int main()
{
    int days, weeks, years, day;
    char name[80];

    printf("Hello, please enter your name: ");
    scanf("%s", name);

    printf("Hello, %s, please enter number of day/s: ", name);
    scanf("%d", &days);

    day = days;

    years = days / 365;
    days %= 365;

    weeks = days / 7;
    days %= 7; 

    printf("%d days = %d year/s, %d week/s, and %d day/s", day, years, weeks, days);
}