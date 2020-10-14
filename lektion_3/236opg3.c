#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ph;
    printf("What is the PH value?\n");
    scanf(" %d", &ph);

    if ( ph > 7){
        if(ph < 12)
            printf("Alkaline\n");
        else
            printf("Very alkaline\n");
    }
    else if (ph == 7)
        printf("Neutral\n");
    else if (ph > 2)
        printf("Acidic\n");
    else
        printf("Very acidic\n");
    
    return EXIT_SUCCESS;
}
