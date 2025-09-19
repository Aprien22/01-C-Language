#include <stdio.h>

void printStarPyramid(int totalRows, int currentRow) {
    if (currentRow > totalRows)
        return;
    
    for (int i = 0; i < totalRows - currentRow; i++) {
        printf(" ");
    }
    for (int j =  0; j < (2 * currentRow - 1); j++) {
        printf("*");
    }
    printf("\n");
    printStarPyramid(totalRows, currentRow + 1);
}

int main() {
    int rows;
    printf("Hello!\nPlease enter # of rows for your \"Star Pyramid\": ");
    scanf("%d", &rows);

    printStarPyramid(rows, 1);

    return 0;
}
