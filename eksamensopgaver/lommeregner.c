/*
*   Jacob Johannes Sigurd Skadborg
*   jskadb20@student.aau.dk
*   Gruppe A408a
*   Software
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SENTINAL 'q'

void run_calculator();
void scan_data();
void do_next_op(char, double, double *);
int operator_is_valid(char);
int operator_is_binary(char);


int main(void){
    run_calculator();
    return EXIT_SUCCESS;
}

/* 
*   Procedure that runs the calculator while SENTINAL is not entered
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
    } while (operator != SENTINAL); /*Program stops running if SENTINAL is inputted*/
    
}

/* 
*   Prompts user for an operator and option operand,
*   if the operator is binary, it takes the 2nd input
*   USES functions is_valid_operator, operator_is_binary
*/
void scan_data(char *operator, double *operand){
    do{
        printf("Enter operator, and an optional operand: ");
        scanf(" %c", operator);
        if(operator_is_valid(*operator)){
            if(operator_is_binary(*operator)){
                scanf(" %lf", operand);
            } else *operand = 0.0;
        } else fflush(stdin);/*This ensures that every char after operator is deleted if operator is not valid*/
    }while(!operator_is_valid(*operator));
}

/*
*   Checks if operator is valid.
*   Used for input validation.
*   Takes operator as char input
*   Returns 1 if operator is valid, 0 if not
*/
int operator_is_valid(char operator){
    int boolResult;
    if(operator == '+' ||
       operator == '-' ||
       operator == '*' ||
       operator == '/' ||
       operator == '^' ||
       operator == '#' ||
       operator == '%' ||
       operator == '!' ||
       operator == SENTINAL){ /*If operator is any of these, result = true*/
        boolResult = 1;
    }
    else boolResult = 0;
    return boolResult;
}

/* 
*   Checks if operator is binary
*   Takes operator input as char
*   returns 1 if operator is binary, 0 if not
*/
int operator_is_binary(char operator){
    int boolResult;
    if(operator == '+' ||
       operator == '-' ||
       operator == '*' ||
       operator == '/' ||
       operator == '^'){
        boolResult = 1;
    }
    else boolResult = 0;
    return boolResult;
}

/* 
*   Does a calculation depending on the operator
*   Also has resopnsibility for some of the input validation
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
        case '!': if(*accumulator != 0) *accumulator = 1 / *accumulator;   break;
        default: break;
    }
}
