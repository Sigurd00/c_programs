#include <stdio.h>  

int main(void){
    //Initialiser variabler
    int m,
    n,
    side1,
    side2,
    hypotenuse;

    //Prommpt for to værdier
    printf("Give me the length of two sides, the first number should be larger than the 2nd: \n");
    scanf(" %d %d", &m, &n);
    
    //Beregning af siderne med 
    side1 = m * m - n * n;
    side2 = 2 * m * n;
    hypotenuse = m * m + n* n;

    //Vis resultatet af beregningen
    printf("Side 1 is = %d\nSide 2 is = %d\nThe hypotenuse is = %d\n", side1, side2, hypotenuse);

    return 0;   
}