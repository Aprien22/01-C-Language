#include <stdio.h>

int sum(int a, int b){
    return a + b;
}
int difference(int a, int b){
    return a - b;
}
int product(int a, int b){
    return a * b;
}
int quotient(int a, int b){
    if (b != 0) 
        return a / b;
    else {
        printf("Error: Division by zero is not allowed.");
        return 0;

    }
}

void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

int main() {
    char operation;
    int num1, num2, result;

    printf("Please enter an operator (+, -, *, /): ");
    scanf("%c", &operation);

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

        switch (operation)
        {
        case '+':
            result = sum(num1, num2);
            break;
        case '-':
            result = difference(num1, num2);
            break;
        case '*':
            result = product(num1, num2);
            break;
        case '/':
            result = quotient(num1, num2);
            break;
        default:
            printf("Invalid operator. Please try again.");
            break;
        }  
        printf("%d %c %d = %d\n", num1, operation, num2, result);

        printf("BEFORE: %d & %d\n", num1, num2);
        swap(&num1, &num2);
        printf("AFTER: %d & %d\n", num1, num2);
}