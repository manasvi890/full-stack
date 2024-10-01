#include <stdio.h>
#include <stdlib.h>
#define n 5
void selectionsort()
{
    int arr[n];
    int small;
    int temp;
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 50 + 1);
        printf("%d\t", arr[i]);
    }
    printf("\nsorted array :\n");
    for (int i = 0; i < n - 1; i++)
    {
        small = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[small])
            {
                small = j;
            }
        }
        temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}
int main()
{
    selectionsort();

    return 0;
}