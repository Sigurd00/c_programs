#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (void){
    char noun[100];
    int i;
    printf("Give me a noun\n");
    scanf(" %s", noun);
    i = strlen(noun) - 1;
    if(noun[i] == 'y')
        strcpy(noun + i, "ies");
    else if(noun[i] == 's')
        strcpy(noun + i + 1, "es");
    else if(noun[i - 1] == 'c' && noun[i] == 'h')
        strcpy(noun + i + 1, "es");
    else
        strcpy(noun + i + 1, "s");
    printf("%s", noun);
    
    return EXIT_SUCCESS;
}