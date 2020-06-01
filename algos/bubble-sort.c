// Bubble sort - check the adjacent elements and swap if left is greater than the right


#include <stdio.h>
#include <stdlib.h>




void swap(int *x, int*y){

    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int *array, int size){

    for (int i =0; i<size; i++){
        printf("%d", array[i]);
        printf(" ");
    }
}
void bubbleSort(int *array, int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-2; j++){
            if (array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}
int main(){

    int array[7];

    printf("Enter the elements in the array\n");
    for (int i = 0; i < 7; i++){
        scanf("%d", &array[i]);
    }

    int n = sizeof(array)/ sizeof(array[0]);

    bubbleSort(array, n);
    printArray(array, n);
}
