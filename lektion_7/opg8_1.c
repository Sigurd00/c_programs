#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void maaltid(int);
int make_random_forret();
int make_random_hovedret();
int make_random_dessert();
void print_forret();
void print_hovedret();
void print_dessert();

enum forret  {guacamole, tarteletter, lakseruller, graeskarsuppe};
enum hovedret{gyldenkaal, hakkeboef, gullash, fiskefrikadeller};
enum dessert {pandekager, gulerodskage, chokolademousse, citronfromage};

typedef enum forret eforret;
typedef enum hovedret ehovedret;
typedef enum dessert edessert;

int main(void){
    srand(time(NULL));
    for(int i = 1; i <= 25; i++)
        maaltid(i);
    return EXIT_SUCCESS;
}

void maaltid(int n){
    printf("Maaltid %d\n", n);
    print_forret(make_random_forret());
    print_hovedret(make_random_hovedret());
    print_dessert(make_random_dessert());
    printf("\n");
}

int make_random_forret(){
    return rand() % 4;
}

int make_random_hovedret(){
    return rand() % 4;
}

int make_random_dessert(){
    return rand() % 4;
}
void print_forret(const eforret n){
    printf("Forret:   ");
    switch(n){
        case guacamole:        printf("Guacamole ");        break;
        case tarteletter:      printf("Tarteletter ");      break;
        case lakseruller:      printf("Lakseruller ");      break;
        case graeskarsuppe:    printf("Graeskarsuppe ");    break;
    }
    printf("\n");
}

void print_hovedret(const ehovedret n){
    printf("Hovedret: ");
    switch(n){
        case gyldenkaal:       printf("Gyldenkaal ");       break;
        case hakkeboef:        printf("Hakkeboef ");        break;
        case gullash:          printf("Gullash ");          break;
        case fiskefrikadeller: printf("Fiskefrikadeller "); break;
    }
    printf("\n");
}

void print_dessert(const edessert n){
    printf("Dessert:  ");
    switch(n){
        case pandekager:       printf("Pandekager ");       break;
        case gulerodskage:     printf("Gulerodskage ");     break;
        case chokolademousse:  printf("Chokolademousse ");  break;
        case citronfromage:    printf("Citronfromage ");    break;
    }
    printf("\n");
}