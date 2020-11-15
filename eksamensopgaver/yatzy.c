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
void play_yatzy(const int);
int *roll_multiple_dies(const int);
int *save_unsorted_dies(int*, const int);
int play_round(int *, const int, const int);
void show_round_results(int *, const int, const int, const int, const int, const int);
void show_game_result(int *, const int);
char *print_round_title(const int);
int get_same_kind(int *, const int, const int, const int);
int get_value_of_pairs(int *, const int, const int, const int);
int get_straight(int *, const int, const int);
int get_full_house(int *, const int, const int);
int get_chance(int *, const int);
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

/*Funktion der styrer spillets flow,
sørger for at alle runder bliver spillet, og sørger for at der bliver kommunikeret med brugeren*/
void play_yatzy(const int n){
    int round_points[16] = {0}; /*round_points[0] er reserveret til summen af rundernes score*/
    int *dice_rolls;
    int *unsorted_dice_rolls;
    int got_bonus_bool = 0;
    for(runde = FIRST_ROUND; runde <= LAST_ROUND; runde++){
        dice_rolls = roll_multiple_dies(n);
        unsorted_dice_rolls = save_unsorted_dies(dice_rolls, n);
        round_points[runde] = play_round(dice_rolls, runde, n);
        round_points[0] += round_points[runde];
        if(runde == sixes && round_points[0] >= 63){ /*Har vi fået nok points til at få bonus points?*/
            round_points[0] += BONUS;
            show_round_results(unsorted_dice_rolls, runde, round_points[runde], round_points[0], n, BONUS);
            got_bonus_bool = 1;
        } else {
            show_round_results(unsorted_dice_rolls, runde, round_points[runde], round_points[0], n, NO_BONUS);
        }
    }
    show_game_result(round_points, got_bonus_bool);
    free(dice_rolls); free(unsorted_dice_rolls); /*Free fra heap*/
}

/*Allokere dynamisk den plads der skal til og fylder listen med tilfældige tal*/
int *roll_multiple_dies(const int n){
    int *dice_rolls = (int *) malloc(n * sizeof(int));
    int i;
    for(i = 0; i < n; i++){
        dice_rolls[i] = rand() % 6 + 1;
    }
    return dice_rolls;
}

/*Gemmer på de usorteret terninger til pæn formatering til brugeren*/
int *save_unsorted_dies(int *dice_rolls, const int n){
    int *unsorted_dice_rolls = (int *) malloc(n * sizeof(int));
    int i;
    for(i = 0; i < n; i++){
        unsorted_dice_rolls[i] = dice_rolls[i];
    }
    return unsorted_dice_rolls;
}

/*Finde ud af hvor mange point vi skal have alt efter hvilken runde det er
* Bruger mange hjælpe-funktioner*/
int play_round(int *dice_rolls, const int runde, const int n){
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
            default:
                printf("\n\n Something went wrong, exiting \n\n"); 
                exit(EXIT_FAILURE); break;
        }
    }
    return points;
}

/*Funktion der kommunikere til brugeren  terninger der er blevet slået, og hvor mange points det blev udregnet til*/
void show_round_results(int *dice_rolls, const int runde, const int points, const int total_points, const int n, const int bonus){
    char *round_title; /*Så vi ikke taber vores pointer fra heap*/
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
    free(round_title); /*Free fra heap*/
}


/*Funktion der efter spillet viser en oversigt over hvor mange points man fik i hver runde*/
void show_game_result(int *round_points, const int got_bonus_bool){
    char *round_title; /*Så vi ikke taber vores pointer fra heap*/
    printf("\nTotal points : %d\n", round_points[0]);
    for(runde = FIRST_ROUND; runde < LAST_ROUND; runde++){
        printf("%s : %d\n", round_title = print_round_title(runde), round_points[runde]);
        if(runde == sixes && got_bonus_bool){
            printf("\n####################\n");
            printf("BONUS POINTS    : 50\n");
            printf("####################\n\n");
        }
        else if(runde == sixes && !got_bonus_bool){
            printf("\n####################\n");
            printf("NO BONUS POINTS : 0\n");
            printf("####################\n\n");
        }
    }
    free(round_title); /*Free fra heap*/
}

/*Håndtere hvad strengen til hver rundes navn skal være*/
char *print_round_title(const int runde){
    char *runde_tekst = (char *) malloc(strlen("Three of a Kind ") * sizeof(char));
    switch (runde){
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
int get_same_kind(int * dice_rolls, const int min_same_kind, const int runde, const int n){
    int i, j = 6, same_kind = 0, points = 0;
    /* assert(runde <= sixes || runde == threeKind || runde == fourKind || runde == yatzy); */
    if(runde <= sixes){ /*ones til sixes*/
        for(i = 0; i < n; i++){
            if(dice_rolls[i] == runde){
                same_kind++;
            }
        }
        if(same_kind >= min_same_kind){
            if(same_kind > 5){
                /*Vi har fundet flere end 5 terninger af same_kind, vi tager ikke flere end 5 terninger, derfor tager vi bare summen af 5 af de terninger*/
                points = 5 * runde;
            }
            else{ 
                points = same_kind * runde; /*Vi har fundet nok terninger, men ikke over 5*/
            }
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
int get_value_of_pairs(int *dice_rolls, const int pairs_requested, const int count_dice, const int disallowed){
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
int get_straight(int * dice_rolls, const int runde, const int n){
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
int get_full_house(int * dice_rolls, const int runde, const int n){
    int pair = 0, three_kind = 0, points = 0;
    
    if((three_kind = get_same_kind(dice_rolls, 3, threeKind, n))){
        three_kind /= 3; /*Værdien af én terning, ikke specielt optimalt...*/
        pair = get_value_of_pairs(dice_rolls, 1, n, three_kind);
        if(pair != 0){
            three_kind *= 3; /*Tilbage til summen af terningerne*/
            points = three_kind + pair;
        }
    }
    return points;
}

/*Tager summen af de største 5 terninger*/
int get_chance(int *dice_rolls, const int n){
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
