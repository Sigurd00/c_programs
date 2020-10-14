#include <stdio.h>
#include <stdlib.h>


int main(void){
    int n, sum = 0;
    printf("Enter a positive integer n:\n");
    scanf(" %d", &n);

    for(int i = 0; i <= n; i++){
        sum += i;
        printf("i = %3d, sum = %d\n", i, sum);
        if(sum == (n * (n + 1)) / 2)
            printf("The value is the same for n = %d and sum = %d \n", n, sum); /* Det betyder at i stedet for at bruge en løkke til at summere det hele, kan man bare bruge formlen til at finde summen. */
    }
    return(EXIT_SUCCESS);
}