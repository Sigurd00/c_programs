#include <stdlib.h>
#include <stdio.h>


int main(void){
    int i, sum = 0, checkDigit;
    int barcode[12];
    printf("Enter a 12 digit barcode seperated by spaces: ");
    for(i = 0; i < 12; i++){
        scanf(" %d", &barcode[i]);
    }
    printf("This is the barcode you wrote: ");
    for(i = 0; i < 12; i++){
        printf("%d ", barcode[i]);
    }

    for(i = 0; i < 11; i += 2){
        sum += 3 * barcode[i];
    }
   
    for(i = 1; i < 10; i += 2){
        sum += barcode[i];
    }
    if(sum % 10 == 0){
        checkDigit = 0;
    }
    else {
        checkDigit = 10 - sum % 10;
    }
    if(checkDigit == barcode[11])
        printf("\nBarcode is validated");
    else
        printf("\nError in barcode");
    return EXIT_SUCCESS;
}