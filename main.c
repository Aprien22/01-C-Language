// C Language Cheat Sheet

// 1. Header Files
#include <stdio.h>  // Standard Input/Output
#include <stdlib.h> // Standard Library
#include <string.h> // String manipulation
#include <math.h>   // Mathematical functions

int main()
{
    // 2. Variable Types
    int integer = 10;           // Integer
    float floating = 3.14;      // Floating point
    double doublePrecision = 3.141592653589793; // Double precision float
    char character = 'A';       // Single character
    char string[50] = "Hello, World!"; // String (character array)

    // 3. Constants
    const int CONSTANT_INT = 100;
    #define MACRO_CONSTANT 200

    // 4. Input and Output
    printf("Enter an integer: ");
    scanf("%d", &integer);

    printf("Enter a float: ");
    scanf("%f", &floating);

    // 5. Arithmetic Operators
    int a = 10, b = 5;
    printf("Sum: %d\n", a + b);
    printf("Difference: %d\n", a - b);
    printf("Product: %d\n", a * b);
    printf("Quotient: %d\n", a / b);
    printf("Remainder: %d\n", a % b);

    // 6. Conditional Statements
    if (a > b) {
        printf("a is greater than b\n");
    } else if (a < b) {
        printf("a is less than b\n");
    } else {
        printf("a is equal to b\n");
    }

    // 7. Switch Statement
    switch (a) {
        case 1:
            printf("One\n");
            break;
        case 2:
            printf("Two\n");
            break;
        default:
            printf("Other\n");
    }

    // 8. Loops
    // For loop
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // While loop
    int j = 0;
    while (j < 5) {
        printf("%d ", j);
        j++;
    }
    printf("\n");

    // Do-while loop
    int k = 0;
    do {
        printf("%d ", k);
        k++;
    } while (k < 5);
    printf("\n");

    // 9. Arrays
    int numbers[5] = {1, 2, 3, 4, 5};
    
    // 10. Functions (declaration and definition)
    int sum(int x, int y);  // Function declaration

    int result = sum(3, 4);
    printf("Sum: %d\n", result);

    // 11. Pointers
    int *ptr = &a;
    printf("Value of a: %d\n", *ptr);

    // 12. Structures
    struct Person {
        char name[50];
        int age;
    };

    struct Person person1 = {"John Doe", 30};
    printf("Name: %s, Age: %d\n", person1.name, person1.age);

    // 13. File I/O
    FILE *file = fopen("example.txt", "w");
    if (file != NULL) {
        fprintf(file, "Hello, File!");
        fclose(file);
    }

    return 0;
}

// Function definition
int sum(int x, int y) {
    return x + y;
}
