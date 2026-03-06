// Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main(){
    int n,x;
    scanf("%d",&n);

    struct Node *head=NULL,*temp=NULL,*newNode=NULL;

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        newNode=createNode(x);

        if(head==NULL){
            head=newNode;
            temp=newNode;
        }else{
            temp->next=newNode;
            temp=newNode;
        }
    }

    temp->next=head;

    struct Node* ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);

    return 0;
}
// Day 29
