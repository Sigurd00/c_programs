#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

enum runde{ones = 1, twos, threes, fours, fives, sixes,
           onePair, twoPairs, threeKind, fourKind, sStraight,
           lStraight, house, chance, yatzy};
enum runde runde;
/*round er brugt, så blev nødt til at bruge det danske ord*/
#define FIRST_ROUND ones
#define LAST_ROUND yatzy
#define SENTINAL 5
#define BONUS 50
#define NO_BONUS 0

int prompt_for_count_dies();
void play_yatzy(int);
int *roll_multiple_dies(int);
int *save_unsorted_dies(int*, int);
int play_round(int *, int, int);
void show_results(int *, int, int, int, int, int);
char *print_round_title(int);
int get_same_kind(int *, int, int, int);
int get_value_of_pairs(int *, int , int, int);
int get_straight(int *, int, int);
int get_full_house(int *, int, int);
int get_chance(int *, int);
int cmpfunc (const void *, const void *);

/*TODO: 
*   GENERAL: Sørg for at alle steder hvor der kan være const input parameter, skal dette forekomme.
*   General: Sørg for at alle variabler har samme naming convention, ie. diceRolls, eller dice_rolls 
*/
int main(void){
    int n;
    srand(time(NULL));
    do{
        n = prompt_for_count_dies();
        if(n >= SENTINAL){
            play_yatzy(n);
        }
    } while (n >= SENTINAL);
    return EXIT_SUCCESS;
}

/*Spørger brugeren hvor mange terninger der skal spilles med*/
int prompt_for_count_dies(){
    int n;
    printf("How many dies do you want to roll? [N < 5 terminates]:");
    scanf(" %d", &n);
    return n;
}

/*Spiller yatzy my dude*/
void play_yatzy(int n){
    int *dice_rolls;
    int *unsorted_dice_rolls;
    int points = 0, total_points = 0;
    for(runde = FIRST_ROUND; runde <= LAST_ROUND; runde++){
        dice_rolls = roll_multiple_dies(n);
        unsorted_dice_rolls = save_unsorted_dies(dice_rolls, n);
        points = play_round(dice_rolls, runde, n);
        total_points += points;
        if(runde == sixes && total_points >= 63){
            total_points += BONUS;
            show_results(unsorted_dice_rolls, runde, points, total_points, n, BONUS);
        } else {
            show_results(unsorted_dice_rolls, runde, points, total_points, n, NO_BONUS);
        }
    }
    free(dice_rolls); free(unsorted_dice_rolls);
}

/*Allokere dynamisk den plads der skal til og fylder listen med tilfældige tal*/
int *roll_multiple_dies(int n){
    int *dice_rolls = (int *) malloc(n * sizeof(int));
    int i;
    for(i = 0; i < n; i++){
        dice_rolls[i] = rand() % 6 + 1;
    }
    return dice_rolls;
}

/*Gemmer på de usorteret terninger til pæn formatering til brugeren*/
int *save_unsorted_dies(int *dice_rolls, int n){
    int *unsorted_dice_rolls = (int *) malloc(n * sizeof(int));
    int i;
    for(i = 0; i < n; i++){
        unsorted_dice_rolls[i] = dice_rolls[i];
    }
    return unsorted_dice_rolls;
}

/*Finde ud af hvor mange point vi skal have alt efter hvilken runde det er
* Bruger mange hjælpe-funktioner*/
int play_round(int *dice_rolls, int runde, int n){
    int points = 0;
    
    if(runde <= sixes){
        points = get_same_kind(dice_rolls, 3, runde, n);
    } else {
        switch (runde){
            case onePair:   points = get_value_of_pairs(dice_rolls, 1, n, 0); break;
            case twoPairs:  points = get_value_of_pairs(dice_rolls, 2, n, 0); break;
            case threeKind: points = get_same_kind(dice_rolls, 3, runde, n);  break;
            case fourKind:  points = get_same_kind(dice_rolls, 4, runde, n);  break;
            case sStraight: points = get_straight(dice_rolls, runde, n);      break;
            case lStraight: points = get_straight(dice_rolls, runde, n);      break;
            case house:     points = get_full_house(dice_rolls, runde, n);    break;
            case chance:    points = get_chance(dice_rolls, n);               break;
            case yatzy:     points = get_same_kind(dice_rolls, 5, runde, n);  break;
            default: exit(EXIT_FAILURE);                                      break;
        }
    }
    return points;
}

/*Samlet sted der kommunikere med brugeren om hvad hvilke terninger der er blevet slået, */
/*TODO: Sørg for at den ikke viser de sorteret terninger, det er ikke specielt pænt*/
void show_results(int *dice_rolls, int runde, int points, int total_points, int n, int bonus){
    char *round_title;
    int i;
    printf("%s ", round_title = print_round_title(runde));
    printf("Dice rolls = ");
    for(i = 0; i < n; i++){
        printf("%d ", dice_rolls[i]);
    }
    printf("Points = %2d Points so far = %d\n", points, total_points);
    if(runde == sixes && bonus){
        printf("                ############# BONUS %d POINTS #############\n", bonus);
    }
    free(round_title);
}

