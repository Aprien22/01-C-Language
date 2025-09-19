#include <stdio.h>

//Write a program to find the greatest of two numbers.
int main()
{
    // Declare and initialize the variables
    int num1, num2;
    
    // Get the two numbers
    printf("Enter your first number: ");
    scanf("%d", &num1);

    printf("Enter your second number: ");
    scanf("%d", &num2);

    // Output the greatest number
    num1 > num2 ? printf("%d is greater than %d", num1, num2) : printf("%d is greater than %d", num2, num1);
}