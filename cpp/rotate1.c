#include <stdio.h>
void leftRotate(int arr[], int n)
{
    int temp;

    temp = arr[0];
    for (int j = 0; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
    arr[n - 1] = temp;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("Original Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    leftRotate(arr, n);
    printf("\nRotated Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

/*#include <stdio.h>
int main()
{
    int size = 5;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("enter element of position:");
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        printf("  %d", arr[i]);
    }
    printf("\n");

    int temp = arr[0];
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = temp;
    printf("after swap:");
    for (int i = 0; i < size; i++)
    {
        printf("  %d", arr[i]);
    }
    return 0;
}*/