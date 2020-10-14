#include <stdio.h>
#include <stdlib.h>

int main(void){
    int m,
    n,
    k,
    smallest,
    largest,
    sum = 0;

    printf("Give me the largest and smalles number and give me the konstant");
    scanf(" %d %d %d", &largest, &smallest, &k);
    
    m = largest <= smallest ? smallest : largest;
    n = largest <= smallest ? largest  : smallest;

    for(int i = n; i <= m; i++){
        if( i % k == 0){
            sum += i;
            printf("%d is divisible by %d\n", i, k);
        }
    }
    printf("Sum = %d\n", sum);
    return(EXIT_SUCCESS);
}