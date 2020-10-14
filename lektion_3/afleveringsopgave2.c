#include <stdio.h>
#include <stdlib.h>

//Vores kontante symboler til nemmere forståelse af kode
#define SEC_PER_MIN 60
#define SEC_PER_HOUR 3600

int main(void){

    //Initaliser variable
    int hours,
    minutes,
    seconds;    

    //Prompter brugeren for antal sekunder, og gemmer det i seconds
    printf("Enter the amount of seconds you want to convert:\n");
    scanf(" %d", &seconds);

    //Beregner antal timer og finder resten
    hours = seconds / SEC_PER_HOUR;
    seconds = seconds % SEC_PER_HOUR;

    //Beregner antal minuter og finder resten
    minutes = seconds / SEC_PER_MIN;
    seconds = seconds % SEC_PER_MIN;

    /*
        Det her var den bedste måde jeg lige kunne kommer i tank om,
        når man skal tage højde for IKKE at skrive fx "0 minutes"
        da det ændre strukturen i hele sætningen.
    */
    //Når både timer, minutter og sekunder skal bruges
    if(hours > 0 && minutes > 0 && seconds > 0){
        printf((hours > 1) ? "%d Hours," : "%d Hour,", hours); //Vi ser også lige efter, om der skal bruges flertal.
        printf((minutes > 1) ? " %d Minutes" : " %d Minut", minutes); 
        printf((seconds > 1) ? " and %d Seconds\n" : " and %d Second\n", seconds);
    }
    //Kun timer og minutter
    else if(hours > 0 && minutes > 0){
        printf((hours > 1) ? "%d Hours" : "%d Hour", hours);
        printf((minutes > 1) ? " and %d Minutes\n" : " and %d Minut\n", minutes);
    }
    //Kun timer og sekunder
    else if (hours > 0 && seconds > 0){
        printf((hours > 1) ? "%d Hours" : "%d Hour", hours);
        printf((seconds > 1) ? " and %d Seconds\n" : " and %d Second\n", seconds);
    }
    //Kun minutter og sekunder
    else if (minutes > 0 && seconds > 0) {
        printf((minutes > 1) ? " %d Minutes" : " %d Minut", minutes);
        printf((seconds > 1) ? " and %d Seconds\n" : " and %d Second\n", seconds);
    }
    //Kun timer
    else if(hours > 0)
        printf((hours > 1) ? "%d Hours\n" : "%d Hour\n", hours);
    //Kun minutter
    else if(minutes > 0)
        printf((minutes > 1) ? "%d Minutes\n" : "%d Minut\n", minutes);
    //Kun sekunder
    else if(seconds > 0)
        printf((seconds > 1) ? "%d Seconds\n" : "%d Second\n", seconds);
    else {
        printf("Invalid input, please make sure that you enter a positive integer\n");
        return(EXIT_FAILURE);
    }
        
    return(EXIT_SUCCESS);
}