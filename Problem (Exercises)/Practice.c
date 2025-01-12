#include <stdio.h>

// Objective: Write a C program to reverse a given positive integer.

int main()
{
    int num, reversed_num = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    while (num > 0) {
        reversed_num = reversed_num * 10 + num % 10;
        num /= 10;
    }
    
    printf("Reversed number: %d\n", reversed_num);
    
    return 0;
    
}

















    /* Objective: Write a C program to calculate the factorial of a given positive integer N.
    int N, factorial = 1;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    if (N < 0) {
        printf("Error: Negative numbers are not allowed.\n");
        return 1;
    }

    for (int i = 1; i <= N; i++) {
        printf("%d ", i);  // Printing the numbers for verification purposes
        factorial *= i;
    }

    printf("The factorial of %d is %d\n", N, factorial);
    
    return 0;
    */



    /* Objective: Write a C program to calculate the factorial of a given positive integer N.
    
    int N, sum;

    printf("Enter the value of N: ");
    scanf("%d", &N);

    for (int i = 0; i <= N; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);  // Printing even numbers for verification purposes
            sum += i;
        }
    }
    
    printf("\nThe sum of all even numbers from 1 to %d is %d\n", N, sum);
    return 0;
    */