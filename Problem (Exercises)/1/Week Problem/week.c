#include <stdio.h>

//Write a program that reads an integer between 1 and 7 and print the day of the week in English.
int main()
{
    //Declare the variables
    char name[80];
    int n;

    //Get the name
    printf("Hello, please enter your name: ");
    scanf("%s", name);

    //Get a number from 1 - 7
    printf("Hello, %s. Please enter a number from 1 - 7: ", name);
    scanf("%d", &n);

    //Check if the number is valid
    if (n < 1 || n > 7)
    {
        printf("Invalid input. Please enter a number between 1 and 7.\n");
    }
    else
    {
        switch (n)
        {
        case 1: printf("Monday"); break;
        case 2: printf("Tuesday"); break;
        case 3: printf("Wednesday"); break;
        case 4: printf("Thursday"); break;
        case 5: printf("Friday"); break;
        case 6: printf("Saturday"); break;
        case 7: printf("Sunday"); break;
        default: break;
        }
    }
    return 0;
}