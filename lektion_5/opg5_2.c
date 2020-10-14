#include <stdio.h>
#include <stdlib.h>
#include "primes.h"

int main(void){
    int n, cnt_prime = 0, i = 2;

    printf("How many primes do you want to find?\n");
    scanf("%d", &n);
    while (cnt_prime < n){
        if(is_prime(i)){
            cnt_prime += 1;
            printf("Prime %3.d: %3.d\n", cnt_prime, i);
        }
    i++;
    }
    return(EXIT_SUCCESS);
}