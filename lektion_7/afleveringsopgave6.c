#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double trapz();
double sum();
double h();
double g();
double length();

int main(void){ 
    double (*fn) (double);
    char f;
    double a, b, n;
    printf("Give me the limits a,b\n");
    scanf(" %lf %lf", &a, &b);
    printf("Now give me a number for the fineness and a char for the function\n");
    scanf(" %lf %c", &n, &f);
    switch(f){ /* Ændre på hvilken funktion vi beregner areal på */
        case 'h': fn = &h; break;
        case 'g': fn = &g; break;
        default : fn = &h; break;
    }
    printf("The area is calculated to be = %lf\n",trapz(a, b, n, fn) ); 
    return EXIT_SUCCESS;
}

double trapz(double a, double b, double n, double (*fn) (double)){
    /*T = h/(2)(f(a)+f(b)+2(sum(f, i = a + h .. n - b))*/
    return length(a, b, n)/2 * (fn(a) + fn(b) + 2*(sum(length(a, b, n), a, b, fn)));
}

/* beregner sumnotationen fra formlen 
*  sum(f, i = a + h .. n - b)) */
double sum(double h, double a, double b, double (*fn) (double)){
    double sum = 0.0, i;
    for(i = a + h; i < b - h; i+= h)
        sum += fn(i);
    return sum;
}

/* Regner længden af trapez intervallet */
double length(double a, double b, double n){
    return (b - a) / n;
}

/* Cirkel: sqrt(4-x^2) */
double h(double x){
    return sqrt(4-(x*x));
}
/* x^2 * sin(x) */
double g(double x){
    return x * x * sin(x);
}
