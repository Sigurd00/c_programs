#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum runde{ones = 1, twos, threes, fours, fives, sixes, 
           onePair, twoPairs, threeKind, fourKind, sStraight,
           lStraight, house, chance, yatzy};
enum runde runde;
/*round er brugt, så blev nødt til at bruge det danske ord*/
#define FIRST_ROUND ones
#define LAST_ROUND yatzy
#define SENTINAL 5

int *roll_multiple_dies(int);
int prompt_for_count_dies();
void play_yatzy(int);
void play_round(int, int);
int play_upper_section(int *, int, int);
char* print_round_title(int);
int play_lower_section(int *, int, int);
int el_cmp(const void *, const void *);

int main(void){
    srand(time(NULL));
    int score[15] = {0};
    int n;
    do{
        n = prompt_for_count_dies();
        if(n >= SENTINAL){
            play_yatzy(n);
            /*Hver runde skal de bedste 5 terninger vælges*/
        }        
    } while (n >= SENTINAL);  
}

int prompt_for_count_dies(){
    int n;
    printf("How many dies do you want to roll? [N < 5 terminates]:");
    scanf(" %d", &n);
    return n;
}

void play_yatzy(int n){
    for(runde = FIRST_ROUND; runde < LAST_ROUND; runde++){
        play_round(runde, n);
    }
}

void play_round(int runde, int n){
    int points = 0;
    int *dice_rolls = roll_multiple_dies(n);
    if(runde <= sixes)
        points += play_upper_section(dice_rolls, runde, n);
    if(runde == sixes && points >= 63)
        points += 50;/*Hvis man har fået nok til bonus points */
    if(runde > sixes)
        play_lower_section(dice_rolls, runde, n);
}

int *roll_multiple_dies(int n){    
    int *dice_rolls = (int *) malloc(n * sizeof(int));
    int i;
    for(i = 0; i < n; i++){
        dice_rolls[i] = rand() % 6 + 1;
    }
    return dice_rolls;
}

int play_upper_section(int * dice_rolls, int runde, int n){
    int i, points = 0;
    char *round_title;
    printf("%s Dice rolls = ", round_title = print_round_title(runde));
    for(i = 0; i < n; i++){
        printf("%d ", dice_rolls[i]);
        if(dice_rolls[i] == runde)
            /*TODO: Sørg for at den kun tager de bedste 5 terninger*/
            /*TODO: Håndhæv at der mindst skal være 3 af hver slags for at tælle*/
            points += runde;
    }
    printf("Points =  %d", points);
    printf("\n");
    free(round_title); /*Free fra heap*/
    return points;
}

char *print_round_title(int runde){
    char *runde_tekst = (char *) malloc(strlen("Three of a Kind ") * sizeof(char));
    switch (runde)
    {
    case ones:      runde_tekst = "Ones            "; break;
    case twos:      runde_tekst = "Twos            "; break;
    case threes:    runde_tekst = "Threes          "; break;
    case fours:     runde_tekst = "Fours           "; break;
    case fives:     runde_tekst = "Fives           "; break;
    case sixes:     runde_tekst = "Sixes           "; break;
    case onePair:   runde_tekst = "One pair        "; break;
    case twoPairs:  runde_tekst = "Two pairs       "; break;
    case threeKind: runde_tekst = "Three of a Kind "; break;
    case fourKind:  runde_tekst = "Four of a Kind  "; break;
    case sStraight: runde_tekst = "Small Straight  "; break;
    case lStraight: runde_tekst = "Large Straight  "; break;
    case house:     runde_tekst = "Full House      "; break;
    case chance:    runde_tekst = "Chance          "; break;
    case yatzy:     runde_tekst = "Yatzy           "; break;
    
    default: 
        printf("\n\n Something went wrong, exiting \n\n");
        exit(EXIT_FAILURE); break;
    }
    return runde_tekst;
}

int play_lower_section(int * dice_rolls, int runde, int n){
    int i, pairOne = 0, points = 0;
    qsort(dice_rolls, n, sizeof(int), el_cmp);
    switch (runde)
    {
    case onePair:
        for(i = n; i > 0; i--){
            if(dice_rolls[i] == dice_rolls[i-1]){
                points += dice_rolls[i]*2;
            }
        }
        break;
    case twoPairs:
        for(i = n; i > 0; i--){
            if(dice_rolls[i] == dice_rolls[i-1]){
                pairOne = dice_rolls[i];
            }
            if(dice_rolls[i] == dice_rolls[i-1] && dice_rolls[i] != pairOne && pairOne != 0){
                points += pairOne*2 + dice_rolls[i]*2;
            }
        }
        break;
    case threeKind: /*TODO: Find en god måde at lave den nederste del af spillet */
        for
    default:
        break;
    }
    
    
    
}
play_pairs()

int el_cmp(const void *ep1, const void *ep2){
    double *tp1 = (double*) ep1,
           *tp2 = (double*) ep2;
    if(*tp1 < *tp2){
        return -1;
    }
    else if (*tp1 > *tp2){
        return 1;
    }
    else 
        return 0;
}
