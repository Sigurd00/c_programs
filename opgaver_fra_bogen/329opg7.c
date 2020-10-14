#include <stdio.h>
#include <stdlib.h>

#define HIGH_SPEED 90
#define SLOW_SPEED 50

/*
    Dette program tager en samling af fart fra biler og 
    sortere dem efter høj fart, normal fart, og langsom
    Den finder også gennemsnittet af bilernes fart
*/

int main(void){
    
    int speed[] = {43, 23, 54, 57, 68, 67, 51, 90, 33, 22, 11, 88, 34, 52, 75, 12, 78, 32, 89, 14, 65, 67, 97, 53, 10, 47, 34};
    const int size = sizeof speed / sizeof *speed;
    int high_speed[size],
    slow_speed[size],
    medium_speed[size];
    int j = 0,
    k = 0,
    l = 0,
    combined_speed = 0,
    average_speed;

    for(int i = 0; i < size; i++){
        if(speed[i] >= HIGH_SPEED){
            high_speed[j] = speed[i];
            j++;
        }
        else if(speed[i] <= SLOW_SPEED){
            slow_speed[k] = speed[i];
            k++;
        }
        else{
            medium_speed[l] = speed[i];
            l++;
        }
        combined_speed += speed[i];
    }
    average_speed = combined_speed / size;

    printf("High Speed: ");
    for(int i = 0; i < j; i++){
        printf("%d ", high_speed[i]);
    }
    printf("\n");

    printf("Medium Speed: ");
    for(int i = 0; i < k; i++){
        printf("%d ", medium_speed[i]);
    }
    printf("\n");

    printf("Slow Speed: ");
    for(int i = 0; i < l; i++){
        printf("%d ", slow_speed[i]);
    }
    printf("\nAverage speed: %d\n", average_speed);
}