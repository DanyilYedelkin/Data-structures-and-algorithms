#include <stdio.h>
#include "sort.h"

void swap(int *x, int *y);

void PrintArray(int a[],int n, int prechod){
	int j;

    for(j = 1; j <= n; j++) printf("%2d ",a[j]);
    printf("\n");

}

void bubbleSort(int a[], int n, int dir){
    int i, j, elem;

    for(i = 0; i < n; i++){
        for(j = n ; j > i + 1; j--){
            if(dir == 1){
                if(a[j] < a[j-1]){
                    // for swapping
                    elem = a[j-1];
                    a[j-1] = a[j];
                    a[j] = elem;
                }
            } else if(dir == 0){
                if(a[j] > a[j-1]){
                    // for swapping
                    elem = a[j-1];
                    a[j-1] = a[j];
                    a[j] = elem;
                }
            }
        }
        PrintArray(a, n, dir);
    }
}

void insertSort(int *A, int n, int dir){
    int i, key, j;

    if(dir == 1){
        for (i = 1; i <= n; i++){
            key = A[i];
            j = i - 1;

            while (j > 0 && A[j] > key){
                A[j + 1] = A[j];
                j = j - 1;
            }

            A[j + 1] = key;
            PrintArray(A, n, dir);
        }
    } else if(dir == 0){
        for (i = 1; i <= n; i++){
            key = A[i];
            j = i - 1;

            while (j > 0 && A[j] < key){
                A[j + 1] = A[j];
                j = j - 1;
            }

            A[j + 1] = key;
            PrintArray(A, n, dir);
        }
    }
}


void selectionSort(int a[], int n, int dir){
    int i, j, minIndx;
    int maxIndx = 0;

    if(dir == 1){
        PrintArray(a, n, dir);
        for (i = 1; i <= n - 1; i++){
            minIndx = i;
            for(j = i + 1; j <= n; j++){
                if(a[j] < a[minIndx]){
                    minIndx = j;
                }
            }

            swap(&a[minIndx], &a[i]);
            PrintArray(a, n, dir);
        }
    }

    if(dir == 0){
        PrintArray(a, n, dir);
        for(i = 1; i <= n-1; i++){
            maxIndx = i;
            for(j = i + 1; j <= n; j++){
                if(a[j] > a[maxIndx]){
                    maxIndx = j;
                }
            }

            swap(&a[maxIndx], &a[i]);
            PrintArray(a, n, dir);
        }
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}