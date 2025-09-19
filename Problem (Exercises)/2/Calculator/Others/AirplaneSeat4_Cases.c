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

void plotAirplaneSeats(struct AirplaneSeat airplaneSeats[ROWS][COLUMNS], struct AirplaneSeat individualSeat, int row, int column, char rowSeats[]); 
void setUpAirplaneSeats(struct AirplaneSeat airplaneSeats[ROWS][COLUMNS], int rowSeat, int columnSeat, int isOccupied, int row, int column);
void printAllSeats(struct AirplaneSeat seats[ROWS][COLUMNS]);
void displayAirplaneSeats(int isOccupied, char columnSeat);
void pickAirplaneSeat(struct AirplaneSeat airplaneSeats[ROWS][COLUMNS], int* filledSeats);
void checkAirplaneSeat(struct AirplaneSeat* seats, int row, int column, int* filledSeats);
void toCapzString(char string[]);


int main(){
    struct AirplaneSeat airplaneSeats[ROWS][COLUMNS];
    struct AirplaneSeat individualSeat;
    char rowSeats[4] = {'A', 'B', 'C', 'D'};
    int filledSeats = 0;
    int* pFSeats = &filledSeats; 
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            plotAirplaneSeats(airplaneSeats, individualSeat, i, j, rowSeats);
        }
    }

    printf("\nWELCOME TO AIRPLANE 002\nCURRENTLY AVAILABLE SEATS: %d/%d\n", *pFSeats, ROWS * COLUMNS);
    printAllSeats(airplaneSeats);


    pickAirplaneSeat(airplaneSeats, pFSeats);
    printf("\nTHANK YOU FOR USING THE PROGRAM! <3 <3 <3");

    return 0;
}

//Passing Whole Structure (& Array of Structures) to Functions
void plotAirplaneSeats(struct AirplaneSeat airplaneSeats[ROWS][COLUMNS], struct AirplaneSeat individualSeat, int row, int column, char rowSeats[]) {
    individualSeat.rowSeat = row + 1;
    individualSeat.columnSeat = rowSeats[column];
    individualSeat.isOccupied = 0;

    setUpAirplaneSeats(airplaneSeats, individualSeat.rowSeat, individualSeat.columnSeat, individualSeat.isOccupied, row, column);
}
//Passing Structure Member (& Array of Structures) to Functions
void setUpAirplaneSeats(struct AirplaneSeat airplaneSeats[ROWS][COLUMNS], int rowSeat, int columnSeat, int isOccupied, int row, int column) {
    airplaneSeats[row][column].rowSeat = rowSeat;
    airplaneSeats[row][column].columnSeat = columnSeat;
    airplaneSeats[row][column].isOccupied = isOccupied;
}

//Passing Structure Member to Functions
void printAllSeats(struct AirplaneSeat seats[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < COLUMNS; j++) {
            displayAirplaneSeats(seats[i][j].isOccupied, seats[i][j].columnSeat);
        }
        printf("\n");
    }
}

//Passing Structure Member to Functions
void displayAirplaneSeats(int isOccupied, char columnSeat) {
    if (isOccupied)
        printf("X\t");
    else 
        printf("%c\t", columnSeat);
}

//Passing Array of Structures to Function
void pickAirplaneSeat(struct AirplaneSeat airplaneSeats[ROWS][COLUMNS], int* filledSeats) {
    int pickedRow = 0;
    char pickedColumn, tryAgain[80];


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

        checkAirplaneSeat(&airplaneSeats[rowIndex][colIndex], rowIndex, colIndex, filledSeats); 

         if (*filledSeats == ROWS * COLUMNS) {
            printf("SEATS ARE FULLY OCCUPIED!\n");
            printAllSeats(airplaneSeats);
            return;
        }

        printf("CURRENTLY AVAILABLE SEATS: %d/%d\n", *filledSeats, ROWS * COLUMNS);
        printAllSeats(airplaneSeats);

        printf("\n>>> Would you like to try again (YES / NO only): \n>>> ");
        scanf("%s", tryAgain);
        toCapzString(tryAgain);

        while ((strcmp(tryAgain, "YES") != 0) && (strcmp(tryAgain, "NO") != 0)) { 
            printf("\n>>> Invalid Input. Please try again (YES / NO only): \n>>> ");
            scanf("%s", tryAgain);
            toCapzString(tryAgain);
        }
        
    } while ((strcmp(tryAgain, "YES") == 0));
}

//Passing Structure Pointer to Function (76)
void checkAirplaneSeat(struct AirplaneSeat* seats, int row, int column, int* filledSeats) {
    if (seats->isOccupied) {
        printf("SEAT %d%c IS OCCUPIED. PLEASE CONSIDER OTHER SEATS. \n\n", row + 1, column + 'A');
    }
    else {
        seats->isOccupied = 1;
        *filledSeats += 1;
        printf("YOU SUCCESSFULLY PICKED %d%c!\n\n", row + 1, column + 'A');
    }
}

void toCapzString(char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
}