#include <stdio.h>

int main()
{
    char a = 'A';
    int points;

    printf("Please enter a character(Must be capilized) " );
    scanf("%c", &a);

    switch (a)
    {
        case 'A':
            points = 4;
            break;
        case 'B':
            points = 3;
            break;
        case 'C':
            points = 2;
        case 'D':
            points = 0;
    }
    if (points > 0) 
    {
        printf("Points Earned");
    }
    else printf("Point Missed");
}