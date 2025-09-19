#include <stdio.h>

void inputArrayValues(int rows, int columns, int myArray[rows][columns]);
void displayArrayInline(int rows, int columns, int myArray[rows][columns]);
void displayArrayTable(int rows, int columns, int myArray[rows][columns]);
void sortByRows(int rows, int columns, int myArray[rows][columns]); 
void sortByColumns(int rows, int columns, int myArray[rows][columns]);
void sortMainDiagonal(int rows, int columns, int myArray[rows][columns]);
void sortAntiDiagonal(int rows, int columns, int myArray[rows][columns]);
void sort2DArrayInPlaceBubble(int rows, int columns, int myArray[rows][columns]);
void sortByRowsBubble(int rows, int columns, int myArray[rows][columns]);
void sortByColumnsBubble(int rows, int columns, int myArray[rows][columns]);
void binarySearch2D(int rows, int columns, int myArray[rows][columns], int target);
void sortByRowsSelection(int rows, int columns, int myArray[rows][columns]); 
void sortByColumnsSelection(int rows, int columns, int myArray[rows][columns]);


int main() {
    int rows, columns, sortType, restartProgram, sortAgain, findAgain, target;

    do {
        printf("\nHello, Please enter some values for your 2D Array\n");
        printf("Please enter the number of rows: ");
        scanf("%d", &rows); 
        printf("Please enter the number of columns: ");
        scanf("%d", &columns);

        int myArray[rows][columns];

        inputArrayValues(rows, columns, myArray);
        displayArrayTable(rows, columns, myArray);
    
        do {
            printf("\nHow do you want it to be sorted\n1. Whole Array\n2. By Rows\n3. By Columns\n4. By Diagonals\n5. By AntiDiagonals\n>>> ");
            while (scanf("%d", &sortType) != 1 || sortType <= 0 || sortType >= 6) {
                printf("INVALID INPUT! Please enter integers from 1 - 5 only\n>>> ");
                while (getchar() != '\n');
            }

            switch (sortType)
            {
            case 1:
                sort2DArrayInPlaceBubble(rows, columns, myArray);
                displayArrayTable(rows, columns, myArray);
                break;

            case 2:
                sortByRowsSelection(rows, columns, myArray);
                displayArrayTable(rows, columns, myArray);
                break;
            case 3:
                sortByColumnsSelection(rows, columns, myArray);
                displayArrayTable(rows, columns, myArray);
                break;
            case 4: 
                sortMainDiagonal(rows, columns, myArray);
                displayArrayTable(rows, columns, myArray);
                break;
            case 5:
                sortAntiDiagonal(rows, columns, myArray);
                displayArrayTable(rows, columns, myArray);
                break;
            default:
                printf("Out of Bound Output.");
                break;
            }
            printf("\nDo you want to sort it another way (Any Number - Yes, 0 - No)?\n>>> ");

            while (scanf("%d", &sortAgain) != 1) {
                printf("INVALID INPUT! Please enter integers from 1 - 5 only\n>>> ");
                while (getchar() != '\n');
            }

        } while (sortAgain != 0);

        printf("\nSorting Completed!");

        do {
            printf("\n");
            printf("\nWhich number would you like to find inside the array?\n>>> ");
        
            while (scanf("%d", &target) != 1) {
            printf("INVALID INPUT! Please enter an integer.\n>>> ");
            while (getchar() != '\n');
            }

            binarySearch2D(rows, columns, myArray, target);
            printf("\n");
            printf("Do you want to find another number (Any Number - Yes, 0 - No)?\n>>> ");

            while (scanf("%d", &findAgain) != 1) {
                printf("INVALID INPUT! Please enter integers\n>>> ");
                while (getchar() != '\n');
            }
        } while (findAgain != 0);

        printf("\nFinding Completed!");
        printf("\nDo you want to restart the program (Any Number - Yes, 0 - No)?\n>>> ");

        while (scanf("%d", &restartProgram) != 1) {
            printf("INVALID INPUT! Please valid integer");
            while (getchar() != '\n');
        }

    } while (restartProgram != 0);

    printf("\nThank you for using the program!");
    
    return 0;
}

void inputArrayValues(int rows, int columns, int myArray[rows][columns]) {

    printf("\nEnter some value for myArray[%d][%d]:\n", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("myArray[%d][%d]: ", i, j);
            scanf("%d", &myArray[i][j]);
        }
    }
}

void displayArrayInline(int rows, int columns, int myArray[rows][columns]) {
    printf("\nDisplaying the Array in Inline Form\n");

    printf("{");
    for (int i = 0; i < rows; i++) {
        printf("{");
        for (int j = 0; j < columns; j++) {
            printf("%d", myArray[i][j]);
            
            if (j < columns - 1) {
                printf(", ");
            }
        }
        printf("}");
        
        if (i < rows - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}


void displayArrayTable(int rows, int columns, int myArray[rows][columns]) {
    printf("\n");
    printf("Displaying the Array in Table Form\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d", myArray[i][j]);

            if (j < columns - 1) {
                printf(",\t");
            }
        }
        printf("\n");
    }
}

void sortByRows(int rows, int columns, int myArray[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            int temp = myArray[i][j];
            int k = j - 1;

            while (k >= 0 && myArray[i][k] > temp) {
                myArray[i][k + 1] = myArray[i][k];
                k--;
            }
            myArray[i][k + 1] = temp;
        }
    }
}

