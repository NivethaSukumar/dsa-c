/**
Inserting a node at the beginning of the list 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* head;

void insert(int x){
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(head != NULL) temp->next = head;
    head = temp;
}

void print(){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    head = NULL; //empty list;
    printf("How many numbers\n");
    int n, i, x;
    scanf("%d", &n);
    for (i=0; i <n; i++){
        printf("Enter the number\n");
        scanf("%d", &x);
        insert(x);
        print();
    }
}