/*#include <stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    printf("rotated array :\n%d\n%d\n%d\n%d\n%d", arr[4], arr[1], arr[2], arr[3], arr[0]);

    return 0;
}

#include <stdio.h>

void rotateLeft(int arr[], int size)
{
    if (size <= 1)
        return; // No rotation needed for arrays of size 0 or 1

    int first = arr[0]; // Store the first element

    // Shift all elements to the left
    for (int i = 1; i < size; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[size - 1] = first; // Move the first element to the end
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5; // Manually define the size of the array

    printf("Original Array: ");
    printArray(arr, size);

    rotateLeft(arr, size); // Rotate the array to the left

    printf("Rotated Array: ");
    printArray(arr, size);

    return 0;
}*/

#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n;

        printf("rotated array :");
    for (int i = 0; i <= 5; i++)
    {
        arr[i] = arr[(i + 1) % n];
    }
    for (int i = 0; i <= 5; i++)
    {
        printf("%d", arr[i]);
    }

    printf("\n");

    return 0;
}