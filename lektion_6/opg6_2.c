#include <stdio.h>

void hours_minutes_seconds();
void hours_minutes_seconds_formatting();

//Vores kontante symboler til nemmere forståelse af kode
#define SEC_PER_MIN 60
#define SEC_PER_HOUR 3600

int main(void){
    int seconds, minutes, hours;
    
    printf("Give me the number of seconds you want to calculate\n");
    scanf(" %d", &seconds);
    
    hours_minutes_seconds(&seconds, &minutes, &hours);
    printf("Hours %d, Minutes %d, Seconds %d", seconds, minutes, hours);
}


void hours_minutes_seconds(int *seconds, int *minutes, int *hours){
    //Beregner antal timer og finder resten
    *hours = *seconds / SEC_PER_HOUR;
    *seconds = *seconds % SEC_PER_HOUR;

    //Beregner antal minuter og finder resten
    *minutes = *seconds / SEC_PER_MIN;
    *seconds = *seconds % SEC_PER_MIN;
}