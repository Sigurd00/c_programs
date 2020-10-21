#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SENTINAL 'q'

void run_calculator();
void scan_data();
void do_next_op(char, double, double *);
int operator_is_binary();



int main(void){
    run_calculator();
    return EXIT_SUCCESS;
}

/* 
*   Runs the calculator while q is not entered
*   USES functions scan_data, do_next_op
*/

void run_calculator(){
    char operator;
    double accumulator = 0.0,
               operand = 0.0;
    do{
        scan_data(&operator, &operand);

        if(operator != SENTINAL){
            do_next_op(operator, operand, &accumulator);
            printf("Result so far is %lf.\n", accumulator);
        }
        else printf("Final Result: %lf.\n", accumulator);
    } while (operator != SENTINAL);
    
}

/* 
*   Prompts user for an operator and option operand,
*   if the operator is binary, it takes the 2nd input
*   USES function operator_is_binary  
*/
void scan_data(char *operator, double *operand){
    char operatorPlaceholder;
    double operandPlaceholder;
        printf("Enter operator, and an optional operand: ");
    scanf(" %c", &operatorPlaceholder);
    if(operator_is_binary(&operatorPlaceholder))
        scanf(" %lf", &operandPlaceholder);
    else *operand = 0.0;
    *operator = operatorPlaceholder;
    *operand = operandPlaceholder;
}

/* 
*   Checks if operator is binary
*   returns 1 if operator is binary
*   returns 0 if operator is not binary
*/
int operator_is_binary(char *operator){
    int boolResult;
    if(*operator == '+' ||
       *operator == '-' ||
       *operator == '*' ||
       *operator == '/' ||
       *operator == '^'){
        boolResult = 1;
    }
    else boolResult = 0;
    return boolResult;
}

/* 
*   Does a calculation depending on the operator
*   Takes the operator as char, the operand as double and the accumulator as a double pointer 
*   outputs the accumulator through the pointer
*/
void do_next_op(char operator, double operand, double *accumulator){
    switch (operator)
    {
        case '+': *accumulator += operand;                                 break;
        case '-': *accumulator -= operand;                                 break;
        case '*': *accumulator *= operand;                                 break;
        case '/': if(operand != 0) *accumulator /= operand;                break;
        case '^': *accumulator = pow(*accumulator, operand);               break;
        case '#': if(*accumulator >= 0) *accumulator = sqrt(*accumulator); break;
        case '%': *accumulator = *accumulator * -1;                        break;
        case '!': *accumulator = 1 / *accumulator;                         break;
        default: break;
    }
}