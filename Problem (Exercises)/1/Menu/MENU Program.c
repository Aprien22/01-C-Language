#include <stdio.h>

int main () 
{
    int prog, again;
    char name[80] = "";
    

    printf("Hello, please enter your name: ");
    scanf("%s", name);

    printf("Hello and welcome, %s!\nWhat do you want to do?\n", name);
    
    do
    {
        printf("\nMENU PROGRAM:\n1. Smiley\n2. Plato\n3. Seconds\n4. Exit\n");
        printf("Input a number (1 - 4): ");
        scanf("%d", &prog);
    
        if (prog == 1) 
        {
            do
            {
                int n1, n2, n3, squaresum;

                printf("Welcome to Smiley The Program, %s.\n", name);

                printf("Please enter the 1st number: ");
                scanf("%d", &n1);
                printf("Please enter the 2nd number: ");
                scanf("%d", &n2);
                printf("Please enter the 3rd number: ");
                scanf("%d", &n3);

                squaresum = (n1 + n2 + n3) * 2;

                printf("Twice the sum of %s's numbers %d, %d, %d is %d :) :) :)\n", name, n1, n2, n3, squaresum);
               
                printf("Do you want to try Smiley's again? (1 - Yes / 0 - No)\n");
                scanf("%d", &again);
                
            } while (again == 1);
        } 
        else if (prog == 2) 
        {
            do
            {
                int age, partnersAge, gender;

                printf("Welcome to Plato The Program, %s.\n", name);
                printf("Enter your gender (1 - Male / 2 - Female): ");
                scanf("%d",&gender);
                printf("Enter your age: ");
                scanf("%d", &age);

                if (gender == 1) 
                {
                    partnersAge = age / 2 + 7;
                    printf("%s, your ideal partners age is: %d \n", name, partnersAge);
                }
                else if (gender == 2)
                {
                    partnersAge = (age-7) * 2;
                    printf("%s, your ideal partners age is: %d \n", name, partnersAge);
                }
                else 
                    printf("ERROR: Invalid input! (1 - Male / 2 - Female)\n");
                
                printf("Do you want to try Plato's again (1 - Yes / 0 - No)? ");
                scanf("%d", &again);

            } while (again == 1);
        } 
        else if (prog == 3) 
        {
            do{
                int sec, min, hour = 0;

                printf("Welcome to Seconds The Program, %s.\n", name);
                printf("Enter seconds: ");
                scanf("%d", &sec);

                hour = sec/3600;
                sec %= 3600;
                min = sec/60;
                sec %= 60;
                
                printf("Seconds: %d\n", sec);
                printf("Minutes: %d\n", min);
                printf("Hours: %d\n", hour);

                printf("%s, the time is %.2d:%.2d:%.2d \n", name, hour, min, sec);
                
                printf("Do you want to try Seconds' again (1 - Yes / 0 - No)? ");
                scanf("%d", &again);

            } while (again == 1);
        } 
        else if (prog == 4) 
        {
            printf("Do you want to exit the program (1 - Yes / 0 - No)? ");
            scanf("%d", &again);

            if( again == 1)
                printf("Thank you for using our program!");
        }
        else 
        {
            printf("ERROR: Invalid Input! Please Try again!\n");
            again = 0;
        }

    } while (again == 0);
}