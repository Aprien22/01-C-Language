#include <stdio.h>

int main(){

    char name[80];
    int hours_worked;
    float hourly_rate = 281.00;
    float gross_pay, withholding_tax, net_pay;
    
    printf("Hello, can you please enter your name? \n");
    scanf("%s", name);

    printf("Hello, %s. How many hours have you worked for? \n", name);
    scanf("%d", &hours_worked);

    gross_pay = hourly_rate * hours_worked;
    withholding_tax = gross_pay * 0.32;
    net_pay = gross_pay - withholding_tax;

    printf("Hello, %s. Here are the results:\nHourly Rate\t: %.2f\nHours Worked\t: %d\nGross Pay\t: %.2f\nWithholding Tax\t: %.2f\nNet Pay\t: %.2f", name, hourly_rate, hours_worked, gross_pay, withholding_tax, net_pay);
}