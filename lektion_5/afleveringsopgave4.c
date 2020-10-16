#include <stdio.h>
#include <math.h>

#define SENTINAL 0

void solveQuadraticEquation();
double calcDiscriminant();
double calcRootOne();
double calcRootTwo();

int main(void) {
  double a, b, c;
    
    do{
        printf("Give me three values: a, b, c\n");
        scanf(" %lf %lf %lf", &a, &b, &c);
        if (!(a == SENTINAL && b == SENTINAL && c == SENTINAL))
            solveQuadraticEquation(a, b, c);
    } while (!(a == SENTINAL && b == SENTINAL && c == SENTINAL));   
}

  /* Prints roots of the quadratic equation a * x*x + b * x + c = 0 */
void solveQuadraticEquation(double a, double b, double c){
    double discriminant = calcDiscriminant(a, b, c);
    double root1, root2;
    if (discriminant < 0)
        printf("The discriminant is: %.3lf \n No roots\n", discriminant);
    else if( discriminant == 0) {
        root1 = calcRootOne(a, b, discriminant);
        printf("The discriminant is: %.3lf \nThere is one root:%.3lf\n", discriminant, root1);
    }
    else{
        root1 = calcRootOne(a, b, discriminant);
        root2 = calcRootTwo(a, b, discriminant);
        printf("The discriminant is: %.3lf \nThere are two roots:%.3lf, and %.3lf \n", discriminant, root1, root2);
    }
}
/* Calculates the discriminant */
double calcDiscriminant(double a, double b, double c){
    double discriminant = b * b - 4 * a * c;
    return discriminant;
}
/* Calculates root one */
double calcRootOne(double a, double b, double discriminant){
    double root1;
    if (discriminant == 0)
        root1 = -b/(2*a);
    else
        root1 = (-b + sqrt(discriminant))/(2*a);
    return root1;
}
/* Calculates root two */
double calcRootTwo(double a, double b, double discriminant){
    double root2 = (-b - sqrt(discriminant))/(2*a);
    return root2;
}