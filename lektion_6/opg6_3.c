#include <stdio.h>
#include <stdlib.h>

#define HUNDRED_DOLLAR_BIL 100
#define FIFTY_DOLLAR_BIL 50
#define TWENTY_DOLLAR_BIL 20
#define TEN_DOLLAR_BIL 10
#define SENTINAL 0

void money_printer();
void money_printer_calculator();

int main(void){
    int dollar;
    do
    {
        printf("Enter an amount of dollars you want the machine to print (has to be divisibel by 10)\n");
        scanf(" %d", &dollar);
        if(dollar != SENTINAL){
            if (dollar % 10 == 0)
                money_printer(dollar);
            else 
                printf("Dollars has to be divisibel by 10, please try again\n\n");
        }
    } while (dollar != SENTINAL);
}

void money_printer(int dollar){
    int hundreds, fiftys, twenties, tens;
    money_printer_calculator(dollar, &hundreds, &fiftys, &twenties, &tens);

    printf("%d Dollars will be printed as: %d Hundreds, %d Fiftys, %d Twenties and %d tens\n", dollar, hundreds, fiftys, twenties, tens);
}

void money_printer_calculator(int dollar, int *hundreds, int *fiftys, int *twenties, int *tens){
    
    *hundreds = dollar / HUNDRED_DOLLAR_BIL;
    dollar = dollar % HUNDRED_DOLLAR_BIL;

    *fiftys = dollar / FIFTY_DOLLAR_BIL;
    dollar = dollar % FIFTY_DOLLAR_BIL;

    *twenties = dollar / TWENTY_DOLLAR_BIL;
    dollar = dollar % TWENTY_DOLLAR_BIL;

    *tens = dollar / TEN_DOLLAR_BIL;
}