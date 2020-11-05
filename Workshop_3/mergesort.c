#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

void merge(int L[], int start, int slut, int midt);
void mergeSort(int L[], int start, int slut);
void printList(int L[], int size);

int main(void){ 
    int L[] = { 5, 3, 8, 1, 6, 10, 7, 2, 4, 9 }; 
    int L_size = sizeof(L) / sizeof(L[0]); 
  	
    printf("Givet listen \n"); 
    printList(L, L_size); 
  
    mergeSort(L, 0, L_size - 1); 
  
    printf("Er den sorterede liste \n"); 
    printList(L, L_size); 
    return 0; 
}

void merge(int L[], int start, int slut, int midt){
    /* Start med at kopiere de to dellister ind i to nye lister L1 og L2, så vi ikke sletter nogle elementer fra L når vi begynder at flette elementerne derind */
    int *L1 = (int *) malloc((midt - start + 1) * sizeof(int));
    int *L2 = (int *) malloc((slut - midt) * sizeof(int));
    int i, j = 0, k = 0;
    for(i = 0; i <= midt - start + 1; i++){
        L1[i] = L[start + i];
        printf("L1[%d] = %d ", i, L1[i]);
    }
    printf("\n");
    for(i = 0; i <= slut - midt; i++){
        L2[i] = L[midt + i + 1];
        printf("L2[%d] = %d ", i, L2[i]);
    }
    printf("\n");

    /* Herefter skal vi kopiere elementer fra L1 og L2 ind på pladserne i L mellem start og slut men i sorteret rækkefølge */
    i = 0;
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
        for(k = j; k <= slut - midt - 1; k++)
            L[start + i + k] = L2[k];
    else
        for(k = i; k <= midt - start; k++)
            L[start + j + k] = L1[k];
    free(L1); free(L2);
}

void mergeSort(int L[], int start, int slut){
    if (start < slut){
        int m = floor((slut+start) /2);
        mergeSort(L, start, m);
        mergeSort(L, m + 1, slut);
        merge(L, start, slut, m);
    }
}

void printList(int L[], int size){ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", L[i]); 
    printf("\n"); 
}
