#include<stdio.h>

/*
Write a program that reads three floating values and check if it is possible to make a triangle with them. 
Also calculate the perimeter of the triangle if the entered values are valid
*/
int main() {

    //Declare the variables
    char name[80];
    float  x, y, z, perimeter;

    //Get the name
    printf("Hello, please enter your name: ");
    scanf("%s", name);
    
    //Get the three floating value
    printf("Hello, %s. Please enter the first number: ", name); 
    scanf("%f", &x);
    
    printf("Enter the second number: ");
    scanf("%f", &y);
    
    printf("Enter the third number: ");
    scanf("%f", &z);

    //Check and Caluclate if the triangle is valid.
    if(x < (y+z) && y < (x+z) && z < (y+x)) 
        {  
        perimeter = x + y + z;
        printf("\nHello, %s. The perimeter of the triangle is: %f\n", name, perimeter);	 
        }
    else 
        {
        printf("\nIt is IMPOSSIBLE to form a triangle.");
        }
    return 0;
}