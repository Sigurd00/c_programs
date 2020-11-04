#include <stdlib.h>
#include <stdio.h>

int *merge(const int *, const int *, const int, const int);

int main(void){
    const int arr1[] = {1, 2, 3 , 4, 11, 15, 17, 29},
              arr2[] = {2, 7, 9, 11, 12, 13, 'a', 'b'};
    int count_arr1 = sizeof(arr1) / sizeof(const int),
        count_arr2 = sizeof(arr2) / sizeof(const int);
    int *combined;
    int i;
    combined = merge(arr1, arr2, count_arr1, count_arr2);
    printf("Combined array is: ");
    for(i = 0; i < count_arr1 + count_arr2; i++){
        printf("%d ", combined[i]);
    }
    free(combined);
    return EXIT_SUCCESS;
}

int *merge(const int *arr1, const int *arr2, const int count_arr1, const int count_arr2){
    int i, k = 0, j = 0;
    int *combined = (int *) malloc((count_arr1 + count_arr2) * sizeof(int));
    for(i = 0; i < count_arr1 + count_arr2; i++){
        if(j < count_arr1 && k < count_arr2){
            if(arr1[j] < arr2[k]){
                combined[i] = arr1[j];
                j++;
            }   
            else if(arr1[j] > arr2[k]){
                combined[i] = arr2[k];
                k++;
            }
            else {
                combined[i] = arr1[j];
                combined[i+1] = arr2[k];
                j++; k++; i++;
            }
        }
        else if(j < count_arr1){
            combined[i] = arr1[j];
                j++;
        }
        else {
            combined[i] = arr2[k];
                k++;
        }
    }
    return combined;
}
