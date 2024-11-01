#include<stdio.h>
int main() {

    char name[80];
    float  x, y, z, perimeter;

    printf("Hello, please enter your name: ");
    scanf("%s", name);
    
    printf("Hello, %s. Please enter the first number: ", name); 
    scanf("%f", &x);
    
    printf("Enter the second number: ");
    scanf("%f", &y);
    
    printf("Enter the third number: ");
    scanf("%f", &z);

    
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