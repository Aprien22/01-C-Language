#include <stdio.h>
#define ROWS 2
#define COLS 2

int main() {
    int arr[ROWS][COLS], sum = 0;
    int* pArr;

    printf("Enter values for arr[2][2] using a Pointer\n");
    for (pArr = &arr[0][0]; pArr <= &arr[ROWS - 1][COLS - 1]; pArr++) {
        printf("Enter value: ");
        scanf("%d", pArr);
    }

    printf("\nPRINT BY POINTER\n");
    for (pArr = &arr[0][0]; pArr <= &arr[ROWS - 1][COLS - 1]; pArr++) {
        printf("Address: %x | Value: %d\n", pArr, *pArr);
    }

    printf("\nPRINT EVEN NUMBERS\n");
    for (pArr = &arr[0][0]; pArr <= &arr[ROWS - 1][COLS - 1]; pArr++) {
        if (*pArr % 2 == 0)
            printf("Address: %x | Value: %d\n", pArr, *pArr);
    }

    printf("\nPRINT ODD NUMBERS\n");
    for (pArr = &arr[0][0]; pArr <= &arr[ROWS - 1][COLS - 1]; pArr++) {
        if (*pArr % 2 == 1)
            printf("Address: %x | Value: %d\n", pArr, *pArr);
    }

    printf("\nPRINT SUM\n");
    for (pArr = &arr[0][0]; pArr <= &arr[ROWS - 1][COLS - 1]; pArr++) {
        sum += *pArr;
    }
    printf("The SUM of all numbers is: %d\n", sum);
    return 0;
}
