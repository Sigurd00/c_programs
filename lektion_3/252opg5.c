#include <stdio.h>
#include <stdlib.h>

int main(void){

    float n;

    printf("How much data does the user use?\n");
    scanf(" %f", &n);
    
    if ( 0.0 < n && n <= 1.0)
        printf("The company charges 250\n");
    else if(1.0 < n && n <= 2.0)
        printf("The company charges 500\n");
    else if(2.0 < n && n < 5.0)
        printf("The company charges 1000\n");
    else if(5.0 < n && n < 10.0)
        printf("The company charges 1500\n");
    else if(n > 10.0)
        printf("The company charges 2000\n");
    else{
        printf("Invalid input0\n");
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}