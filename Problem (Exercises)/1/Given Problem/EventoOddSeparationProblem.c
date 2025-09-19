#include <stdio.h>
#include "C:\Users\PC\Programming\Odd-Even.c"

int main(){

    int arr_size;
    char name[80];
    
    printf("\nHello and welcome to ODD and EVEN Program!\n");
    printf("Can you please tell your name: ");
    scanf("%s", name);


    printf("\nHello %s!\nPlease input the number of elements to be stored in the array (size): ", name);
    scanf("%d", &arr_size);


    int mainArray[arr_size];
    int oddArray[arr_size];
    int evenArray[arr_size];

    printf("\nInput %d elements in the array: \n", arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        printf("Element - %d : ", i);
        scanf("%d", &mainArray[i]);
    }

    int evenCount = evenCollect(mainArray, evenArray, arr_size);
    int oddCount = oddCollect(mainArray, oddArray, arr_size);

    if (evenCount == 0)
        printf("\nThere are no EVEN values in the Array\n");
    else
    {
        printf("\nThe Even elements are: \n");
        for (int i = 0; i < evenCount; i++)
            printf("%d ", evenArray[i]);
    
    }
    
    printf("\n");
    if (oddCount == 0)
        printf("\nThere are no ODD values in the Array\n");
    else
    {

        printf("\nThe Odd elements are: \n");
        for (int i = 0; i < oddCount; i++)
            printf("%d ", oddArray[i]);
    }
    printf("\n\n");

    
    return 0;
    
}