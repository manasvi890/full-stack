#include <stdio.h>
#define size 5
int deque[size];
int f = -1, r = -1;

void insert_front(int x)
{
    if ((f == 0 && r == size - 1) || (f == r + 1))
    {
        printf("Overflow");
    }
    else if ((f == -1) && (r == -1))
    {
        f = r = 0;
        deque[f] = x;
    }
    else if (f == 0)
    {
        f = size - 1;
        deque[f] = x;
    }
    else
    {
        f = f - 1;
        deque[f] = x;
    }
}

void insert_rear(int x)
{
    if ((f == 0 && r == size - 1) || (f == r + 1))
    {
        printf("Overflow");
    }
    else if ((f == -1) && (r == -1))
    {
        r = 0;
        deque[r] = x;
    }
    else if (r == size - 1)
    {
        r = 0;
        deque[r] = x;
    }
    else
    {
        r++;
        deque[r] = x;
    }
}

void display()
{
    int i = f;
    printf("\nElements in a deque are: ");

    while (i != r)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % size;
    }
    printf("%d", deque[r]);
}

void delete_front()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else if (f == r)
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = -1;
        r = -1;
    }
    else if (f == (size - 1))
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = 0;
    }
    else
    {
        printf("\nThe deleted element is %d", deque[f]);
        f = f + 1;
    }
}

void delete_rear()
{
    if ((f == -1) && (r == -1))
    {
        printf("Deque is empty");
    }
    else if (f == r)
    {
        printf("\nThe deleted element is %d", deque[r]);
        f = -1;
        r = -1;
    }
    else if (r == 0)
    {
        printf("\nThe deleted element is %d", deque[r]);
        r = size - 1;
    }
    else
    {
        printf("\nThe deleted element is %d", deque[r]);
        r = r - 1;
    }
}

int main()
{
    insert_front(20);
    insert_front(10);
    insert_front(40);
    display();
    insert_rear(30);
    insert_rear(50);
    insert_rear(80);
    display();
    delete_front();
    delete_rear();
    display();
    return 0;
}