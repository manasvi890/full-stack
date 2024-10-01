#include <stdio.h>
#include <stdlib.h>
void bubblesort()
{
    int temp;
    int arr[10];
    int n;
    printf("enter number of array :");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 50 + 1);
        printf("%d\t", arr[i]);
    }
    printf("\nsorted array :\n");
    for (int i = 0; i < n - 1; i++)
    {

        
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {

        printf("%d\t", arr[i]);
    }
}
int main()
{
    bubblesort();
    return 0;
}
