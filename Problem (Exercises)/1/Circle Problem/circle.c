#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    char name[80];
    float pi = 3.14f;
    float radius, area, circumference;

    printf("Hello, please enter your name: ");
    fgets(name, sizeof(name), stdin); // safer for names with spaces

    printf("Hello, %sPlease enter the radius of your circle: ", name);
    while (scanf("%f", &radius) != 1 || radius <= 0) {
        printf("Invalid radius entered. Please Enter a Valid Number: \n");
        while (getchar() != '\n'); // clear input buffer
    }

    circumference = 2 * pi * radius;
    area = pi * radius * radius;

    printf("Hello, %sYour circle, with the radius of %.2f\nHas an Area of %.2f unit^2 and a Circumference of %.2f unit\n", name, radius, area, circumference);
    return 0;
}