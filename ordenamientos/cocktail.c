#include <stdio.h>

void cocktailSort(int *arr, int n)
{
    int start = 0;
    int end = n - 1;
    int swapped = 1;
    int i;
    while (swapped)
    {
        swapped = 0;
        printf("Forward\n");
        for(i = 0; i < end - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                swapped = 1;
            }
        }
        
        end--;
        if (!swapped)
            break;

        printf("Backwards\n");
        for (i = end - 2; i > 0; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                swapped = 1;
            }
        }

        start++;
    }
}

int main()
{
    int arr[] = {4, 3, 1, 5, 2, 7, 6};
    int n = 7;

    cocktailSort(arr, n);
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}