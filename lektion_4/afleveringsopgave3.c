#include <stdio.h>
#include <stdlib.h>

int main(void){
    int smallest, largest, a, b, GCD;

    /* Vi vil sikre os at koden bliver kørt mindst én gang */
    do {
        printf("Please give two non-negative integers:\n");
        scanf(" %d %d", &smallest, &largest);

        /* Sørger for at b altid vil være det laveste tal */
        a = largest <= smallest ? smallest : largest;
        b = largest <= smallest ? largest  : smallest;
        
        /*
            Hvis vi har et negativt tal er det fordi vi ønsker at lukke programmet
            Hvis vi ønsker at lukke programmet, ønsker vi ikke at finde GCD 
        */
        GCD = 0;
        if(a > 0 && b > 0){
            /*
                Vi tester fra det laveste tal, 
                så snart vi finder et tal hvor begge tal har 0 til rest, har vi fundet GCD
            */
            for(int i = b; i >= GCD; i--){
                if(a % i == 0 && b % i == 0)
                    GCD = i;
            }
            printf("GCD of %d and %d is %d\n\n", a, b, GCD);
        }
    } while(a >= 0 && b >= 0); // Skal vi køre igen?
    
    return(EXIT_SUCCESS);  
}