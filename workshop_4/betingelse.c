#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int isPrime(int);
int isGcd1(int);
int is2mod5(int);

int main(void){
  int x;
  int p, q, r;

  for(x = 1; x <= 10000000000; x++){
    p = isPrime(x);
    q = isGcd1(x);
    r = is2mod5(x);
    if ((p && !r) || !(p || !q || r) || (!p && !q && r)){
      printf("Du fandt et x\n");
      printf("p er %d, q er %d, r er %d og x er %d\n", p,q,r,x);
    }
  }
  return EXIT_SUCCESS;
}

/* Denne funktion skal returnere 1 hvis x er et primtal og 0 ellers */
int isPrime(int i){
    int k, limit;
    assert(i >= 0);
    
    if (i == 1) 
        return 0;
    else if (i == 2) 
        return 1;
    else if (i % 2 == 0)
    return 0;
    else{
        limit = (int)(ceil(sqrt(i)));
        for (k = 3; k <= limit; k += 2)
            if (i % k == 0)
                return 0;
        return 1;
   }
}

/* Denne funktion skal returnere 1 hvis gcd(x,2)=1 og 0 ellers */
int isGcd1(int x){
    return x % 2;
}

/* Denne funktion skal returnere 1 hvis 9^x-2 mod 5 = 2 og 0 ellers */ 
int is2mod5(int x){
    return x % 2;
}
