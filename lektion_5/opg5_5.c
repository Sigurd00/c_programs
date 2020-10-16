#include <stdio.h>
#include <stdlib.h>

int isLeapYear();
int my_isLeapYear();

int main(void){
    int year;

    printf("What year would you like to check? \n");
    scanf(" %d", &year);

    printf("My result: %3.d, Kurts result: %3.d", my_isLeapYear(year), isLeapYear(year));
/* giver sku ikke noget resultat :/ */
    return(EXIT_SUCCESS);
}
/*Min*/
int my_isLeapYear(int year){
    int res;
    if(year % 400 == 0 || year % 4 == 0)
        res = 1;
    else 
        res = 0;
    return res;
}
/*Kurts */
int isLeapYear(int year){
  int res;
  if (year % 400 == 0)
    res = 1;
  else if (year % 100 == 0)
    res = 0;
  else if (year % 4 == 0)
    res = 1;
  else res = 0;
  return res;
}