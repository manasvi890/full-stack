#include <stdio.h>
#define n 5
int front = -1;
int rear = -1;
int dequeue[n];
void insert_front(int x)
{
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
    {
        printf("\ndequeue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        dequeue[front] = x;
    }
    else if (front == 0)
    {
        front = n - 1;
        dequeue[front] = x;
    }
    else
    {
        front = front - 1;
        dequeue[front] = x;
    }
}
void insert_rear(int x)
{
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
    {
        printf("\ndequeue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        rear = 0;
        dequeue[rear] = x;
    }
    else if (rear == n - 1)
    {
        rear = 0;
        dequeue[rear] = x;
    }
    else
    {
        rear++;
        dequeue[rear] = x;
    }
}
void display()
{
    int i = front;
    /* if (front == -1 && rear == -1)
     {
         printf("dequeue is null");
     }*/
    printf("\nElements in a deque are: ");

    while (i != rear)

    {
        printf("%d\t", dequeue[i]);
        i = (i + 1) % n;
    }
    printf("%d\t", dequeue[rear]);
    printf("\n");
}
void delete_front()
{
    if (front == -1 && rear == -1)
    {
        printf("dequeue is empty\n");
    }
    else if (front == rear)
    {
        printf("deleted element is:%d\n", dequeue[front]);
        front = -1;
        rear = -1;
    }
    else if (front == (n - 1))
    {
        printf("deleted element is:%d\n", dequeue[front]);
        front = 0;
    }
    else
    {
        printf("deleted element is:%d\n", dequeue[front]);
        front = front + 1;
    }
}
void delete_rear()
{
    if (front == -1 && rear == -1)
    {
        printf("dequeue is empty\n");
    }
    else if (front == rear)
    {
        printf("deleted element is :%d\n", dequeue[rear]);
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        printf("deleted element is:%d\n", dequeue[rear]);
        rear = n - 1;
    }
    else
    {
        printf("deleted element is:%d\n", dequeue[rear]);
        rear = rear - 1;
    }
}
int main()
{
    insert_front(10);
    insert_front(30);
    insert_front(40);
    display();

    insert_rear(20);
    insert_rear(50);
    insert_rear(60);

    display();
    delete_front();
    delete_rear();
    display();

    return 0;
}
