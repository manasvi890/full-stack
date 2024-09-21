#include <stdio.h>
#define n 5
int stack[n];
int top = -1;

void push()
{

    if (top == n - 1)
    {
        printf("stack is full");
    }
    else
    {
        top = top + 1;
     
        printf("enter record :");
        scanf("%d", &stack[top]);
    }
}

void display()
{
    if (top < 0)
    {
        printf("stack is null");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("\t %d", stack[i]);
        }
        printf("\n");
    }
}
void pop()
{

    if (top == -1)
    {
        printf("stack is null");
    }
    else
    {
        top = top - 1;
    }
}

int main()
{
    push();
    push();
    push();
    push();
    push();
    display();
    pop();
    display();
    return 0;
}