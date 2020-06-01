// Quick sort
// Select a pivot and put the values less than the pivot towards the left side 
// Elements greater than the pivot on the right side

#include <stdio.h>
#include <stdlib.h>


void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


int Partition(int *array, int start, int end){
    int pivot = array[end];
    int pIndex = start;
    for (int i = start; i < end; i++){
        if (array[i] < pivot){
            swap(&array[i], &array[pIndex]);
            pIndex = pIndex +1;
        }
    }
    swap(&array[pIndex], &array[end]);
    return pIndex;

}
void quickSort(int *array, int start, int end){
    int pIndex;
    if (start < end) {
        pIndex = Partition(array, start, end);
        quickSort(array, start, pIndex-1);
        quickSort(array, pIndex+1, end);
    }
}

void printSortedArray(int *array, int size){
    for (int i = 0; i < size; i++){
        printf("%d", array[i]);
        printf(" ");
    }
}
int main(){
    
    int array[6];

    printf("Enter the elements in the array\n");
    for (int i =0; i < 6; i++){
        scanf("%d", &array[i]);
    }
    int size = sizeof(array)/sizeof(array[0]);
    quickSort(array, 0, size);
    printSortedArray(array, size);
}