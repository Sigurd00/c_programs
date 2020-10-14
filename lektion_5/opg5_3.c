#include <stdio.h>
#include <stdlib.h>
#include "primes.h"

int goldbach_is_true(int);

int main(void){
    int n;
    printf("Give me the highest number you want to check:\n");
    scanf(" %d", &n);

    for(int i = 8; i <= n; i += 2){
        if(goldbach_is_true(i)){
            printf("It is true at %3.d\n", i);
        }
    }
}

int goldbach_is_true(int n) {
    for(int i = 1; i <= n; i+= 2){
        if(is_prime(i) && is_prime(n-i)){
            printf("%3.d + %3.d = %3.d Therefore ", i, n-i, n);
            return(1);
        }
    }
    printf("wtf");
    return(0);
}