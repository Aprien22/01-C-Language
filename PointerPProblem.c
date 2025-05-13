#include <stdio.h>

void read_and_print() {
    int n;
    scanf("%d", &n);
    if (n != 0) {
        read_and_print();  // recursive call
        printf("%d\t", n); // print on unwinding
    }
}

int main() {
    printf("Enter values (0 to stop):\n");
    read_and_print();
    return 0;
}