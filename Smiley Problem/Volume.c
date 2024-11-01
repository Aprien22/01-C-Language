#include <stdio.h>

void main(){

    int length , width, height, volume;

    printf("Please enter the length: ");
    scanf("%d", &length);
    printf("Please enter the width: ");
    scanf("%d", &width);
    printf("Please enter the height: ");
    scanf("%d", &height);

    volume = length * width * height;

    printf("The volume of your box is, %d cm", volume);
}