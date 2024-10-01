#include <stdio.h>
#include <stdlib.h>
#define n 5
int front = -1;
int rear = -1;

void enqueue(int queue[], int x)
{

    if (rear == n - 1)
    {
        printf("queue is overflow\n");
    }
    else if (rear == -1 && front == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void display(int queue[])
{

    if (rear == -1 && front == -1)
    {
        printf("queue is null\n");
    }
    else
    {
        for (int i = front; i < rear + 1; i++)
        {
            printf(" %d\t", queue[i]);
        }
        printf("\n");
    }
}
void dequeue(int queue[])
{
    if (front == -1 && rear == -1)
    {
        printf("queue is null\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}
int main()
{
    int queue[n];
    int x;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    display(queue);
    dequeue(queue);
    display(queue);

    return 0;
}