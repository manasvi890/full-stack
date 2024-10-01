/*#include <stdio.h>
int main()
{
    int size = 5;
    int arr[] = {1, 2, 3, 4, 5};
    int i;
    int temp;

    for (i = 0; i < size; i++)
    {
        printf("enter element of position:");
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < size; i++)
    {
        printf("  %d", arr[i]);
    }

    printf("\n");
    temp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;

    printf("after swap: ");
    for (i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }

    return 0;
}*/

#include <stdio.h>

int main()
{
    int size = 5;
    int arr[] = {1, 2, 3, 4, 5}; // Declare the array with the given size
    int i;
    int temp;

    // Input elements from the user

    // Display original array
    printf("Original array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Rotate the array
    temp = arr[size - 1]; // Save the last element
    for (i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1]; // Shift elements to the right
    }
    arr[0] = temp; // Place the last element at the front

    // Display the rotated array
    printf("After rotation: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
