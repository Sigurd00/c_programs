#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DECK_SIZE 55
#define JOKER_COUNT 3

enum numeral{deuce = 2, treys, four, five, six, seven, eight,
                  nine, ten, jack, queen, king, ace};
enum suit{clubs = 1, diamonds, hearts, spades};
/*Vi antager her at ace er højeste værdi*/
enum numeral numeral;
enum suit suit;

typedef struct card {
    int suit;
    int numeral_value;
    int is_joker; /*Boolean*/
} card;

void make_deck(card *deck);
card make_card(int suit, int numeral_value, int is_joker);
void prnt_deck(card *card);
void prnt_card(card card);
void sort_cards_suit_joker_numeral(card deck[], int size);
int card_cmp_suit_joker_numeral();
int card_cmp_joker(int is_joker1, int is_joker2);
int card_cmp_numeral(int numeral1, int numeral2);
int card_cmp_suit(int suit1, int suit2);

int main(void){
    card deck[DECK_SIZE];

    make_deck(deck);
    printf("####Unsorted####\n");
    prnt_deck(deck);
    sort_cards_suit_joker_numeral(deck, DECK_SIZE);
    printf("\n\n####Sorted####\n");
    prnt_deck(deck);
    return EXIT_SUCCESS;
}

/*Makes a whole deck of cards*/
void make_deck(card *deck){
    int i = 0;
    for (suit = spades; suit >= clubs; suit--){ /*Goes through every suit*/
        for (numeral = deuce; numeral <= ace; numeral++, i++){ /* And every numeral */
            deck[i] = make_card(suit, numeral, 0);
        }
    }
    for(i = 52; i < 52+JOKER_COUNT; i++){ 
        deck[i] = make_card(0, 0, 1);
    }
}

/*Makes a card with given input*/
card make_card(int suit, int numeral_value, int is_joker){
    card result;
    result.suit = suit;
    result.numeral_value = numeral_value;
    result.is_joker = is_joker;

    return result;
}

/*Prints the information from the whole deck*/
void prnt_deck(card *card){
    int i;
    printf("1: Clubs\n2: Diamonds\n3: Hearts\n4: Spades\n0: JOKER\n\n");
    for (i = 0; i < DECK_SIZE; i++){
        prnt_card(card[i]);
    }
}

/*Prints the information from a card*/
void prnt_card(card card){
    char *is_joker;
    is_joker = (card.is_joker ? "IS JOKER" : "NOT JOKER");
    printf("CARD: %d %2d   : %s \n",
            card.suit, card.numeral_value, is_joker);
}

/*Sorts the deck of cards*/
void sort_cards_suit_joker_numeral(card deck[], int size){
    qsort(deck, size, sizeof(card), card_cmp_suit_joker_numeral);
}

/*Compares a card by suit, joker and numeral*/
int card_cmp_suit_joker_numeral(const card *card1, const card *card2){
    if(card1->is_joker || card2->is_joker)
        return card_cmp_joker(card1->is_joker, card2->is_joker);
    else if(card1->suit == card2->suit)
        return card_cmp_numeral(card1->numeral_value, card2->numeral_value);
    else
        return card_cmp_suit(card1->suit, card2->suit);
}

/*Compares a card by joker*/
int card_cmp_joker(int is_joker1, int is_joker2){
    return (is_joker1 > is_joker2) - (is_joker1 < is_joker2);
}

/*Compares a card by numeral*/
int card_cmp_numeral(int numeral1, int numeral2){
    return (numeral1 > numeral2) - (numeral1 < numeral2);
}

/*Compares a card by suit*/
int card_cmp_suit(int suit1, int suit2){
    return (suit1 > suit2) - (suit1 < suit2);
}