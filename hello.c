#include <stdio.h>
#include <string.h>

int add(int a, int b);

int main() {
    printf("Hello, World!\n");

    char name[50];
    int x, y;
    
    printf("What's your name? ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Hello, %s!\n", name);


    printf("First Number: ");
    scanf("%d", &x);
    printf("Second Number: ");
    scanf("%d", &y);

    printf("The sum of %d and %d is %d\n", x, y, add(x, y));

    return 0;
}


int add(int a, int b)
{
    return a + b;
}