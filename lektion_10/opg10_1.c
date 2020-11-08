#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *stringcopy(char *);

int main(void){
    char string[100];
    int *reversed;
    printf("Type in a string you want to reverse\n");
    scanf(" %s", string);
    reversed = stringcopy(string);

    printf("The reversed string is: \n %s", reversed);

    free(reversed);

    return EXIT_SUCCESS;
}

/*Not working*/
int *stringcopy(char *string){
    char * reversedStr = (char *) malloc(strlen(string) * sizeof(char));
    int i, j;
    for(i = 0, j = strlen(string); i < strlen(string); i++, j--){
        reversedStr[i] = string[j];
    }
    return reversedStr;
}