/*Håndtere hvad strengen til hver rundes navn skal være*/
char *print_round_title(int runde){
    char *runde_tekst = (char *) malloc(strlen("Three of a Kind ") * sizeof(char));
    switch (runde)
    {
    case ones:      runde_tekst = "Ones           "; break;
    case twos:      runde_tekst = "Twos           "; break;
    case threes:    runde_tekst = "Threes         "; break;
    case fours:     runde_tekst = "Fours          "; break;
    case fives:     runde_tekst = "Fives          "; break;
    case sixes:     runde_tekst = "Sixes          "; break;
    case onePair:   runde_tekst = "One pair       "; break;
    case twoPairs:  runde_tekst = "Two pairs      "; break;
    case threeKind: runde_tekst = "Three of a Kind"; break;
    case fourKind:  runde_tekst = "Four of a Kind "; break;
    case sStraight: runde_tekst = "Small Straight "; break;
    case lStraight: runde_tekst = "Large Straight "; break;
    case house:     runde_tekst = "Full House     "; break;
    case chance:    runde_tekst = "Chance         "; break;
    case yatzy:     runde_tekst = "Yatzy          "; break;

    default:
        printf("\n\n Something went wrong, exiting \n\n");
        exit(EXIT_FAILURE); break;
    }
    return runde_tekst;
}

/*Hjælpe-funktion til første 6 runder same Three of a Kind, Four of a Kind og Full house
* Bruges også til sidste runde, yatzy*/
int get_same_kind(int * dice_rolls, int min_same_kind, int runde, int n){
    int i, j = 6, same_kind = 0, points = 0;
    if(runde <= sixes){
        for(i = 0; i < n; i++){
            if(dice_rolls[i] == runde){
                /*TODO: Sørg for at den kun tager de bedste 5 terninger*/
                same_kind++;
            }
        }
        if(same_kind >= min_same_kind){
            points = same_kind * runde;
        }
    }
    else{ /*Three of a Kind og Four of a Kind*/
        while(points == 0 && j > 0){
            for(i = 0; i < n; i++){
                if(dice_rolls[i] == j){
                    same_kind++;
                }
                if(same_kind == min_same_kind){
                    points = same_kind * j;
                }
            }
            j--;
            same_kind = 0; /*Start forfra med at tælle hvor mange der er af samme tal*/
        }
    }
    return points;
}

/*Hjæle-funktion der finder par, 
* disallowed er til Full house, den må ikke finde et par som bliver brugt i 3 of a kind, skal være 0 i alle andre tilfælde*/
int get_value_of_pairs(int *dice_rolls, int pairs_requested, int count_dice, int disallowed){
    int *pairs = (int *) malloc(pairs_requested * sizeof(int));
    int i = count_dice, pairs_found = 0, pair_found_value = 0, points = 0;
    qsort(dice_rolls, count_dice, sizeof(int), cmpfunc); /*sortering af listen gør det en del nememere at finde par*/
    /*Kør ind til vi har fundet antallet af par der bliver spurgt om, eller til vi har gennemgået alle terninger*/
    while(pairs_found < pairs_requested && i > 0){
        if(dice_rolls[i] == dice_rolls[i - 1] && dice_rolls[i] != pair_found_value && dice_rolls[i] != disallowed){ /*Er den her terning ens med den næste?*/
            pairs[pairs_found] = dice_rolls[i];
            pairs_found++;
            pair_found_value = dice_rolls[i];   /*Hvis vi har fundet et par af 6'ere, skal vi ikke søge efter flere par af 6'ere*/
            i--; /*Vi kan hoppe over den terning der danner par*/
        }
        i--;
    }
    if(pairs_found < pairs_requested){ /*Hvis vi ikke finder så mange par som runden kræver, så får vi 0 points*/
        points = 0;
    } else {
        for(i = 0; i < pairs_found; i++){
            points += pairs[i] * 2;
        }
    }
    free(pairs); /*Free fra heap*/
    return points;
}


/*Ser om vores terninger kan lave en straight*/
int get_straight(int * dice_rolls, int runde, int n){
    int i, highest_in_straight = 0, points = 0;
    qsort(dice_rolls, n, sizeof(int), cmpfunc);
    for(i = 0; i < n; i++){
        if(dice_rolls[i] == highest_in_straight + 1){
            highest_in_straight++;
        }
    }
    /*1-2-3-4-5*/
    if(runde == sStraight && highest_in_straight >= 5){
        points = 15;
    }
    /*2-3-4-5-6*/
    else if(runde == lStraight && highest_in_straight == 6){
        points = 20;
    }
    else points = 0;
    return points;
}

/*Checks if the dice can make a full house*/
int get_full_house(int * dice_rolls, int runde, int n){
    int pair = 0, three_kind = 0, points = 0;
    
    if((three_kind = get_same_kind(dice_rolls, 3, threeKind, n))){
        three_kind /= 3; /*Værdien af én terning*/
        pair = get_value_of_pairs(dice_rolls, 1, n, three_kind);
        if(pair != 0){
            three_kind *= 3; /*Tilbage til summen af par*/
            points = three_kind + pair;
        }
    }
    return points;
}

/*Tager summen af de største 5 terninger*/
int get_chance(int *dice_rolls, int n){
    int i, points = 0;
    qsort(dice_rolls, n, sizeof(int), cmpfunc);
    for(i = n - 1; i > n - 6; i--){
        points += dice_rolls[i];
    }
    return points;
}

/*Hjælpe-funktion til qsort*/
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
