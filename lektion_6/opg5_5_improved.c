#include <stdio.h>
#include <stdlib.h>

int isLeapYear();
int my_isLeapYear();

int main(void){
    int year, res;

    printf("What year would you like to check? \n");
    scanf(" %d", &year);
    if(my_isLeapYear(year, &res))
        printf("Result 1: Year %d is a Leap Year  :   ", year);
    else
        printf("Result 1: Year %d is not a Leap Year  :   ", year);
    if(isLeapYear(year, &res))
        printf("Result 2: Year %d is a Leap Year\n", year);
    else
        printf("Result 2: Year %d is not a Leap Year\n", year);
    return(EXIT_SUCCESS);
}
/*Min*/
int my_isLeapYear(int year, int *res){
    if(year % 400 == 0 || year % 4 == 0)
        *res = 1;
    else 
        *res = 0;
}
/*Kurts */
int isLeapYear(int year, int *res){
  if (year % 400 == 0)
    *res = 1;
  else if (year % 100 == 0)
    *res = 0;
  else if (year % 4 == 0)
    *res = 1;
  else *res = 0;
}