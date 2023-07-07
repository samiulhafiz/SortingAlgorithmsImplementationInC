#include <stdio.h>

void countSort(int arr[], int n, int exp);
int findMax(int arr[], int n);

void radixSort(int arr[], int n)
{
    int max = findMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
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

    radixSort(arr, n);

    printf("\nArray after sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

