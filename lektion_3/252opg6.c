#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int x,
    y;

    printf("Enter the point as x y:\n");
    scanf(" %d %d", &x, &y);

    if( x > 0 && y > 0)
        printf("The point is in Q I\n");
    else if(x < 0 && y > 0)
        printf("The point is in Q II\n");
    else if( x < 0 && y < 0)
        printf("The point is in Q III\n");
    else if(x > 0 && y < 0)
        printf("The point is in Q IV\n");
    else
        printf("The point is in the center of the Cartesian plane\n");
 
    return(EXIT_SUCCESS);
}