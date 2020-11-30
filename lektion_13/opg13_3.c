#include <stdlib.h>
#include <stdio.h>

int quotient(int, int);
int modulo(int dividend, int divisor);

int main(void){
    printf("%d\n", quotient(6, 2));
    printf("%d\n", modulo(5, 2));
}

/* Does not like 0 */
int quotient(unsigned int dividend, unsigned int divisor){
    if(dividend < divisor)
        return 0;
    else return 1 + quotient(dividend - divisor, divisor);
}

/* Does not like 0 */
int modulo(int dividend, int divisor){
    if(dividend < divisor)
        return divisor - dividend;
    else return modulo(dividend - divisor, divisor);
}