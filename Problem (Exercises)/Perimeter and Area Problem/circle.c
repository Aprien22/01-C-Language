#include <stdio.h>

int main()
{
    // Declare variables
    char name[80];
    float pi = 3.14;
    float radius, area, circumference;

    // Input name
    printf("Hello, please enter your name: ");
    scanf("%s", name);

    //Input Radius
    printf("Hello, %s. Please enter the radius of your circle: \n", name);
    scanf("%f", &radius);

    // Calculate the area and circumference of the circle
    circumference = 2 * pi * radius;
    area = pi * radius * radius;

    printf("Hello, %s.\nYour circle, with the radius of %f\nHas an Area of %f unit^2 and a Circumference of %f unit", name, radius, area, circumference);
}