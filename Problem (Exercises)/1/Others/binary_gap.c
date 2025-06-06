#include <stdio.h>

int solution(int N);

int main() {
    int num;
    printf("What's your number? ");
    scanf("%d", &num);

    printf("The longest gap of %d is %d\n", num, solution(num));
}

int solution(int N) {
    int currentGap = 0;
    int maxGap = 0;
    int foundOne = 0;

    while (N > 0) {
        if (N % 2 == 1) {
            if (foundOne && currentGap > maxGap) {
                maxGap = currentGap;
            }
            currentGap = 0;
            foundOne = 1;
        } else {
            if (foundOne) {
                currentGap++;
            }
        }
        N /= 2;
    }

    return maxGap;
}
