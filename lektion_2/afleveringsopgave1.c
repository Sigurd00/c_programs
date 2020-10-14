#include <stdio.h>

//Vores kontante symboler til nemmere forståelse af kode
#define SEC_PER_MIN 60
#define SEC_PER_HOUR 3600
#define SEC_PER_DAY 86400
#define SEC_PER_WEEK 604800

int main(void){

    //Initaliser variable
    int weeks,
    days,
    hours,
    minutes,
    seconds;

    //Prompter brugeren for antal sekunder, og gemmer det i seconds
    printf("Enter the amount of seconds you want to convert:\n");
    scanf(" %d", &seconds);

    //Beregner antal uger og finder resten
    weeks = seconds / SEC_PER_WEEK; 
    seconds = seconds % SEC_PER_WEEK;

    //Beregner antal dage og finder resten
    days = seconds / SEC_PER_DAY;
    seconds = seconds % SEC_PER_DAY;

    //Beregner antal timer og finder resten
    hours = seconds / SEC_PER_HOUR;
    seconds = seconds % SEC_PER_HOUR;

    //Beregner antal minuter og finder resten
    minutes =  seconds / SEC_PER_MIN;
    seconds =   seconds % SEC_PER_MIN;
    
    //Spytter formateret resultat ud
    printf("%d Weeks, %d Days, %d Hours, %d Minutes and %d Seconds\n", weeks, days, hours, minutes, seconds);

    return 0;
}