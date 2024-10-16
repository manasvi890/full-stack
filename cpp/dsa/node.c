#include <stdio.h>
struct node
{
    int data;
    char ch;
    struct node *ptr;
};
int main()
{
    struct node x, y, z;

    x.data = 65;
    x.ch = 'A';
    x.ptr = NULL;

    y.data = 90;
    y.ch = 'B';
    y.ptr = NULL;

    z.data = 95;
    z.ch = 'C';
    z.ptr = NULL;

    printf("%d\t%c\t\n", x.data, x.ch);
    printf("%d\t%c\t\n", y.data, y.ch);

    x.ptr = &z;
    y.ptr = &x;
    z.ptr = &y;

    printf("pointer : %d\t%c\t\n", x.ptr->data, x.ptr->ch);
    printf("pointer : %d\t%c\t\n", y.ptr->data, y.ptr->ch);
    printf("pointer : %d\t%c\t\n", z.ptr->data, z.ptr->ch);

    return 0;
}