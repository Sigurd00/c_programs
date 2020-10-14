#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    printf("Give me the number of the pyramid");
    scanf(" %d", &n);

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            printf(" %d", j);      
        }
        printf("\n");
    }
    for(int i = n -1; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            printf(" %d", j);      
        }
        printf("\n");
    }
    return(EXIT_SUCCESS);
}