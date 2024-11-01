#include <stdio.h>

void main(){

    // Declare variables
    char name[80];
    int first , second, third, twicesum;

    // Ask for name
    printf("Please enter your name: ");
    scanf("%s", name);

    // Ask for three numbers
    printf("Hello %s, please enter your first number: ", name);
    scanf("%d", &first);
    printf("Please enter the second number: ");
    scanf("%d", &second);
    printf("The third number: ");
    scanf("%d", &third);

    twicesum = 2 * (first + second + third);

    printf("Twice the sum of your numbers %d, %d, %d is %d :) :) :)", first, second, third, twicesum);
}