void sortByColumns(int rows, int columns, int myArray[rows][columns]) {
    for (int i = 0; i < columns; i++) {
        for (int j = 1; j < rows; j++) {
            int temp = myArray[j][i];
            int k = j - 1;

            while (k >= 0 && myArray[k][i] > temp) {
                myArray[k+1][i] = myArray[k][i];
                k--;
            }
            myArray[k + 1][i] = temp;
        }
    }
}

void sortMainDiagonal(int rows, int columns, int myArray[rows][columns]) {
    int diagonalSize = (rows < columns) ? rows : columns; // Main diagonal length

    for (int i = 1; i < diagonalSize; i++) {
        int temp = myArray[i][i]; // Current element
        int k = i - 1;

        // Move elements of the diagonal that are greater than temp
        while (k >= 0 && myArray[k][k] > temp) {
            myArray[k + 1][k + 1] = myArray[k][k];
            k--;
        }
        myArray[k + 1][k + 1] = temp; // Insert at the correct position
    }
}

void sortAntiDiagonal(int rows, int columns, int myArray[rows][columns]) {
    int diagonalSize = (rows < columns) ? rows : columns; // Anti-diagonal length

    for (int i = 1; i < diagonalSize; i++) {
        int temp = myArray[i][columns - 1 - i]; // Current anti-diagonal element
        int k = i - 1;

        // Move elements of the anti-diagonal that are greater than temp
        while (k >= 0 && myArray[k][columns - 1 - k] > temp) {
            myArray[k + 1][columns - 1 - (k + 1)] = myArray[k][columns - 1 - k];
            k--;
        }
        myArray[k + 1][columns - 1 - (k + 1)] = temp; // Insert at the correct position
    }
}


void sort2DArrayInPlaceBubble(int rows, int columns, int myArray[rows][columns]) {
    for (int i = 0; i < rows * columns; i++) {
        int row1 = i / columns;
        int col1 = i % columns;

        for (int j = i + 1; j < rows * columns; j++) {
            int row2 = j / columns;
            int col2 = j % columns;

            if (myArray[row1][col1] > myArray[row2][col2]) {
                int temp = myArray[row1][col1];
                myArray[row1][col1] = myArray[row2][col2];
                myArray[row2][col2] = temp;
            }
        }
    }
}

void sortByRowsBubble(int rows, int columns, int myArray[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns - 1; j++) {
            for (int k = 0; k < columns - j - 1; k++) {
                int temp = myArray[i][k];
                myArray[i][k] = myArray[i][k + 1];
                myArray[i][k + 1] = temp;
            }
        }
    }
}

void sortByColumnsBubble(int rows, int columns, int myArray[rows][columns]) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows - 1; j++) {
            for (int k = 0; k < rows - j - 1; k++) {
                int temp = myArray[k][i];
                myArray[k][i] = myArray[k + 1][i];
                myArray[k + 1][i] = temp;
            }
        }
    }
}

void sortByRowsSelection(int rows, int columns, int myArray[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns - 1; j++){
            int min_idx = j;

            for (int k = j + 1; k < columns; k++){
                if (myArray[i][k] < myArray[i][min_idx])
                    min_idx = k;
            }
            if (min_idx != j) {
                int temp = myArray[i][j];
                myArray[i][j] = myArray[i][min_idx];
                myArray[i][min_idx] = temp;
            }
        }
    }    
}

void sortByColumnsSelection(int rows, int columns, int myArray[rows][columns]) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows - 1; j++){
            int min_idx = j;

            for (int k = j + 1; k < rows; k++){
                if (myArray[k][i] < myArray[min_idx][i])
                    min_idx = k;
            }
            if (min_idx != j) {
                int temp = myArray[j][i];
                myArray[j][i] = myArray[min_idx][i];
                myArray[min_idx][i] = temp;
            }
        }
    }    
}

void binarySearch2D(int rows, int columns, int myArray[rows][columns], int target) {
    int low = 0, high = rows * columns - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int row = mid / columns;
        int column = mid % columns;

        if (myArray[row][column] == target) {
            printf("\nTarget number found at index myArray[%d][%d]", row, column);
            return;
        }
        else if (myArray[row][column] < target) {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    printf("\nTarget number not found inside the Array.");
}


#include <stdio.h>

// Recursive function to calculate factorial of n
int factorial(int n) {
    // Base case: When n is 0, return 1
    if (n == 0) {
        return 1;
    }

    // Recursive case: Multiply n by factorial(n-1)
    // The function call factorial(n-1) is pushed onto the stack
    int result = n * factorial(n - 1);

    // After the recursive call returns, the current function call is popped from the stack
    return result;
}

int main() {
    int number = 5;
    printf("Factorial of %d: %d\n", number, factorial(number));

    // Explanation of stack during recursion:
    // factorial(5) is called
    //   → factorial(4) is called
    //     → factorial(3) is called
    //       → factorial(2) is called
    //         → factorial(1) is called
    //           → factorial(0) is called → Base case reached, return 1
    //         ← factorial(1): 1 * 1 = 1 (returned and popped from stack)
    //       ← factorial(2): 2 * 1 = 2 (returned and popped from stack)
    //     ← factorial(3): 3 * 2 = 6 (returned and popped from stack)
    //   ← factorial(4): 4 * 6 = 24 (returned and popped from stack)
    // ← factorial(5): 5 * 24 = 120 (returned and popped from stack)
    // Final result: 120

    return 0;
}
