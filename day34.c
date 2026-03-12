// Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(){
    if(top == NULL) return 0;
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main(){
    char exp[100];
    fgets(exp,100,stdin);
    char *token = strtok(exp," \n");

    while(token != NULL){
        if(isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))){
            push(atoi(token));
        }else{
            int b = pop();
            int a = pop();
            int res;
            if(token[0]=='+') res = a+b;
            else if(token[0]=='-') res = a-b;
            else if(token[0]=='*') res = a*b;
            else if(token[0]=='/') res = a/b;
            push(res);
        }
        token = strtok(NULL," \n");
    }

    printf("%d",pop());
    return 0;
}
// Day 35
