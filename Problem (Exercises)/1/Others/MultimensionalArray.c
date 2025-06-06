#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void displayArray(int rows, int columns, int myArray[rows][columns]);
void insertionSortByRows(int myArray[], int columns);
void insertionSortByColumns(int rows, int columns, int myArray[rows][columns], int columnIndex);
void findNumber(int rows, int columns, int myArray[rows][columns], bool isTransposed);
void findMinimum(int rows, int columns, int myArray[rows][columns]);
void findMaximum(int rows, int columns, int myArray[rows][columns]);
void sumArray(int rows, int columns, int myArray[rows][columns]);
void sumRows(int myArray[], int columns, int rowIndex);
void sumColumns(int rows, int columns, int myArray[rows][columns], int columnIndex);
void transposeMatrix(int rows, int columns, int myArray[rows][columns]);

int main() {
    int rows, columns, again;
    bool isTransposed = false;
    
    // Get the dimensions of the array
    printf("Enter number of row/s:\n>>> ");
    while (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid input! Please enter a positive integer.\n>>> ");
        while (getchar() != '\n'); // Clear input buffer
    }

    printf("Enter number of column/s:\n>>> ");
    while (scanf("%d", &columns) != 1 || columns <= 0) {
        printf("Invalid input! Please enter a positive integer.\n>>> ");
        while (getchar() != '\n'); // Clear input buffer
    }

    int myArray[rows][columns];

    // Input array elements
    printf("Please enter some values in myArray[%d][%d]\n", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int status = 0;
            do {
                printf("myArray[%d][%d]: ", i, j);
                status = scanf("%d", &myArray[i][j]);

                if (status != 1) {
                    printf("Invalid input! Please enter an integer.\n");
                    while (getchar() != '\n'); // Clear input buffer
                }

            } while (status != 1); // Repeat until valid integer is entered
        }
    }
    
    // Display initial array
    printf("Initial Array: ");
    displayArray(rows, columns, myArray);

    // Find minimum and maximum values
    findMinimum(rows, columns, myArray);
    findMaximum(rows, columns, myArray);

    // Sort columns
    for (int j = 0; j < columns; j++) {
        insertionSortByColumns(rows, columns, myArray, j);
    }
    printf("Insertion Sorted by Column: ");
    displayArray(rows, columns, myArray);

    // Sort rows
    for(int i = 0; i < rows; i++) {
        insertionSortByRows(myArray[i], columns);
    }
    printf("Insertion Sorted Array: ");
    displayArray(rows, columns, myArray);

    // Sum calculations
    sumArray(rows, columns, myArray);
    for (int i = 0; i < rows; i++) {
        sumRows(myArray[i], columns, i);
    }
    for (int i = 0; i < columns; i++) {
        sumColumns(rows, columns, myArray, i);
    }

    // Transpose the matrix
    transposeMatrix(rows, columns, myArray);
    isTransposed = true;
    displayArray(columns, rows, myArray);

    // Search for a number
    do {
        findNumber(rows, columns, myArray, isTransposed);
       
        printf("\nWould you like to try again? (Any Number - YES, 0 - NO)\n>>> ");
        while (scanf("%d", &again) != 1) {
            printf("Invalid input! Please enter an integer.\n>>> ");
            while (getchar() != '\n'); // Clear input buffer
        }


    } while (again != 0);

    printf("Thank you for using the program :) :) :)\n");
    return 0;
}

// Function implementations
void findNumber(int rows, int columns, int myArray[rows][columns], bool isTransposed) {
    int numToFind;
    bool found = false;

    printf("\nWhich number would you like to search for?\n>>> ");
   
    while (scanf("%d", &numToFind) != 1) {
        printf("Invalid input! Please enter an integer.\n>>> ");
        while (getchar() != '\n'); // Clear input buffer
    }

    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (myArray[i][j] == numToFind) {
                printf("The value exists at index myArray[%d][%d]\n", isTransposed ? j : i, isTransposed ? i : j);
                found = true;
            }
        }
    }
    if (!found) {
        printf("The value doesn't exist inside the array.\n");
    }
}

void displayArray(int rows, int columns, int myArray[rows][columns]) {    
    printf("\nmyArray[%d][%d] = \n", rows, columns);
    for (int i = 0; i < rows; i++) {
        printf("{");
        for (int j = 0; j < columns; j++) {
            printf("%d", myArray[i][j]);
            if (j < columns - 1) printf(", ");
        }
        printf("}\n");
    }
}

