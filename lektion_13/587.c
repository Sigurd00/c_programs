#include <stdlib.h>
#include <stdio.h>

int blob_check(int arr[][5], int blobx, int bloby);

int main(void){
    int arr[5][5] = {{1, 1, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 0, 1, 0, 1},
                    {1, 0, 0, 0, 1},
                    {0, 1, 0, 1, 1}};
    printf("Black cells:%d", blob_check(arr, 1, 1));
}

int blob_check(int arr[][5], int blobx, int bloby){
    if(blobx < 0 || blobx > 4 || bloby < 0 || bloby < 0) /* blob is out of bounds */
        return 0;
    else if(arr[blobx][bloby] == 1){ /* blob is black */
        arr[blobx][bloby] = 0;
        /* check all around it */
        return 1 + blob_check(arr, blobx - 1, bloby -1) + blob_check(arr, blobx, bloby -1) + blob_check(arr, blobx + 1, bloby -1) 
                 + blob_check(arr, blobx - 1, bloby)    + blob_check(arr, blobx + 1, bloby)
                 + blob_check(arr, blobx - 1, bloby +1) + blob_check(arr, blobx, bloby +1) + blob_check(arr, blobx + 1, bloby + 1);
    }
    else return 0;/* Blob is white */
}