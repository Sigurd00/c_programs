#include <stdio.h>

int main(void){
    int yard_length,
    yard_width,
    house_length,
    house_width,
    sqyard,
    sqhouse,
    work_area,
    total_time;

    int work_speed = 2;

    printf("Give me the length and the width of the yard\n");
    scanf(" %d %d", &yard_length, &yard_width);

    printf("Now give me the length and width of the house\n");
    scanf(" %d %d", &house_length, &house_width);
    
    sqyard = yard_width * yard_length;
    sqhouse = house_length * house_width;
    work_area = sqyard - sqhouse;
    total_time = work_area / work_speed;

    printf("The house is %d square feet\nThe yard is %d square feet\nThe total work area is %d\nThe time it will take you to mow the lawn is %d\n",
    sqhouse, sqyard, work_area, total_time);

    return 0;
}