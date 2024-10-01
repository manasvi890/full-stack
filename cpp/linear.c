#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return the index of the target element
        }
    }
    return -1; // Return -1 if the target is not found
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\nEnter the element to search: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    if (result != -1)
    {
        printf("Element %d found at index %d\n", target, result);
    }
    else
    {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
