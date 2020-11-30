#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_palindrome_iter(char *str);
int is_palindrome_rec(char *str);
int is_palindrome_rec_h(char *str, int start, int end);

int main(void){
    printf("regninger is palindrome TRUE [1] FALSE [0] %d:%d\n",
        is_palindrome_iter("regninger"), is_palindrome_rec("regninger"));

    return EXIT_SUCCESS;
}

/* checks if string is palindrome, iterative, returns bool */
int is_palindrome_iter(char *str){
    int start = 0, end = strlen(str) - 1, truth = 0;
    while(start <= end){
        if(str[start] == str[end])
            truth = 1;
        else truth = 0;
        start++; end--;
    }
    return truth;
}

/* makes start values for recursive helper function */
int is_palindrome_rec(char *str){
    int start = 0, end = strlen(str) - 1;
    return is_palindrome_rec_h(str, start, end);
}

/* Helper function, recursively checks if string is palindrome */
int is_palindrome_rec_h(char *str, int start, int end){
    if(str[start] != str[end])
        return 0;
    else if(start > end)
        return 1;        
    else
        return is_palindrome_rec_h(str, start + 1, end -1);
}