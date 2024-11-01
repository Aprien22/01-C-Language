#include <stdio.h>

int main()
{
    //Declaration of variables     
    char name[80];
    int cash_on_hand,thousands ,fivehundreds ,onehundreds ,fifties ,twenties ,tens ,fives ,ones;

    // Getting the name and cash on hand
    printf("Hello, what's your name? ");
    scanf("%s", name);

    printf("Hello, %s. How many cash do you have right now? ", name);
    scanf("%d", &cash_on_hand);

    // Printing the cash on hand
    printf("Cash on hand: %d\n", cash_on_hand);

    // Calculating the denominations
    thousands = cash_on_hand/1000;
    cash_on_hand = cash_on_hand % 1000;
    
    fivehundreds = cash_on_hand/500;
    cash_on_hand = cash_on_hand % 500;
    
    onehundreds = cash_on_hand/100;
    cash_on_hand = cash_on_hand % 100;
    
    fifties = cash_on_hand/50;
    cash_on_hand = cash_on_hand % 50;

    twenties = cash_on_hand/20;
    cash_on_hand = cash_on_hand % 20;

    tens = cash_on_hand/10;
    cash_on_hand = cash_on_hand % 10;
    
    fives = cash_on_hand/5;
    cash_on_hand = cash_on_hand % 5;

    ones = cash_on_hand;

    //Printing the Denominations
    printf("Hello again, %s.\nDenominations: \n1000 - %d\n500 - %d\n100 - %d\n50 - %d\n20 - %d\n10 - %d\n5 - %d\n1 - %d\n", name, thousands, fivehundreds, onehundreds, fifties, twenties, tens, fives, ones);
}