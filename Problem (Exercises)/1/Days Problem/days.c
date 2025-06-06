#include <stdio.h>
// Find the denominations of days, based on year, month, day
int main()
{
    // Declare variables
    int days, weeks, years, day;
    char name[80];

    // Get user's name and number of days
    printf("Hello, please enter your name: ");
    scanf("%s", name);

    printf("Hello, %s, please enter number of day/s: ", name);
    scanf("%d", &days);

    // Save the inputted number of days
    day = days;

    // Calculate the number of years and remaining days
    years = days / 365;
    days %= 365;

    weeks = days / 7;
    days %= 7; 

    // Print the result
    printf("%d days = %d year/s, %d week/s, and %d day/s", day, years, weeks, days);
}