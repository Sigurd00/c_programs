#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int *roll_multiple_dies();

int main(void){
    int i, k, n;
    int *dice_rolls;
    srand(time(NULL));
    printf("How many dies do you want to roll? ");
    scanf(" %d", &n);
    for(i = 1; i <= 10; i++){
        printf("Rolls %3d: ", i);
        dice_rolls = roll_multiple_dies(n);
        for(k = 0; k < n; k++)
            printf("%3d ", dice_rolls[k]);
        printf("\n");
    }
    free(dice_rolls);
    return EXIT_SUCCESS;
}

int *roll_multiple_dies(int n){    
    int *dice_rolls = (int *) malloc(n * sizeof(int));
    int i;
    for(i = 0; i < n; i++){
        dice_rolls[i] = rand() % 6 + 1;
    }
    return dice_rolls;
}