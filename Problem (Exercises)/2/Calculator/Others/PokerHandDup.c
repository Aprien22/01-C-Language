#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Card
{
    int cardValue;
    char cardSuit[80];
};

void sortHand(struct Card cardsinHand[]);
void printHand(struct Card cardsinHand[]);
void checkPokerHand(struct Card cardsinHand[]);


int main() {
    struct Card cardsinHand[5];
    char input[10];
    
    printf("==============================\n");
    printf("|        WELCOME TO          |\n");
    printf("|     POKER HAND CHECKER     |\n");
    
    do {
        printf("==============================\n");
        printf("Input Format: <value> <suit>\nValue: 1 - 13 (Ace - King)\nSuits: Hearts, Diamonds, Clubs, Spades\nExample: 1 Hearts\n");
        printf("==============================\n");
        printf("Enter your poker hand (5 cards):\n");
        
        for (int i = 0; i < 5; i++) {
            printf(">>> Card %d: ", i + 1);
            scanf("%d %s", &cardsinHand[i].cardValue, cardsinHand[i].cardSuit);
            while (cardsinHand[i].cardValue < 1 || cardsinHand[i].cardValue > 13) {
                printf(">>> Invalid card value. Please enter a value between 1 and 13: ");
                scanf("%d", &cardsinHand[i].cardValue);
            }
            while (strcmp(cardsinHand[i].cardSuit, "Hearts") != 0 && 
                strcmp(cardsinHand[i].cardSuit, "Diamonds") != 0 && 
                strcmp(cardsinHand[i].cardSuit, "Clubs") != 0 && 
                strcmp(cardsinHand[i].cardSuit, "Spades") != 0) {
                printf(">>> Invalid suit. Please enter Hearts, Diamonds, Clubs, or Spades: ");
                scanf("%s", cardsinHand[i].cardSuit);
            }
        }

        printf("==============================\n");
        printf("|         YOUR HAND          |\n");
        printf("==============================\n");

        printHand(cardsinHand);
        sortHand(cardsinHand);
        
        printf("==============================\n");
        printf("|         SORTED HAND        |\n");
        printf("==============================\n");
        printHand(cardsinHand);

        printf("==============================\n");
        printf("|      CONGRATULATIONS!      |\n");
        printf("==============================\n");
        
        checkPokerHand(cardsinHand);
        printf("==============================\n");

    
        printf(">>> Do you want to try another hand (Yes/No)? ");
        scanf("%s", input);

        while (strcmp(input, "Yes") != 0 && strcmp(input, "No") != 0) {
            printf(">>> Invalid input. Please enter Yes or No: ");
            scanf("%s", input);
        }

    } while (strcmp(input, "Yes") == 0);

    printf("==============================\n");
    printf("|         THANK YOU!         |\n");
    printf("==============================\n");
    return 0;

}
void checkPokerHand(struct Card cardsinHand[]) {
    int cardRanks[5];
    char cardSuits[5][80];

    for (int i = 0; i < 5; i++) {
        cardRanks[i] = cardsinHand[i].cardValue;
        strcpy(cardSuits[i], cardsinHand[i].cardSuit);
    }

    // Straight Flush
    if (((strcmp(cardSuits[0], cardSuits[1]) == 0) && 
         (strcmp(cardSuits[0], cardSuits[2]) == 0) && 
         (strcmp(cardSuits[0], cardSuits[3]) == 0) && 
         (strcmp(cardSuits[0], cardSuits[4]) == 0))
        && 
        ((cardRanks[4] - cardRanks[3] == 1) && 
         (cardRanks[3] - cardRanks[2] == 1) && 
         (cardRanks[2] - cardRanks[1] == 1) && 
         (cardRanks[1] - cardRanks[0] == 1))) {
        
            printf("===== A Straight Flush! =====\n");
    }

     // Four of A Kind
    else if (((cardRanks[0] == cardRanks[1]) && 
         (cardRanks[0] == cardRanks[2]) && 
         (cardRanks[0] == cardRanks[3]))
        || 
        ((cardRanks[4] == cardRanks[3]) && 
         (cardRanks[4] == cardRanks[2]) && 
         (cardRanks[4] == cardRanks[1]))) {
        
            printf("===== A Four of A Kind! =====\n");
    }

    // Full House
    else  if (((cardRanks[0] == cardRanks[1]) && 
         (cardRanks[0] == cardRanks[2]) && 
         (cardRanks[3] == cardRanks[4])) 
        || 
        ((cardRanks[2] == cardRanks[3]) && 
         (cardRanks[2] == cardRanks[4]) && 
         (cardRanks[0] == cardRanks[1]))) {

            printf("===== A Full House! =====\n");
    }

    // Flush
    else if ((strcmp(cardSuits[0], cardSuits[1]) == 0) && 
             (strcmp(cardSuits[0], cardSuits[2]) == 0) && 
             (strcmp(cardSuits[0], cardSuits[3]) == 0) && 
             (strcmp(cardSuits[0], cardSuits[4]) == 0)) {
        
                printf("===== A Flush! =====\n");
    }

    // Straight
    else if ((cardRanks[4] - cardRanks[3] == 1) && 
             (cardRanks[3] - cardRanks[2] == 1) && 
             (cardRanks[2] - cardRanks[1] == 1) && 
             (cardRanks[1] - cardRanks[0] == 1)) {
        
                printf("===== A Straight! =====\n");
    }

    // Three of A Kind
    else if (((cardRanks[0] == cardRanks[1]) && 
             (cardRanks[0] == cardRanks[2])) 
        || 
            ((cardRanks[2] == cardRanks[3]) && 
             (cardRanks[2] == cardRanks[4]))) {
        
                printf("===== A Three of A Kind! =====\n");
    }
    // Two Pair
    else if (((cardRanks[0] == cardRanks[1]) && 
             (cardRanks[2] == cardRanks[3])) 
        || 
            ((cardRanks[0] == cardRanks[1]) && 
             (cardRanks[3] == cardRanks[4])) 
        || 
            ((cardRanks[1] == cardRanks[2]) && 
             (cardRanks[3] == cardRanks[4]))) {
        
                printf("===== A Two Pair! =====\n");
    }
    else if ((cardRanks[0] == cardRanks[1]) || 
             (cardRanks[1] == cardRanks[2]) || 
             (cardRanks[2] == cardRanks[3]) || 
             (cardRanks[3] == cardRanks[4])) {
        
                printf("===== A One Pair! =====\n");
    }

    else {
        printf("===== Nothing! =====\n");
    }
}

