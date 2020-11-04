#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TABLE_SIZE 100
int el_cmp();

int main(void){
    double *dbl = (double *) malloc(TABLE_SIZE * sizeof(double));
    int i;
    srand(time(NULL));

    for(i = 0; i < TABLE_SIZE; i++){
        dbl[i] = rand();
    }   
    printf("The unsorted numbers are:\n");
    for(i = 0; i < TABLE_SIZE; i++){
        printf("Number %3d: %3lf\n", i+1, dbl[i]);
    }
    qsort(dbl, TABLE_SIZE, sizeof(double), el_cmp);
    printf("\n\n The sorted list: \n");
    for(i = 0; i < TABLE_SIZE; i++){
        printf("Number %3d: %3lf\n", i+1, dbl[i]);
    }
    free(dbl);
    return EXIT_SUCCESS;
}

int el_cmp(const void *ep1, const void *ep2){
    double *tp1 = (double*) ep1,
           *tp2 = (double*) ep2;
    if(*tp1 < *tp2){
        return -1;
    }
    else if (*tp1 > *tp2){
        return 1;
    }
    else 
        return 0;
}