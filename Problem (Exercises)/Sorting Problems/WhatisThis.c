#include <stdio.h>
int selectionSort(int arr[], int n){
    printf("\n================================");
    for (int i = 0; i < n - 1; i++){
        int min_idx = i;
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
    printf("\nSELECTION SORT:\n");
    for (int i = 0; i < n; i++)
       printf("myArray[%d] = %d \n", i, arr[i]);
}

int bubbleSort(int arr[], int n){
    printf("\n================================");
    for (int i = 0; i < n - 1; i++){
        for(int j = 0;  j < n - 1; j++ ){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nBUBBLE SORT:\n");
    for (int i = 0; i < n; i++)
        printf("myArray[%d] = %d \n", i, arr[i]);
}

int insertionSort(int arr[], int n){
    for (int i = 0; i < n; i++){
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    printf("\nBUBBLE SORT:\n");
    for (int i = 0; i < n; i++)
        printf("myArray[%d] = %d \n", i, arr[i]);

}
int main(){
    
    int a = 2048;
    int sum = 0;
    int size;
    int myArray[size];
    
    printf("Size of Array: ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &myArray[i]);
    }

    selectionSort(myArray, size);
    bubbleSort(myArray, size);
    bubbleSort(myArray, size);

}
