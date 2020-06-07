#include <stdio.h>
#include <stdlib.h>



void swap (int *xp, int *yp) {

    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int *array, int n){

    for (int i = 0; i <n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }

}

void selectionSort(int *array, int n){

    int min_index;
    for (int i = 0; i < n-1; i++){
        min_index = i;
        // to find the smallest element and its min_index
        for (int j = i+1; j < n; j++){
            if (array[j] < array[min_index]){
               min_index = j;
            }
        }
        // swap the elements
        swap(&array[i], &array[min_index]);
    }
}

void merge (int *L, int *R, int *array, int nL, int nR){

    int i = 0, j = 0, k = 0; 

    while (i < nL && j < nR){
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i = i+1;

        } else {
            array[k] = R[j];
            j = j+1;
        }
        k = k +1 ;
    }

    if (i < nL) {
        array[k] = L[i];
        i = i + 1;
        k = k + 1;
    }

    if (j < nR) {
        array[k] = R[j];
        j = j + 1;
        k = k + 1;
    }

}

void mergeSort(int *array, int n){
    int nL = n/2;

    int nR = n - nL;

    int L[n], R[n];
    if (n < 2 ) {
        return;
    }
    for (int i = 0; i < nL; i++){
        L[i] = array[i];
    } 

    for (int j = nL; j <n; j++){
        R[j-nL] = array[j];
    }

    mergeSort(L, nL);
    mergeSort(R, nR);
    merge(L, R, array, nL, nR);

}


int partition(int *array, int start, int end){
    int pIndex;
    int pivot = array[end];
    pIndex = start;

    for (int i = start ; i < end; i ++) {
        if (array[i] <= pivot){
            swap(&array[i], &array[pIndex]);
            pIndex++;
        }
    }
    swap(&array[pIndex], &array[end]);
    return pIndex;
}
void quickSort(int *array, int start, int end){
    
    int pIndex;
    if (start < end) {
        pIndex = partition(array, start, end);
        quickSort(array, start, pIndex-1);
        quickSort(array, pIndex+1, end);
    }
}
void printArray(int *array, int n){

    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);

        printf(" ");
    }
}

int main(){

    int array[6];
    char ch;

    printf("Enter the values of the array\n");
    for (int i = 0; i < 6; i++){
        scanf("%d", &array[i]);
    }

    printf("Enter the type of sort\n");
    ch = getchar();
    int n = sizeof(array)/sizeof(array[0]);

    switch(ch){

        case 'b':
            bubbleSort(array, n);
        case 's':
            selectionSort(array, n);
        case 'm':
            mergeSort(array, n);
        case 'q':
            quickSort(array, 0, n-1);
        // case 'i':
        //     insertionSort(array, n);
        default:
            quickSort(array, 0, n-1);
    }
    printArray(array, n);
    return 0;
}