// to inset a node at nth position in a linkedlist

#include <stdio.h>
#include <stdlib.h>

struct Node{

    int data;
    struct Node *next;
};

struct Node *head;

void Insert(int x, int n){

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (n == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *previousNode = head;
    for (int i = 1; i < n-1; i++){
        previousNode = previousNode->next;
    }
    newNode->next = previousNode->next;
    previousNode->next = newNode;
}
void Delete(int n){
    struct Node *temp1 = head;
    if (n == 1){
        head = temp1->next;
        free (temp1);
    }

    for (int i = 1; i < n-1; i++){
        temp1 = temp1->next;
    }
    // temp1 points to n-1 nth node.
    struct Node *temp2 = temp1->next; // nth node
    temp1->next = temp2->next;
    free(temp2);

}
void Print(){
    struct Node *temp = malloc(sizeof(struct Node));
    temp = head;

    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
int main(){
   head = NULL;

   Insert(2, 1);
   Insert(3, 2);
   Insert(5, 3);
   Insert(6, 4);
   Delete(3);
   Print();
   
}