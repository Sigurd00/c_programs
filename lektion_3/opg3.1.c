#include <stdio.h>
#include <stdlib.h>

#define DELTA 0.01
#define RSQ (r*r)
#define HYPOTENUS (x * x + y * y)

int main(void){
    int opg;
    double r,
    x,
    y;

    printf("Give me two values which indicates a point:\n");
    scanf(" %lf %lf", &x, &y);
    printf("Give me a radius of the circle:\n");
    scanf("%lf", &r);

    printf((RSQ + DELTA >= HYPOTENUS && RSQ - DELTA <= HYPOTENUS) ? "The point is on the edge of the circle\n" :(RSQ > HYPOTENUS) ? "The point is within the circle\n" : "The point is not within the circle\n");

/*
    if ( r * r == x * x + y * y)
        printf("The point is on the edge of the circle\n");
    else if (r * r > x * x + y * y)
        printf("The point is within the circle\n");
    else
        printf("The point is not within the circle\n");
*/
    return (EXIT_SUCCESS);
}


/*
    Det der er kommenteret ud er med if kontrolstruktur,
    Man kan lave det som en oneliner med et betinget udtryk 
    som man kan se vi har gjort på linje 18.

    Der er defineret nogle konstanter for at gøre det mere læseligt

    Delta definere hvor præcis vi skal være før den er PÅ cirklen
*/