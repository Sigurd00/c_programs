#include <stdio.h>
#include <stdlib.h>

#define DOLLAR_TO_EURO 0.89
#define DOLLAR_TO_DKK 6.66
#define DOLLAR_TO_RUBIN 66.43
#define DOLLAR_TO_YEN 119.9

void convert_valuta();
void valuta_table();

int main(void){
    int dollars;

    printf("What is the max amount of dollars you want to show on the table?\n");
    scanf(" %d", &dollars);
    
    valuta_table(dollars);

    return EXIT_SUCCESS

}

void valuta_table(int max_dollar){
    double euro, dkk, rubin, yen;
    for(int i = 1; i <= max_dollar; i++){
        convert_valuta(i, &euro, &dkk, &rubin, &yen);
        printf("%3.d Dollars converts to:%5.2lf EURO, %5.2lf DKK, %5.2lf RUBIN, %5.2lf YEN\n", i, euro, dkk, rubin, yen);
    }
}

void convert_valuta(int dollars, double *euro, double *dkk, double *rubin, double *yen){
    *euro = dollars * DOLLAR_TO_EURO;
    *dkk = dollars * DOLLAR_TO_DKK;
    *rubin = dollars * DOLLAR_TO_RUBIN;
    *yen = dollars * DOLLAR_TO_YEN;
}