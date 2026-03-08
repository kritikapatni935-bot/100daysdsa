//Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff, exp;
    struct Node* next;
};

struct Node* insert(struct Node* head, int c, int e){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void printPolynomial(struct Node* head){
    while(head != NULL){
        if(head->exp == 0)
            printf("%d", head->coeff);
        else if(head->exp == 1)
            printf("%dx", head->coeff);
        else
            printf("%dx^%d", head->coeff, head->exp);

        if(head->next != NULL)
            printf(" + ");

        head = head->next;
    }
}

int main(){
    int n,c,e;
    struct Node* head = NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d %d",&c,&e);
        head = insert(head,c,e);
    }

    printPolynomial(head);

    return 0;
}
// Day 31
