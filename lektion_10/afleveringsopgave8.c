#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void process_product_code(char *, char *, char *, char *);

int main(void){
    char productCode[] = "ATL1203S14";            /*Input*/
    char warehouse[4], product[5], qualifiers[4]; /*Output*/

    printf("Product code is : %s\n", productCode);
    process_product_code(productCode, warehouse, product, qualifiers);
    printf("Warehouse: %s\nProduct: %s\nQualifiers: %s\n", warehouse, product, qualifiers);
    return EXIT_SUCCESS;
}


void process_product_code(char *productCode, char *warehouse, char *product, char *qualifiers){
    int i = 0, firstDigitPosition, alphaAfterDigitPosition = 0, checkForAlpha = 0;
    while(alphaAfterDigitPosition == 0){
        if(checkForAlpha == 0 && isdigit(productCode[i])){
            firstDigitPosition = i;
            checkForAlpha = 1;
        }
        if(checkForAlpha == 1 && isalpha(productCode[i])){
            alphaAfterDigitPosition = i;
        }
        i++;
    }
    strncpy(warehouse, productCode, firstDigitPosition);
    strncpy(product, productCode + firstDigitPosition, alphaAfterDigitPosition - firstDigitPosition); /*TODO: This is not working correctly*/
    strncpy(qualifiers, productCode + alphaAfterDigitPosition, strlen(productCode) - alphaAfterDigitPosition);
}