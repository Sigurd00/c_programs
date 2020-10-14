#include <stdio.h>
#include <stdlib.h>

#define CM_TO_INCH 0.3937

int main(void){
    int cm_smallest,
    cm_largest,
    s,
    l;
    double inch;

    printf("Give me the smallest and the largest CM:\n");
    scanf(" %d %d", &s, &l);
    //Sørger for at det mindste tal faktisk er det mindste 
    cm_largest = l <= s ? s : l;
    cm_smallest = l <= s ? l  : s;
    for(int i = cm_smallest; i <= cm_largest; i += 10){
        inch = i * CM_TO_INCH;
        printf("CM: %3d INCH: %3.3lf\n", i, inch);
    }
}