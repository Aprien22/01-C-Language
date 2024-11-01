#include <stdio.h>
#include <string.h>
#include "cs50.h"


int main(void)
{   
    string name = get_string("What's your name? ");
    printf("Hello, %s!\n", name);

    int age = get_int("How old are you? ");
    printf("%i!!\n", age);

    if (age <= 10){
        printf("Wow, you're so young.");
    }
    else if (age <= 12)
    {
        printf("Almost adult eh?");
    }
    else
    {
        printf("Wow you're an adult.");
    }
}


