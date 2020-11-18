#include <stdlib.h>
#include <stdio.h>

struct Fractions{
    unsigned int numerator;
    unsigned int denominator;
};

typedef struct Fractions Fractions;

Fractions get_fraction(const unsigned int, const unsigned int);
Fractions get_short_fraction(Fractions);
Fractions get_product_fraction(Fractions, int);
Fractions get_product_two_fractions(Fractions, Fractions);
Fractions get_add_two_fractions(Fractions, Fractions);
void print_fraction(Fractions);
unsigned int gcd(unsigned int large, unsigned int small);


int main(void){
    Fractions f1;
    Fractions f2;
    f1 = get_fraction(4, 6);
    f2 = get_fraction(3, 6);
    
    printf("\nFraction 1\n");
    print_fraction(f1);
    printf("\nFraction 2\n");
    print_fraction(f2);

    f1 = get_product_fraction(f1, 2);
    printf("\nFraction 1 * 2\n");
    print_fraction(f1);

    f1 = get_product_two_fractions(f1, f2);
    printf("\nProduct of two fractions\n");
    print_fraction(f1);

    f1 = get_add_two_fractions(f1, f2);
    printf("\nAdding two fractions\n");
    print_fraction(f1);

    f1 = get_short_fraction(f1);
    printf("\nShort fraction\n");
    print_fraction(f1);
}

Fractions get_fraction(const unsigned int numerator, const unsigned int denominator){
    Fractions f1;
    f1.numerator = numerator;
    f1.denominator = denominator;
    return f1;
}

Fractions get_short_fraction(Fractions f1){
    int divisor = gcd(f1.denominator, f1.numerator);
    
    f1.numerator = f1.numerator / divisor;
    f1.denominator = f1.denominator / divisor;

    return f1;
}

Fractions get_product_fraction(Fractions f1, int opporant){
    f1.numerator = f1.numerator * opporant;

    return f1;
}

Fractions get_product_two_fractions(Fractions f1, Fractions f2){
    f1.numerator = f1.numerator * f2.numerator;
    f1.denominator = f1.denominator * f2.denominator;
    return f1;
}

Fractions get_add_two_fractions(Fractions f1, Fractions f2){
    int denominator = f1.denominator * f2.denominator;

    f1.numerator = f2.denominator * f1.numerator;
    f2.numerator = f1.denominator * f2.numerator;
    
    f1.numerator = f1.numerator + f2.numerator;
    f1.denominator = denominator;

    return f1;
}

void print_fraction(Fractions f1){
    printf("%d\n", f1.numerator);
    printf("-\n");
    printf("%d\n", f1.denominator);
    
}

unsigned int gcd(unsigned int large, unsigned int small){
    unsigned int remainder; 
    while (small > 0){
      remainder = large % small;
      large = small;
      small = remainder;
    }
    return large;
  }