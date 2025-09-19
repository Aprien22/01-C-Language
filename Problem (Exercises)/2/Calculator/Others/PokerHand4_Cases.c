#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Card
{
    int cardValue;
    char cardSuit[80];
};

void getCardsInHand(struct Card indiv, struct Card cardsInHand[], int index);
void printHand(int cardVal, char cardSuit[]); 
void sortHand(struct Card *cardsinHand);
void checkPokerHand(struct Card cardsinHand[]);


int main() {
    struct Card indivCard;
    struct Card cardsinHand[5];
    struct Card *pCardsinHand = cardsinHand; 
    char input[10];
    
    printf("==============================\n");
    printf("|        WELCOME TO          |\n");
    printf("|     POKER HAND CHECKER     |\n");
    
    do {
        printf("==============================\n");
        printf("Input Format: <value> <suit>\nValue: 1 - 13 (Ace - King)\nSuits: Hearts, Diamonds, Clubs, Spades\nExample: 1 Hearts\n");
        printf("==============================\n");
        printf("Enter your poker hand (5 cards):\n");
        
        for(int i = 0; i < 5; i++){
            getCardsInHand(indivCard, cardsinHand, i);
        }

        printf("==============================\n");
        printf("|         YOUR HAND          |\n");
        printf("==============================\n");

        for (int i = 0; i < 5; i++) {
            printHand(cardsinHand[i].cardValue, cardsinHand[i].cardSuit);
        }
        sortHand(pCardsinHand);
        
        printf("==============================\n");
        printf("|         SORTED HAND        |\n");
        printf("==============================\n");
        
        for (int i = 0; i < 5; i++) {
            printHand(cardsinHand[i].cardValue, cardsinHand[i].cardSuit);
        }

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

//Passing Whole Structure (and Array of Structures) to Functions
void getCardsInHand(struct Card indiv, struct Card cardsInHand[], int index)
{
    printf(">>> Card %d: ", index + 1);
    scanf("%d %s", &indiv.cardValue, indiv.cardSuit);
    while (indiv.cardValue < 1 || indiv.cardValue > 13) {
        printf(">>> Invalid card value. Please enter a value between 1 and 13: ");
        scanf("%d", &indiv.cardValue);
    }
    while (strcmp(indiv.cardSuit, "Hearts") != 0 && 
        strcmp(indiv.cardSuit, "Diamonds") != 0 && 
        strcmp(indiv.cardSuit, "Clubs") != 0 && 
        strcmp(indiv.cardSuit, "Spades") != 0) {
        printf(">>> Invalid suit. Please enter Hearts, Diamonds, Clubs, or Spades: ");
        scanf("%s", indiv.cardSuit);
    }
    cardsInHand[index].cardValue = indiv.cardValue;
    strcpy(cardsInHand[index].cardSuit, indiv.cardSuit);
}

//Passing Structure Member to Functions
void printHand(int cardVal, char cardSuit[]) {

    if (cardVal == 1)
        printf("Ace of %s\n", cardSuit);
    else if (cardVal == 11)
        printf("Jack of %s\n", cardSuit);
    else if (cardVal == 12)
        printf("Queen of %s\n", cardSuit);
    else if (cardVal == 13)
        printf("King of %s\n", cardSuit);
    else 
        printf("%d of %s\n", cardVal, cardSuit);
}


//Passing Structure Pointer to Function
void sortHand(struct Card *cardsinHand) {
    int tempValue;
    char tempSuit[80];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((cardsinHand + j)->cardValue > (cardsinHand + j + 1)->cardValue)
            {
                strcpy(tempSuit, (cardsinHand + j)->cardSuit);
                strcpy((cardsinHand + j)->cardSuit, (cardsinHand + j + 1)->cardSuit);
                strcpy((cardsinHand + j + 1)->cardSuit, tempSuit);

                tempValue = (cardsinHand + j)->cardValue;
                (cardsinHand + j)->cardValue =  (cardsinHand + j + 1)->cardValue;
                (cardsinHand + j + 1)->cardValue = tempValue;
            }  
        }
    }
}

//Passing Array of Structures to Function
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



