#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LGT 50
typedef struct person{
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
} person;

person *get_person(char *filename);
int count_file_lines(char *filename);
void print_person(person person);
person construct_person(char *filename);
void sort_persons_by_surname(person person[], int n);
int cmp_persons_by_surname();
void save_person_list(person person[], int n, char *filename);

int main(void){
    int n, i;
    person *person = get_person("adresser.txt");
    n = count_file_lines("adresser.txt");

    for(i = 0; i < n; i++){
        print_person(person[i]);
    }
    sort_persons_by_surname(person, n);
    
    save_person_list(person, n, "savedlist.txt");

    free(person);
    return EXIT_SUCCESS;
}


person *get_person(char *filename){
    int n = count_file_lines(filename), i;
    char line[64];

    person *person = (struct person *) malloc(sizeof(struct person) * n);
    FILE *stream = fopen(filename, "r");

    for(i = 0; i < n; i++){
        fgets(line, 64, stream);
        person[i] = construct_person(line);
    }
    
    fclose(stream);
    return person;
}

int count_file_lines(char* filename){
    char line[64];
    int count = 0;
    FILE *stream = fopen(filename, "r");

    while(fgets(line, 64, stream)){
        count++;
    }
    fclose(stream);
    return count;
}

person construct_person(char *line){
    person person;
    sscanf(line, " %s %[ A-Za-z ] , %[ a-zA-Z ] %d , %d %[^.] .",
            &person.fornavn, &person.efternavn, &person.vejnavn,
            &person.vejnummer, &person.postnummer, &person.bynavn);
    return person;
}

void print_person(person person){
    printf("%s %s, %s %d, %d %s\n",
           person.fornavn, person.efternavn, person.vejnavn, 
           person.vejnummer, person.postnummer, person.bynavn);
}

void sort_persons_by_surname(person person[], int n){
    qsort(person, n, sizeof(struct person), cmp_persons_by_surname);
}

int cmp_persons_by_surname(const person *person1, const person *person2){
    return strcmp(person1->efternavn, person2->efternavn);
}

void save_person_list(person person[], int n, char *filename){
    int i;
    char line[64];
    FILE *stream = fopen(filename, "w");

    for(i = 0; i < n; i++){
        strcpy(line, person[i].bynavn);
        strcat(line, ": ");
        strcat(line, person[i].efternavn);
        strcat(line, "\n\0");
        fputs(line, stream);        
    }
    fclose(stream);
}