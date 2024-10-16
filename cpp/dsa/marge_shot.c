#include <stdio.h>
int i, j, k;
void marge(int arr[], int lb, int mid, int ub)
{
    i = lb;
    j = mid + 1;
    k = lb;
    int arr1[50];
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            arr1[k] = arr[i];
            i++;
        }
        else
        {
            arr1[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            arr1[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            arr1[k] = arr[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++)
    {
        arr[k] = arr1[k];
        // printf("%d\t", arr[k]);
    }
}

void margeshot(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        margeshot(arr, lb, mid);
        margeshot(arr, mid + 1, ub);
        printf("call\n");
        marge(arr, lb, mid, ub);
    }
}
int main()
{
    int arr[5] = {10, 5, 90, 1, 15};
    for (int v = 0; v < 5; v++)
    {
        printf("%d\t", arr[v]);
    }
    printf("\n");
    margeshot(arr, 0, 4);
    for (int v = 0; v < 5; v++)
    {
        printf("%d\t", arr[v]);
    }
    return 0;
}