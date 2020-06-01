#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    string names[4] = {"EMMA", "NIVY", "SWETHA", "RAHUL"};

    for (int i = 0; i < 4; i++){
        if (strcmp(names[i], "NIVY") ==0){
            printf("Found\n");
            return 0;
        }
    } 
    printf("Not found\n");
    return 1;
}