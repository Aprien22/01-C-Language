#include <stdio.h>

int main(){
    int hour, minutes;

    // Getting the number of hours
    printf("Please enter the number of hour/s: ");
    scanf("%d", &hour);
    
    // Converting the hour/s to minutes
    minutes = hour * 60;

    // Outputting the converted value
    printf("%d %s is equal to %d minutes.", hour, (hour > 1) ? "hours" : "hour", minutes);

    return 0;

}