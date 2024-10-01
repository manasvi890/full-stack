#include <stdio.h>
#define n 5
int rear = -1;
int front = -1;

void enqueue(int queue[], int x)
{
    if (rear == n - 1)
    {
        printf("queue is full");
    }
    else if (front == -1 && rear == -1)
    {
        rear = front = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % n;
        queue[rear] = x;
    }
}
void display(int queue[])
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("queue is null");
    }

    else
    {

        while (i != rear)

        {
            printf("%d\t", queue[i]);
            i = (i + 1) % n;
        }
        printf("%d\t", queue[rear]);
    }
    printf("\n");
}
void dequeue(int queue[])
{
    int x;
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
        front = (front + 1) % n;
        queue[front];
    }
}
int main()
{
    int queue[n];
    int x;
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    enqueue(queue, 50);
    display(queue);
    dequeue(queue);
    display(queue);
}