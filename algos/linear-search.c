// linear search in C
#include<stdio.h>
#include<stdlib.h>

int main(){

    int numbers[6] = {4, 5, 2, 10, 50, 3};

    for (int i =0; i < 6; i++){
        if(numbers[i] == 10){
            printf("Found the number\n");
        } else {
            printf("Not found\n");
        }
    }
}