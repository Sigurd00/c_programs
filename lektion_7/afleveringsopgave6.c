#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double trapz();
double sum();
double h();


int main(void){ 
    double (*fn) (int);
    char f;
    int a, b, n;
    printf("Give me the limits a,b\n");
    scanf(" %d %d", &a, &b);
    printf("Now give me a number for the fineness and a char for the function\n");
    scanf(" %d %c", &n, &f);
    if( f == 'h')
        fn = &h;

    printf("The area is calculated to be = %lf",trapz(a, b, n, fn) ); 
    
    return EXIT_SUCCESS;
}

double trapz(int a, int b, int n, double (*fn) (int)){
    double h = (b - a) / n;

    double T =  h/2 * (fn(a) + fn(b) + 2*(sum(n, fn)));

    return T;
}


double sum(int n, double (*fn) (int)){
    double sum = 0.0;
    int i;
    for(i = 1; i < n; i++)
        sum += fn(n);
    return sum;
}

double h(int x){
    return sqrt(4-(x*x)); 
}