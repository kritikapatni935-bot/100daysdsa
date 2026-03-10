// Implement push and pop operations on a stack and verify stack operations.
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    if(top < MAX-1)
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if(top >= 0)
    {
        top--;
    }
}

int main()
{
    int n,m,x,i;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        push(x);
    }

    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        pop();
    }

    for(i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }

    return 0;
}
// Day 33
