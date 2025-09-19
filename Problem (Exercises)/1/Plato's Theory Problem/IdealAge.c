#include <stdio.h>

void main()
{
    int idealAge, yourAge;

    printf("Please enter your age: ");
    scanf("%d", &yourAge);

    idealAge = yourAge / 2 + 7;

    printf("Your partner's Ideal age is, %d", idealAge);
}