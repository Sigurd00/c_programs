#include <stdio.h>
#include <stdlib.h>

int population_projection(double, double, double);

int main(void){
    double x,y,z;
    printf("Give me the start population, the growth and the top population:\n");
    scanf(" %lf %lf %lf",&x, &y, &z);

    printf("It takes %d years to reach a population of %3.lf",population_projection(x, y, z), z);
}


int population_projection(double pop, double growth, double top_pop){
    int countYears = 0;
    while (pop <= top_pop){
        pop *= growth;
        countYears += 1;
    }
    return(countYears);   
}