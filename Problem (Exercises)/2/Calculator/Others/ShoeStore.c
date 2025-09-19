#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZES 12

struct ShoeInventory {
    int shoeStockNum;
    int shoeStyleNum;
    int shoeStockOnHand[SIZES];
    float shoePrice;
};

void displayStockRecord(struct ShoeInventory shoeStock[], int *totalStock);
void enterStockRecord(struct ShoeInventory stock[], int *currentStockIndex);
void changeStockPrice(struct ShoeInventory stock[], int *currentStockIndex);
void changeStockOnHand(struct ShoeInventory stock[], int *currentStockIndex);

int main () {
    struct ShoeInventory shoeStock[100];
    int choice, stockIndex, currentStockIndex = 0;
    int* ptrCSI = &currentStockIndex;

    do {
        printf("\n===================================");
        printf("\nWELCOME TO SHOE INVENTORY TRACKER!\n1. Enter a New Record\n2. Display a Record\n3. Change the Price of a Stock\n4. Change the Stock on Hand\n5. Exit\n");

        printf("\n>>> What would you like to do (1 - 5 only)? ");
        scanf("%d", &choice);
        while (choice < 1 || choice > 5) {
            printf(">>> INVALID INPUT. Enter a number between 1 and 5: ");
            while (getchar() != '\n'); 
            scanf("%d", &choice);
        }

        if(choice == 1) {
            enterStockRecord(shoeStock, ptrCSI);
        }
        else if (choice == 2) {
            displayStockRecord(shoeStock, ptrCSI);
        }
        else if(choice == 3)
            changeStockPrice(shoeStock, ptrCSI);
        else if(choice == 4) {
            changeStockOnHand(shoeStock, ptrCSI);
        }
        else
            break;
    } while (choice != 5);

    printf("\nTHANK YOU FOR USING THE PROGRAM! <3 <3 <3");
    return 0;
}

void enterStockRecord(struct ShoeInventory stock[], int *currentStockIndex) {
    printf("\n===================================");
    printf("\nENTER A NEW RECORD\n");
    stock[*currentStockIndex].shoeStockNum = *currentStockIndex + 1;

    printf("STOCK %d\n", stock[*currentStockIndex].shoeStockNum);
    printf(">>> SHOE STYLE NUMBER (0 - 50): ");
    scanf("%d", &stock[*currentStockIndex].shoeStyleNum);
    while (stock[*currentStockIndex].shoeStyleNum < 0 || stock[*currentStockIndex].shoeStyleNum > 50) {
        printf(">>> INVALID. Enter style number (0 - 50): ");
        while (getchar() != '\n');
        scanf("%d", &stock[*currentStockIndex].shoeStyleNum);
    }

    printf(">>> SHOE STOCK ON HAND:\n");
    for (int i = 0; i < SIZES; i++) {
        printf("Size %d: ", i + 3);
        scanf("%d", &stock[*currentStockIndex].shoeStockOnHand[i]);
        while (stock[*currentStockIndex].shoeStockOnHand[i] < 0) {
            printf(">>> INVALID. Enter non-negative quantity for Size %d: ", i + 3);
            while (getchar() != '\n');
            scanf("%d", &stock[*currentStockIndex].shoeStockOnHand[i]);
        }
    }

    printf(">>> SHOE PRICE: ");
    scanf("%f", &stock[*currentStockIndex].shoePrice);
    while (stock[*currentStockIndex].shoePrice < 0) {
        printf(">>> INVALID. Enter a positive price: ");
        while (getchar() != '\n');
        scanf("%f", &stock[*currentStockIndex].shoePrice);
    }

    printf("NEW STOCK ADDED!!!\n");
    (*currentStockIndex)++;

}

