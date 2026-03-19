// Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
};

struct Stack{
    int *arr;
    int top;
};

void enqueue(struct Queue* q, int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(q->rear == NULL){
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q){
    if(q->front == NULL)
        return -1;
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = NULL;
    free(temp);
    return val;
}

int isEmptyQueue(struct Queue* q){
    return q->front == NULL;
}

void push(struct Stack* s, int x){
    s->arr[++s->top] = x;
}

int pop(struct Stack* s){
    return s->arr[s->top--];
}

int isEmptyStack(struct Stack* s){
    return s->top == -1;
}

int main(){
    int n;
    scanf("%d", &n);

    struct Queue q;
    q.front = q.rear = NULL;

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    struct Stack s;
    s.arr = (int*)malloc(sizeof(int) * n);
    s.top = -1;

    while(!isEmptyQueue(&q))
        push(&s, dequeue(&q));

    while(!isEmptyStack(&s))
        printf("%d ", pop(&s));

    free(s.arr);
    return 0;
}
// Day 42
