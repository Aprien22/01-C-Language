#include <stdio.h>

int main(){
    int seconds, hour, minutes;

    // Getting the number of seconds
    printf("Please enter the number of seconds: ");
    scanf("%d", &seconds);
    
    hour = seconds/3600;
    seconds %= 3600;

    minutes = seconds/60;
    seconds %= 60;

    // Outputting the converted value
    printf("You have %.2d:%.2d:%.2d", hour, minutes, seconds);

    return 0;

}