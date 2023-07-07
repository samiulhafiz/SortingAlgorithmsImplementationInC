#include <stdio.h>

void buildMaxHeap(int arr[], int n);
void heapify(int arr[], int n, int root);
void swap(int* a, int* b);

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapify(int arr[], int n, int root)
{
    int largest = root;
    int left = (2 * root) + 1;
    int right = (2 * root) + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        swap(&arr[root], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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

    heapSort(arr, n);

    printf("\nArray after sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

