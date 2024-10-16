

#include <stdio.h>
#define n 4

int addition(int target, int arr[])
{

    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {

                arr[0] = i;
                arr[1] = j;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int target = 9;
    int arr[n] = {2, 7, 11, 15};

    if (addition(target, arr))
    {
        printf("Elements are at positions %d and %d\n", arr[0], arr[1]);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
