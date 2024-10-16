#include <stdio.h>
int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    int temp;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    /*
    for (int i = 0; i < 5; i++)
     {
         printf("%d\t", arr[i]);
     }
     printf("sort\n");
     */
    return end;
}
void quicksort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int local = partition(arr, lb, ub);
        quicksort(arr, lb, local - 1);
        quicksort(arr, local + 1, ub);
    }
}
int main()
{
    int arr[5] = {10, 5, 2, 70, 30};
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    quicksort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}