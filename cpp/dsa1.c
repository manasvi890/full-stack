

#include <stdio.h>

int main()
{
    int i, j, n, temp;
    int arr[20];

    printf("enter number :");
    scanf("%d", &n);

    for (i = 0; i <= n; i++)
    {
        printf("enter elements :");
        printf("%d", &arr[i]);
    }
    printf("rotate array :");
    for (i = 0; i <= n; i++)
    {
        temp = arr[0];
        for (j = 0; j <= n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }

    for (i = 0; i <= n; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}
