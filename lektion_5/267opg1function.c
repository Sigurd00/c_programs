#include <stdio.h>
#include <stdlib.h>

int sum_iter(int);
int sum_formula(int);

int main(void){
    int n;
    printf("Enter a positive integer n:\n");
    scanf(" %d", &n);
    if(sum_iter(n) == sum_formula(n)){
        printf("The sum for %d is calculated with sum_iter as %d and with sum_formula as %d", n, sum_iter(n), sum_formula(n));
    }
}

/*functions */
int sum_iter(int n){
    int sum = 0;
    for(int i = 0; i <= n; i++){
        sum += i;
    }
    return sum;
}

int sum_formula(int n){
    int sum = (n * (n + 1)) / 2;
    return sum;
}