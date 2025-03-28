#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
void insert_end(int val)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
        head->next = head;
        head->prev = head;
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
        temp->next = head;
        head->prev = temp;
    }
}
void delete_end()
{
    struct node *ptr = head;
    struct node *p;

    if (head->next == head)
    {
        head = NULL;
        free(ptr);
    }
    else
    {
        while (ptr->next != head)
        {
            p = ptr;
            ptr = ptr->next;
        }
        p->next = head;
        head->prev = p;
        free(ptr);
    }
}

void insert_first(int num)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));

    temp->data = num;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
        head->next = head;
        head->prev = head;
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
        temp->next = ptr;
        ptr->prev = temp;
    }
}

void delete_first()
{
    struct node *ptr = head;
    struct node *p = head;

    if (head->next == head)
    {
        head = NULL;
        free(ptr);
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        head = head->next;
        ptr->next = head;
        head->prev = ptr;
        free(p);
    }
}

void insert_mid(int val, int pos)
{
    struct node *ptr = head;
    struct node *p;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    while (ptr->data != pos)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = temp;
    temp->prev = p;
    temp->next = ptr;
    ptr->prev = temp;
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
    ptr->next->prev = p;
    free(ptr);
}

void display()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("list is already null");
    }
    else
    {
        while (ptr->next != head)
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
    int n, val, pos;

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
            scanf("%d\t", &val);
            insert_end(val);
            break;

        case 2:
            delete_end();
            break;

        case 3:
            printf("Enter element to insert :");
            scanf("%d", &val);
            // printf("enter position :");
            // scanf("%d", &pos);
            insert_mid(val, pos);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &pos);
            delete_mid(pos);
            break;

        case 5:
            printf("Enter element to insert at beginning: ");
            scanf("%d", &val);
            insert_first(val);
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