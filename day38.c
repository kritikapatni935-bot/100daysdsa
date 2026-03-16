// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
#include <stdio.h>
#include <string.h>

#define MAX 1000

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int value){
    if(front == -1){
        front = rear = 0;
        deque[front] = value;
    }
    else if(front > 0){
        front--;
        deque[front] = value;
    }
    else{
        printf("Overflow\n");
    }
}

void push_back(int value){
    if(front == -1){
        front = rear = 0;
        deque[rear] = value;
    }
    else if(rear < MAX-1){
        rear++;
        deque[rear] = value;
    }
    else{
        printf("Overflow\n");
    }
}

void pop_front(){
    if(front == -1){
        printf("Underflow\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
}

void pop_back(){
    if(front == -1){
        printf("Underflow\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        rear--;
    }
}

int get_front(){
    if(front == -1) return -1;
    return deque[front];
}

int get_back(){
    if(front == -1) return -1;
    return deque[rear];
}

int empty(){
    if(front == -1) return 1;
    return 0;
}

int size(){
    if(front == -1) return 0;
    return rear - front + 1;
}

void clear(){
    front = rear = -1;
}

void reverse(){
    int i = front, j = rear, temp;
    while(i < j){
        temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void sort(){
    int i, j, temp;
    for(i = front; i <= rear; i++){
        for(j = i + 1; j <= rear; j++){
            if(deque[i] > deque[j]){
                temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

void display(){
    if(front == -1){
        printf("Empty\n");
        return;
    }
    for(int i = front; i <= rear; i++){
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main(){
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);
    pop_back();
    push_back(30);

    printf("%d\n", get_front());
    printf("%d\n", get_back());
    printf("%d\n", size());

    reverse();
    display();

    sort();
    display();

    clear();
    printf("%d\n", empty());

    return 0;
}
// Day 39
