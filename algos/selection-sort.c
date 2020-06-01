// Selection sort

/*
Select the smallest element and compare with all the other elements in the list and swap it if its in the wrong order
*/

#include<stdio.h>
#include<stdlib.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int *array, int size){

    for (int i = 0; i < size; i++){
        printf("%d", array[i]);
        printf(" ");
    }
}
void selectionSort(int *array, int n){

    int min_idx;
    for (int i =0; i < n-1; i++){
        //find the minimum element in the unsorted array
        min_idx = i;
        for (int j = i+1; j < n; j++){
            if (array[j] < array[min_idx]){
                min_idx = j;
            }
        }
        // swap the found minimum element with the first element
        swap(&array[i], &array[min_idx]);
    }
}
int main(){

    int array[10];

    printf("Enter the elements\n");
    for (int i = 0; i < 10; i++){
        scanf("%d", &array[i]);
    }

    int n = sizeof(array)/sizeof(array[0]);
    selectionSort(array, n);
    printArray(array, n);

    return 0;
}