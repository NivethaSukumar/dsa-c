// Merge sorting
/*
Big O notation : O(nlogn) -> Worst case
Omega notation: Omega(nlogn)-> Best case
*/

/*
Using recursion
First Divide the array to 2 halves
Sort the left half of the array
Sort the right half of the array
Merge the two arrays 
*/

 
#include <stdio.h>
#include <stdlib.h>

void merge(int *L, int *R, int *array, int size){
    int i = 0;
    int j = 0;
    int k = 0;

    int mid = size/2;
    int lr = size - mid;
    while (i < mid && j < lr){
        if (L[i] <= R [j]){
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    // for Left overs in L 
     while (i < mid) {
         array[k] = L[i];
         i++;
         k++;
    }

    // for left overs in Right side array

    while (j < lr){
        array[k] = R[i];
        j++;
        k++;
    }

}

void mergeSort(int *array, int n){

    int midpt;
    int L[n], R[n];
    
    if ( n < 2) return ;
    midpt = n/2;
    int lr = n - midpt;
    for (int i = 0; i <midpt; i++){
        L[i] = array[i];
    }
    for (int j = 0; j < lr; j++){
        R[j] = array[j];
    }
    mergeSort(L, midpt);
    mergeSort(R, lr);
    merge(L, R, array, n);
}
void printArray(int *array, int n){
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
    }
}
int main() {

    int array[6];
    printf("Enter the elements in the array\n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &array[i]);
    }
    int size = sizeof(array)/sizeof(array[0]);
    mergeSort(array, size);
    printArray(array, size);
    
}