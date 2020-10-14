#include <stdio.h>
#include <stdlib.h>

int main(void){

    int watts, 
    lumens;
    printf("How many watts does the light bulb use?\n");
    scanf(" %d", &watts);

/* // Opgave 1, lav det med en switch
    switch (watts){
    case 15: lumens = 125; break;
    case 25: lumens = 215; break;
    case 40: lumens = 500; break;
    case 60: lumens = 880; break;
    case 75: lumens = 1000; break;
    case 100: lumens = 1675; break;
    
    default: printf("This light bulb doesnt exist\n"); exit(EXIT_FAILURE); break;
    }
*/

   //opgave 2, lav det med if statements
   if (watts == 15)
       lumens = 125;
    else if (watts == 25)
        lumens = 215;
    else if (watts == 40)
        lumens = 500;
    else if (watts == 60)
        lumens = 880;
    else if (watts == 75)
        lumens = 1000;
    else if (watts == 100)
        lumens = 1675;
    else {
        printf("This light bulb doesnt exist\n");
        exit(EXIT_FAILURE);
    }
        
    printf("Your light bulb has a brightness of %d lumens\n", lumens);

    return (EXIT_SUCCESS);
}