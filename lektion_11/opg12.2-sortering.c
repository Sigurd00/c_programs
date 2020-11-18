#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BOOKS 10
#define TITLE_MAX 50
#define AUTHOR_MAX 40
#define PUBLISHER_MAX 20

struct book {
  char title[TITLE_MAX], author[AUTHOR_MAX], publisher[PUBLISHER_MAX];
  int publishing_year;
  int university_text_book;
};
typedef struct book book;

book make_book(char *title, char *author, char *publisher, int year, int text_book);
void sort_books_by_title(book shelf[], int);
void sort_books_by_year_and_type(book shelf[], int);
void prnt_book(book b);
int book_cmp(const void *p, const void *q);
int book_cmp_by_year_and_type();
int book_cmp_by_year(const book *book1, const book *book2);


int main(void) {
  book shelf[MAX_BOOKS];
  int i;

  shelf[0] =
    make_book("Problem Solving and Program Design in C", "Hanly and Koffman", 
              "Pearson", 2010, 1);   

  shelf[1] =
    make_book("C by Disssection", "Kelley and Pohl", 
              "Addison Wesley", 2001, 1);   

  shelf[2] =
    make_book("The C Programming Language", "Kernighan og Ritchie", 
              "Prentice Hall", 1988, 1);   

  shelf[3] =
    make_book("Pelle Erobreren", "Martin Andersen Nexoe",
              "Gyldendal", 1910, 0);

  shelf[4] = shelf[3];
  strcpy(shelf[4].title, "Ditte Menneskebarn");
  shelf[4].publishing_year = 1917;

  for(i = 0; i <=4; i++)
    prnt_book(shelf[i]);
    
  sort_books_by_title(shelf, 4);
  printf("####SORTED BY TITLE####\n");
  for(i = 0; i <=4; i++)
    prnt_book(shelf[i]);
    
  sort_books_by_year_and_type(shelf, 4);
  printf("###############################\n");
  printf("####SORTED BY TYPE AND YEAR####\n");
  printf("###############################\n");
  for(i = 0; i <=4; i++)
    prnt_book(shelf[i]);
  
  return 0;
}


book make_book(char *title, char *author, char *publisher, 
               int year, int text_book){
  book result;
  strcpy(result.title, title); strcpy(result.author, author); strcpy(result.publisher, publisher); 
  result.publishing_year = year;
  result.university_text_book = text_book;
 
  return result;
}

void prnt_book(book b){
  char *yes_or_no;

  yes_or_no = (b.university_text_book ? "yes" : "no"); 
  printf("Title: %s\n"
         "Author: %s\n"
         "Publisher: %s\n"
         "Year: %4i\n"
         "University text book: %s\n\n",
         b.title, b.author, b.publisher, 
         b.publishing_year, yes_or_no);
}

void sort_books_by_title(book shelf[], int last){
    qsort(shelf->title, last+1, sizeof(shelf[0]), book_cmp);
}

void sort_books_by_year_and_type(book shelf[], int last){
    qsort(shelf, last+1, sizeof(book), book_cmp_by_year_and_type);
}


int book_cmp(const void *p, const void *q){
    return strcmp(p, q);
}

int book_cmp_by_year_and_type(const book *book1, const book *book2){
    if(book1->university_text_book && !book2->university_text_book)
        return 1;
    else if(!book1->university_text_book && book2->university_text_book)
        return -1;
    else if(book1->university_text_book == book2->university_text_book)
        return book_cmp_by_year(book1, book2);
}

int book_cmp_by_year(const book *book1, const book *book2){
    return (book1->publishing_year > book2->publishing_year) - (book1->publishing_year < book2->publishing_year);
}