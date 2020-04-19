#include <stdio.h>

void bubbleSort(int* arr, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {4, 3, 1, 5, 2, 7, 6};
    int n = 7;

    bubbleSort(arr, n);
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}