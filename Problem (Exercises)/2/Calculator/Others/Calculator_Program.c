#include <stdio.h>
#include <math.h>
int main()
{
    char operation;
    double num1, num2;
    char name[80];
    int again = 1;

    printf("Hello and Welcome, please enter your name: ");
    scanf("%s", name);

    do
    {
        printf("Hello again %s. Welcome to CALCULATOR: the program!\n", name);

        printf("Please enter an operator (+, -, *, /): ");
        scanf(" %c", &operation);

        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        switch (operation)
        {
        case '+':
            printf("%.2lf", num1 + num2);
            break;
        case '-':
            printf("%.2lf", num1 - num2);
            break;
        case '*':
            printf("%.2lf", num1 * num2);
            break;
        case '/':
            printf("%.2lf", num1 / num2);
            break;
        default:
            printf("Invalid operator. Please try again.");
            again = 1;
            break;
        }  
        printf("\nDo you want to retry (Any Number - YES, 0 - NO)? ");
        scanf("%d", &again);

    } while (again != 0);

    printf("Thank you for using this program!");
    
    
    return 0;
}