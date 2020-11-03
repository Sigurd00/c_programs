#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

void Merge(int L[], int start, int slut, int midt);
void MergeSort(int L[], int start, int slut);
void printList(int L[], int size);

int main(void){ 
  int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 }; 
  int L_size = sizeof(L) / sizeof(L[0]); 
  	
  printf("Givet listen \n"); 
  printList(L, L_size); 
  
  MergeSort(L, 0, L_size - 1); 
  
  printf("Er den sorterede liste \n"); 
  printList(L, L_size); 
  return 0; 
} 
void Merge(int L[], int start, int slut, int midt){
  /* Start med at kopiere de to dellister ind i to nye lister L1 og L2, så vi ikke sletter nogle elementer fra L når vi begynder at flette elementerne derind */
    int L1[midt - start + 1], L2[slut - midt];
    for(int i = start; i <= midt; i++)
        L1[i] = L[i];
    for(int i = 0; i <= slut - midt - 1; i++)
        L2[i] = L[midt + i + 1];
  
  /* Herefter skal vi kopiere elementer fra L1 og L2 ind på pladserne i L mellem start og slut men i sorteret rækkefølge */

    int i = 0, j = 0;
    while (i < midt - start + 1 && j < slut - midt){
        if(L1[i] <= L2[j]){
            L[start + i + j] = L1[i];
            i++;
        }
        else{
            L[start + i + j] = L2[j];
            j++;
        }
    }
    if(i == midt - start + 1)
        for(int k = j; k <= slut - midt - 1; k++)
            L[start + i + k] = L2[k];
    else
        for(int k = i; k <= midt - start; k++)
            L[start + j + k] = L1[k];
}

void MergeSort(int L[], int start, int slut){
    if (start < slut){
        int m = floor((slut+start) /2);
        MergeSort(L, start, m);
        MergeSort(L, m + 1, slut);
        Merge(L, start, slut, m);
    }
}

void printList(int L[], int size){ 
  int i; 
  for (i = 0; i < size; i++) 
    printf("%d ", L[i]); 
  printf("\n"); 
} 