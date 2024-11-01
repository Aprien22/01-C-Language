#include <stdio.h>
#include <string.h>

int factorial(int count);

int main()
{
    int count = 22;

    printf("%d", factorial(count));
}

int factorial(int n){
    if (n == 0)
    {
        return 1;
    }
    return n * (factorial(n-1));
}