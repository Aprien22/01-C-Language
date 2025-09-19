#include <stdio.h>

int main(){
    char name[80];
    int height, weight, age, highschool;


    printf("Hello, what is your name? ");
    scanf("%s", name);
    
    printf("Hello, %s, what is your height (in feet)? ", name); 
    scanf("%d", &height);

    printf("What is your weight (in kilos)? ");
    scanf("%d", &weight);
    
    printf("How old are you? ");
    scanf("%d", &age);

    printf("Did you at least graduate/completed Highschool (1 - YES, 0 - NO): ");
    scanf("%d", &highschool);

    if (height >= 5){
        if (weight == 50){
            if (age >= 18){
                if (highschool == 1){
                    printf("Congratulations %s, you are QUALIFIED/ACCEPTED", name);
                }
                else {
                    printf("Sorry %s, you are NOT ACCEPTED as you aren't a highschool graduate", name);
                }
            }
            else {
                printf("Sorry %s, you are NOT ACCEPTED as you are under 18 years old", name);
            }

        }
        else{ 
            printf("Sorry %s, you are NOT ACCEPTED as weigh above/below the 50 kilos", name);
        }
    }
    else {
        printf("Sorry %s, you are NOT ACCEPTED as your height is below 5 feet", name);
    }
    
    return 0;
}