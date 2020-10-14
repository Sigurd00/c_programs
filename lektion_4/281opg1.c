#include <stdio.h>
#include <stdlib.h>

int main(void){
    int population = 9870,
    countYears = 0;
    while (population <= 30000){
        population *= 1.1;
        countYears += 1;
    }

    printf("It takes %d years to reach a population of 30000\n", countYears);   
    return(EXIT_SUCCESS);
}