#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ROWS 5
#define COLUMNS 4

struct AirplaneSeat {
    int rowSeat;
    char columnSeat;
    int isOccupied; //1 - Occupied, 0 - Not Occupied
};

void displayAirplaneSeats(struct AirplaneSeat airplaneSeat[ROWS][COLUMNS]);
void pickAirplaneSeat(struct AirplaneSeat airplaneSeats[ROWS][COLUMNS], int* filledSeats);
void toCapzString(char string[]);


int main(){
    struct AirplaneSeat airplaneSeats[ROWS][COLUMNS];
    char rowSeats[4] = {'A', 'B', 'C', 'D'};
    int filledSeats = 0;
    int* pFSeats = &filledSeats; 
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            airplaneSeats[i][j].rowSeat = i + 1;
            airplaneSeats[i][j].columnSeat = rowSeats[j];
            airplaneSeats[i][j].isOccupied = 0;
        }
    }

    pickAirplaneSeat(airplaneSeats, pFSeats);
    printf("\nTHANK YOU FOR USING THE PROGRAM! <3 <3 <3");

    return 0;
}

void pickAirplaneSeat(struct AirplaneSeat airplaneSeats[ROWS][COLUMNS], int* filledSeats) {
    int pickedRow = 0;
    char pickedColumn, tryAgain[80];

    printf("\nWELCOME TO AIRPLANE 002\nCURRENTLY AVAILABLE SEATS: %d/%d\n", *filledSeats, ROWS * COLUMNS);
    displayAirplaneSeats(airplaneSeats);

    do {
        printf("\n>>> Which seat would you like to reserve (Numbers 1 - 5 & Letters A - D only)(Example: 1A): \n>>> ");
        scanf("%d %c", &pickedRow, &pickedColumn);
        while (getchar() != '\n');
        pickedColumn = toupper(pickedColumn);

        while (pickedRow < 1 || pickedRow > 5 || pickedColumn < 'A' || pickedColumn > 'D')
        {
            printf("\n>>> Invalid Input. Please try again (Numbers 1 - 5 & Letters A - D only)(Example: 1A): \n>>> ");
            scanf("%d %c", &pickedRow, &pickedColumn);
            while (getchar() != '\n');
            pickedColumn = toupper(pickedColumn);
        }

        int rowIndex = pickedRow - 1, colIndex = pickedColumn - 'A';

        if (airplaneSeats[rowIndex][colIndex].isOccupied) {
            printf("SEAT %d%c IS OCCUPIED. PLEASE CONSIDER OTHER SEATS. \n", pickedRow, pickedColumn);
            continue;
        }
        else {
            airplaneSeats[rowIndex][colIndex].isOccupied = 1;
            *filledSeats += 1;
            printf("YOU SUCCESSFULLY PICKED %d%c!\n\n", pickedRow, pickedColumn);

            if (*filledSeats == ROWS * COLUMNS) {
                printf("SEATS ARE FULLY OCCUPIED!\n");
                displayAirplaneSeats(airplaneSeats);
                return;
            }
            printf("CURRENTLY AVAILABLE SEATS: %d/%d\n", *filledSeats, ROWS * COLUMNS);
            displayAirplaneSeats(airplaneSeats);

            printf("\n>>> Would you like to try again (YES / NO only): \n>>> ");
            scanf("%s", tryAgain);
            toCapzString(tryAgain);

            while ((strcmp(tryAgain, "YES") != 0) && (strcmp(tryAgain, "NO") != 0)) { 
                printf("\n>>> Invalid Input. Please try again (YES / NO only): \n>>> ");
                scanf("%s", tryAgain);
                toCapzString(tryAgain);
            }
        }
    } while ((strcmp(tryAgain, "YES") == 0));
}

void displayAirplaneSeats(struct AirplaneSeat airplaneSeats[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < COLUMNS; j++) {
            if (airplaneSeats[i][j].isOccupied)
                printf("X\t");
            else 
                printf("%c\t", airplaneSeats[i][j].columnSeat);
        } 
        printf("\n");
    }
}

void toCapzString(char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
}