#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *common_ending(const char *, const char *);
char *stringrev(const char *);

int main(void){
    char word1[50];
    char word2[50];
    char *commonEnding;
    printf("Give me two words to compare:");
    scanf(" %s %s", word1, word2);
    commonEnding = common_ending(word1, word2);
    printf("The greatest common ending of the two words is:\n%s",commonEnding);

    free(commonEnding);    
    return EXIT_SUCCESS;
}

char *common_ending(const char * word1, const char * word2){
    char *commonEnding = (char *) malloc(strlen(word1) * sizeof(char)); /*Det kan maksimalt være lige så stort som det mindste ord*/
    char *word1_reversed;
    char *word2_reversed;
    int i, j = 0;

    word1_reversed = stringrev(word1);
    word2_reversed = stringrev(word2);

    for(i = 0; i < strlen(word1); i++){
        if(word1_reversed[i] == word2_reversed[i]){
        commonEnding[i] = word1_reversed[i];
        j++;
        }
    }
    commonEnding[j] = '\0';
    commonEnding = stringrev(commonEnding);
    free(word1_reversed); free(word2_reversed);
    return commonEnding;
}

char *stringrev(const char *string){
    char *reversedStr = (char *) malloc(strlen(string) * sizeof(char));
    int i, j;
    for(i = 0, j = strlen(string) -1; i < strlen(string); i++, j--){
        reversedStr[i] = string[j];
    }
    reversedStr[i] = '\0';
    return reversedStr;
}

