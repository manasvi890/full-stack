#include <stdio.h>
#include <stdlib.h>
int val;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void insert_end(int val)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return;
}
void delete_end()
{
    struct node *ptr = head;
    struct node *p;
    if (head->next == NULL)
    {
        head = NULL;
        free(ptr);
        return;
    }
    while (ptr->next != NULL)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
    return;
}

void insert_first(int val)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = head;
    head = temp;
}
void delete_first()
{
    struct node *ptr = head;
    head = ptr->next;
    free(ptr);
}
void insert_mid(int num, int pos)
{
    struct node *ptr = head;
    struct node *p;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;

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
void display()
{
    struct node *ptr = head;

    if (head == NULL)
    {
        printf("list is null");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}
int main()
{
    int n, num, pos;

    do
    {
        printf("1. Insert at end\n");
        printf("2. Delete from end\n");
        printf("3. Insert after a value\n");
        printf("4. Delete a value\n");
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
            scanf("%d", &num);
            insert_end(num);
            break;

        case 2:
            delete_end();
            break;

        case 3:
            printf("Enter element to insert and the value after which to insert: ");
            scanf("%d %d", &num, &pos);
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
