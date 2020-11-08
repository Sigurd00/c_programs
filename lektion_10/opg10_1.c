#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *stringrev(char *);

int main(void){
    char string[100];
    char *reversed;
    printf("Type in a string you want to reverse\n");
    scanf(" %s", string);
    reversed = stringrev(string);

    printf("The reversed string is:\n%s\n", reversed);

    free(reversed);

    return EXIT_SUCCESS;
}

/*Not working*/
char *stringrev(char *string){
    char *reversedStr = (char *) malloc(strlen(string) * sizeof(char));
    int i, j;
    for(i = 0, j = strlen(string) -1; i < strlen(string); i++, j--){
        reversedStr[i] = string[j];
    }
    reversedStr[i] = '\0';
    return reversedStr;
}