void displayStockRecord(struct ShoeInventory stock[], int *currentStockIndex) {
    int found = 0, searchBy = 0, searchNum = 0;

    printf("\n===================================");
    printf("\nDISPLAY A RECORD\n");
    printf(">>> Do you want to search by Stock - 0 or Style - 1: ");
    scanf("%d", &searchBy);
    (searchBy == 0) ? printf(">>> STOCK NUMBER: ") : printf(">>> STYLE NUMBER: ");
    scanf("%d", &searchNum);

    printf("===================================\n");
    printf("\nDISPLAYING RECORD/S:\n");
    for (int i = 0; i < *currentStockIndex; i++) {
        if ((!searchBy && stock[i].shoeStockNum == searchNum) || 
            (searchBy && stock[i].shoeStyleNum == searchNum)) {
            
            found = 1;
            printf("\nSTOCK NUMBER: %d\n", stock[i].shoeStockNum);
            printf("STYLE NUMBER: %d\n", stock[i].shoeStyleNum);
            printf("STOCK ON HAND: \n");
            for (int j = 0; j < SIZES/2; j++){
                printf("Size %d: %d\t Size %d: %d\n", 
                    j + 3, stock[i].shoeStockOnHand[j], 
                    j + 9, stock[i].shoeStockOnHand[j + 6]);
            }
            printf("PRICE: PHP %.2f\n", stock[i].shoePrice);

        }
    }
    if (!found)
        printf("\nNo records found for %s Number: %d\n", searchBy ? "Style" : "Stock", searchNum);
}

void changeStockPrice(struct ShoeInventory stock[], int *currentStockIndex) {
    int pickedStock = 0;

    printf("===================================\n");
    printf("CHANGING STOCK's PRICE:\n");

    do {
        printf(">>> Which Stock's Price would you like to change (1 to %d)? ", *currentStockIndex);
        scanf("%d", &pickedStock);
        while (getchar() != '\n');
    } while (pickedStock < 1 || pickedStock > *currentStockIndex);

    printf("STOCK %d CURRENT PRICE: %.2f \n", pickedStock, stock[pickedStock - 1].shoePrice);

    do {
        printf(">>> STOCK %d NEW PRICE (must be non-negative): ", pickedStock);
        scanf("%f", &stock[pickedStock - 1].shoePrice);
        while (getchar() != '\n');
    } while (stock[pickedStock - 1].shoePrice < 0);

    printf("STOCK %d - PRICE UPDATED!!!\n", pickedStock);
    printf("STOCK %d CURRENT PRICE: PHP %.2f\n", pickedStock, stock[pickedStock - 1].shoePrice);
}


void changeStockOnHand(struct ShoeInventory stock[], int *currentStockIndex) {
    int pickedStock = 0;

    printf("===================================\n");
    printf("CHANGING STOCK ON HAND:\n");

    do {
        printf(">>> Which Stock would you like to change (1 to %d)? ", *currentStockIndex);
        scanf("%d", &pickedStock);
        while (getchar() != '\n');
    } while (pickedStock < 1 || pickedStock > *currentStockIndex);

    printf("STOCK %d - CURRENT STOCK ON HAND:\n", pickedStock);
    for (int i = 0; i < SIZES / 2; i++) {
        printf("Size %d: %d\t Size %d: %d\n", 
            i + 3, stock[pickedStock - 1].shoeStockOnHand[i], 
            i + 9, stock[pickedStock - 1].shoeStockOnHand[i + 6]);
    }

    printf(">>> STOCK %d - NEW STOCK ON HAND (Pairs per Size 3 - 14):\n", pickedStock);
    for (int j = 0; j < SIZES; j++) {
        do {
            printf("Size %d: ", j + 3);
            scanf("%d", &stock[pickedStock - 1].shoeStockOnHand[j]);
            while (getchar() != '\n');
        } while (stock[pickedStock - 1].shoeStockOnHand[j] < 0);
    }

    printf("STOCK %d - STOCKS ON HAND UPDATED!!!\n", pickedStock);
    printf("STOCK %d - CURRENT STOCK ON HAND:\n", pickedStock);
    for (int k = 0; k < SIZES / 2; k++) {
        printf("Size %d: %d\t Size %d: %d\n", 
            k + 3, stock[pickedStock - 1].shoeStockOnHand[k], 
            k + 9, stock[pickedStock - 1].shoeStockOnHand[k + 6]);
    }
}
