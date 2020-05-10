#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checks = 0;
int swaps = 0;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quiuqSort(int* arr, int start, int pivot)
{
    if (start < pivot)
    {
        int i = -1;
        int j;

        for (j = 0; j < pivot; j++)
        {
            checks++;
            if (arr[j] < arr[pivot])
            {
                i++;
                swaps++;
                swap(&arr[j], &arr[i]);
            }
        }

        i++;
        swaps++;
        swap(&arr[i], &arr[pivot]);

        quiuqSort(arr, start, i - 1);
        quiuqSort(arr, i + 1, pivot);
    }
}

int main(int argc, char** argv)
{
    printf("Quiuq Sort\n==============\n");
    time_t startTime = time(0);
    time_t endTime;
    clock_t begin = clock();
    printf("Starting time is %s", ctime(&startTime));

    FILE *f = fopen(argv[1], "rb");
    int n;
    fread(&n, sizeof(int), 1, f);

    /*int* orderedArr = malloc(sizeof(int) * n);
    int* unorderedArr = malloc(sizeof(int) * n);
    fread(orderedArr, sizeof(int) * n, 1, f);
    fread(unorderedArr, sizeof(int) * n, 1, f);

    int i;
    printf("Ordered: ");
    for (i = 0; i < n; i++)
        printf("%d ", orderedArr[i]);
    printf("\n");
    printf("Unordered: ");
    for (i = 0; i < n; i++)
        printf("%d ", unorderedArr[i]);
    printf("\n");

    printf("\nSorting ordered array\n");
    bubbleSort(orderedArr, n);

    printf("Sorted: ");
    for (i = 0; i < n; i++)
        printf("%d ", orderedArr[i]);
    printf("\n");

    printf("Checks: %d\nSwaps: %d\n", checks, swaps);

    checks = 0;
    swaps = 0;

    printf("\nSorting unordered array\n");
    bubbleSort(unorderedArr, n);

    printf("Sorted: ");
    for (i = 0; i < n; i++)
        printf("%d ", unorderedArr[i]);
    printf("\n");

    printf("Checks: %d\nSwaps: %d\n", checks, swaps);*/

    int *arr = malloc(sizeof(int) * n);
    fread(arr, sizeof(int) * n, 1, f);

    printf("Array: ");
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quiuqSort(arr, 0, n - 1);

    printf("Sorted: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    fclose(f);

    time(&endTime);
    clock_t end = clock();
    printf("End time is %s", ctime(&endTime));
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Difference is %lf seconds", timeSpent);

    return 0;
}