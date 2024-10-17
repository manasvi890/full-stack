#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

void insert_end(int num)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = num;
    temp->next = head;

    if (head == NULL && tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}
void delete_end()
{
    struct node *ptr = tail;
    struct node *p = head;
    if (head == NULL)
    {
        printf("\n\nthe list is already empty");
    }
    if (head == tail)
    {
        head = tail = NULL;
        return;
    }
    while (p->next != tail)
    {
        p = p->next;
    }
    p->next = head;
    tail = p;
    free(ptr);
}
void insert_mid(int num, int pos)
{
    struct node *ptr = head;
    struct node *p;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = num;

    while (ptr->data != pos)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = temp;
    temp->next = ptr;
}
void delete_mid(int pos)
{
    struct node *ptr = head;
    struct node *p;
    while (ptr->data != pos)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = ptr->next;
    free(ptr);
}
void insert_first(int num)
{

    struct node *temp = malloc(sizeof(struct node));
    temp->data = num;
    temp->next = head;
    head = temp;
    tail->next = head;
}
void delete_first()
{
    if (head == NULL)
    {
        printf("\n\nthe list is already empty");
    }
    if (head == tail)
    {
        head = tail = NULL;
        return;
    }
    struct node *ptr = head;
    head = head->next;
    tail->next = head;
    free(ptr);
}
void display()
{
    struct node *ptr = head;
    printf("\n");
    if (head == NULL)
    {
        printf("the list is already empty");
    }
    else
    {
        while (ptr != tail)
        {
            printf("%d", ptr->data);
            ptr = ptr->next;
        }
        printf("%d", ptr->data);
        printf("\n");
    }
}
int main()
{
    int n, num, pos;

    do
    {
        printf("1. Insert at end\n");
        printf("2. Delete from end\n");
        printf("3. Insert mid\n");
        printf("4. Delete mid\n");
        printf("5. Insert at beginning\n");
        printf("6. Delete from beginning\n");
        printf("7. Display\n");
        printf("0. Terminate\n\n");

        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter element to insert at end: ");
            scanf("%d\t", &num);
            insert_end(num);
            break;

        case 2:
            delete_end();
            break;

        case 3:
            printf("Enter element to insert :");
            scanf("%d", &num);
            printf("enter position :");
            scanf("%d", &pos);
            insert_mid(num, pos);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &pos);
            delete_mid(pos);
            break;

        case 5:
            printf("Enter element to insert at beginning: ");
            scanf("%d", &num);
            insert_first(num);
            break;

        case 6:
            delete_first();
            break;

        case 7:
            display();
            break;

        case 0:
            printf("Terminating program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (n != 0);

    return 0;
}
