#include <stdio.h>

#define n 7
int binarysearch(int arr[], int low, int high)
{

    int mid;
    int x;
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\nenter number you want to find :");
    scanf("%d", &x);

    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[n] = {2, 5, 10, 15, 35, 45, 50};

    int index = binarysearch(arr, 0, n - 1);

    if (index == -1)
    {
        printf("element not found");
    }
    else
    {
        printf("element is in %d position", index);
    }
    return 0;
}
