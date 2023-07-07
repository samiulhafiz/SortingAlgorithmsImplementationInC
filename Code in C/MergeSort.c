#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int leftLength, int right[], int rightLength);

void mergeSort(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int mid = n / 2;
    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((n - mid) * sizeof(int));

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, mid, right, n - mid);

    free(left);
    free(right);
}

void merge(int arr[], int left[], int leftLength, int right[], int rightLength)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < leftLength && j < rightLength)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftLength)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightLength)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

int main()
{
    int arr[] = {85, 75, 82, 92, 41};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, n);

    printf("\nArray after sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