void sortHand(struct Card cardsinHand[]) {
    int tempValue;
    char tempSuit[80];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (cardsinHand[j].cardValue > cardsinHand[j + 1].cardValue)
            {
                strcpy(tempSuit, cardsinHand[j].cardSuit);
                strcpy(cardsinHand[j].cardSuit, cardsinHand[j + 1].cardSuit);
                strcpy(cardsinHand[j + 1].cardSuit, tempSuit);

                tempValue = cardsinHand[j].cardValue;
                cardsinHand[j].cardValue =  cardsinHand[j + 1].cardValue;
                cardsinHand[j + 1].cardValue = tempValue;
            }  
        }
    }
}

void printHand(struct Card cardsinHand[]) {
    for (int i = 0; i < 5; i++) {
        if (cardsinHand[i].cardValue == 1)
            printf("Ace of %s\n", cardsinHand[i].cardSuit);
        else if (cardsinHand[i].cardValue == 11)
            printf("Jack of %s\n", cardsinHand[i].cardSuit);
        else if (cardsinHand[i].cardValue == 12)
            printf("Queen of %s\n", cardsinHand[i].cardSuit);
        else if (cardsinHand[i].cardValue == 13)
            printf("King of %s\n", cardsinHand[i].cardSuit);
        else 
            printf("%d of %s\n", cardsinHand[i].cardValue, cardsinHand[i].cardSuit);
    }
}


