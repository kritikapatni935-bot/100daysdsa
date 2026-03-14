// Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1, size;

void enqueue(int value)
{
    if ((rear + 1) % size == front)
        return;

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % size;

    queue[rear] = value;
}

void dequeue()
{
    if (front == -1)
        return;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % size;
}

void display()
{
    if (front == -1)
        return;

    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
}

int main()
{
    int n, m, i, x;

    scanf("%d", &n);
    size = n;

    queue = (int *)malloc(size * sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++)
        dequeue();

    display();

    free(queue);
    return 0;
}
// Day 37
