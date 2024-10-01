#include <stdio.h>
#include <stdlib.h>
#define n 5

int arr[n];
int number;

void linearsearch()
{
    for (int i = 0; i <= n; i++)
    {
        arr[i] = (rand() % 50 + 1);
        printf("%d\t", arr[i]);
    }
}

int main()
{
    int index = 0;
    linearsearch();
    printf("enter element to search :");
    scanf("%d", &number);
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == number)
        {
            printf("number is :%d", arr[i]);
            index = 1;
            break;
        }
    }

    if (index == 0)
    {

        printf("number not found ");
    }

    return 0;
}