void insertionSortByColumns(int rows, int columns, int myArray[rows][columns], int columnIndex) {
    for (int i = 1; i < rows; i++) {
        int temp = myArray[i][columnIndex];
        int j = i - 1;
        while (j >= 0 && myArray[j][columnIndex] > temp) {
            myArray[j+1][columnIndex] = myArray[j][columnIndex];
            j--;
        }
        myArray[j+1][columnIndex] = temp;
    }
}

void insertionSortByRows(int myArray[], int columns) {
    for (int i = 1; i < columns; i++) {
        int temp = myArray[i];
        int j = i - 1;
        while (j >= 0 && myArray[j] > temp) {
            myArray[j+1] = myArray[j];
            j--;
        }
        myArray[j+1] = temp;
    }
}

void findMinimum(int rows, int columns, int myArray[rows][columns]) {
    int min = myArray[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (myArray[i][j] < min) min = myArray[i][j];
        }
    }
    printf("Minimum value: %d\n", min);
}

void findMaximum(int rows, int columns, int myArray[rows][columns]) {
    int max = myArray[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (myArray[i][j] > max) max = myArray[i][j];
        }
    }
    printf("Maximum value: %d\n", max);
}

void sumArray(int rows, int columns, int myArray[rows][columns]) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sum += myArray[i][j];
        }
    }
    printf("Sum of the Array: %d\n", sum);
}

void sumRows(int myArray[], int columns, int rowIndex) {
    int sum = 0;
    for (int i = 0; i < columns; i++) {
        sum += myArray[i];
    }
    printf("Sum of Row %d: %d\n", rowIndex, sum);
}

void sumColumns(int rows, int columns, int myArray[rows][columns], int columnIndex) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += myArray[i][columnIndex];
    }
    printf("Sum of Column %d: %d\n", columnIndex, sum);
}

void transposeMatrix(int rows, int columns, int myArray[rows][columns]) {
    int transposed[columns][rows];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transposed[j][i] = myArray[i][j];
        }
    }
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            myArray[j][i] = transposed[i][j];
        }
    }
}


int bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for(int j = 0;  j < n - 1; j++ ){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortRows(int rows, int cols, int myArray[rows][cols]) {
    for (int i = 0; i < rows; i++) {  // (1) Loop through each row
        for (int j = 0; j < cols - 1; j++) {  // (2) Standard Bubble Sort passes
            for (int k = 0; k < cols - j - 1; k++) {  // (3) Compare and swap adjacent elements
                if (myArray[i][k] > myArray[i][k + 1]) {  
                    int temp = myArray[i][k];
                    myArray[i][k] = myArray[i][k + 1];
                    myArray[i][k + 1] = temp;
                }
            }
        }
    }
}

void bubbleSortColumns(int rows, int cols, int myArray[rows][cols]) {
    for (int j = 0; j < cols; j++) {  // (1) Loop through each column
        for (int i = 0; i < rows - 1; i++) {  // (2) Standard Bubble Sort passes
            for (int k = 0; k < rows - i - 1; k++) {  // (3) Compare and swap adjacent elements
                if (myArray[k][j] > myArray[k + 1][j]) {  
                    int temp = myArray[k][j];
                    myArray[k][j] = myArray[k + 1][j];
                    myArray[k + 1][j] = temp;
                }
            }
        }
    }
}

for (int i = 0; i < size - 1; i++) {  // Outer loop: selects the position
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {  // Inner loop: finds min element
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
    }
    // Swap the found minimum with the first element of the unsorted part
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
}

for (int i = 0; i < rows; i++) {  // (1) Iterate through each row
    for (int j = 0; j < cols - 1; j++) {  // (2) Select position for min
        int minIndex = j;
        for (int k = j + 1; k < cols; k++) {  // (3) Find min in row
            if (arr[i][k] < arr[i][minIndex]) {
                minIndex = k;
            }
        }
        // Swap the found minimum with the first unsorted element
        int temp = arr[i][j];
        arr[i][j] = arr[i][minIndex];
        arr[i][minIndex] = temp;
    }
}

for (int j = 0; j < cols; j++) {  // (1) Iterate through each column
    for (int i = 0; i < rows - 1; i++) {  // (2) Select position for min
        int minIndex = i;
        for (int k = i + 1; k < rows; k++) {  // (3) Find min in column
            if (arr[k][j] < arr[minIndex][j]) {
                minIndex = k;
            }
        }
        // Swap the found minimum with the first unsorted element
        int temp = arr[i][j];
        arr[i][j] = arr[minIndex][j];
        arr[minIndex][j] = temp;
    }
}
