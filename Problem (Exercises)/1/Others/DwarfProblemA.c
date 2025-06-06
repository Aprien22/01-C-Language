#include <stdio.h>

void findFactors(int num);
void sumFactors(int num, int* sum);
void numberHalf(int num, int* sum, float* half);
int isItDwarf(int* sum, float* half);


int main(){
    int arr[5] = {5, 3, 4, 1, 2}, *p = arr;
    printf("\nDwarf Problem (Array Version)\n");

    printf("\narr[5] = {");
    for (int i = 0; i < 5; i++) {
        printf("%d", arr[i]);
        if (i < 5 - 1) printf(",\t");
    }  
    printf("}\n\n");

    for(int i = 0; i < 5; i++) {
        int sum, *pSum = &sum;
        float half, *pHalf = &half;

        printf("Input Number: %d\n", arr[i]);

        findFactors(arr[i]);
        printf("\n");

        sumFactors(arr[i], pSum);

        numberHalf(arr[i], pSum, pHalf);

        if (isItDwarf(pSum, pHalf)) 
            printf("%d is a DWARF", arr[i]);
        else 
            printf("%d is not a DWARF", arr[i]);

        printf("\n\n");

    }
}

void findFactors(int num) {
    printf("Factors are: ");

    if (num == 1){
        printf("%d", num);
    }
    else {
        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                printf("%d", i);
                if (i < num) 
                    printf(", ");
            }
        }
    }
}

void sumFactors(int num, int* sum) {
    *sum = 0;
    printf("Sum of the Factors: ");

    if (num == 1) {
        printf("%d", num);
        *sum = num;
    }
    else {
        for (int j = 1; j < num; j++) {
            if (num % j == 0) {
                if (j < num && j != 1) 
                    printf(" + ");
                printf("%d", j);
                *sum += j;
            }
        }
    }
    printf(" = %d", *sum);
}

void numberHalf(int num, int* sum, float* half) { 
    *half = (float) num / 2;

    printf("\nHalf of the number: %d / 2 = %.2f\n", num, *half);
}

int isItDwarf(int* sum, float* half) { 
    if (*sum >= *half) 
        return 1;
    else 
        return 0;
}
