#include <stdlib.h>
#include <stdio.h>

double multy_apply();
double multy_apply_2();
double half();

int main(void){
    int n;
    double s;
    printf("Please enter the amount of times you want to operate, and the nubmer you want to operate on\n");
    scanf(" %d %lf", &n, &s);
    printf("The result is of multy_apply is  : %lf\n", multy_apply(half, n, s));
    printf("The result is of multy_apply_2 is: %lf\n", multy_apply_2(half, half, n, s));
    return EXIT_SUCCESS;
}

double multy_apply(double fn(double), int n, double s){
    for(int i = 0; i < n; i++){
        s = fn(s);
    }
    return s;
}

double multy_apply_2(double fn(double), double gn(double), int n, double s){
    for(int i = 0; i < n; i++){
        s = fn(s);
        s = gn(s);
    }
    return s;
}

double half(double x){
    return x/2;
}