#include <stdio.h>

int main() {
    char name [80];
    int height, age, citizenship, recommendee;

    printf("Hello, and welcome to Jedi Knigh Academy\nWhat is your name? ");
    scanf("%s", name);
    
    printf("Hello, %s, what is your height (in cm)? ", name);
    scanf("%d", &height);

    printf("How old are you? ");
    scanf("%d", &age);
    
    printf("Are you a citizen of Planet Endor? (1 - citizen, 0 - not): ");
    scanf("%d", &citizenship);

    printf("Are you a recomendee of Jedi Master Obi Wan (1 - recommended, 0 - not recommended): ");
    scanf("%d", &recommendee);
    
    if (recommendee == 1) {
        printf("Congratulations! %s, You are ACCEPTED via Jedi Master Obi Wan recommendation.\n", name);
    } 
    else {
        if (height >= 200) {
            if (age >= 21 && age <= 25) {
                if (citizenship == 1) {
                    printf("ACCEPTED. Congratulations! %s, you meet all the requirements.\n", name);
                } else {
                    printf("REJECTED. Not a citizen of Planet Endor.\n");
                }
            } else {
                printf("REJECTED. Did not meet the age requirement.\n");
            }
        } else {
            printf("REJECTED. Did not meet the height requirement.\n");
        }
    }
    return 0;
}
