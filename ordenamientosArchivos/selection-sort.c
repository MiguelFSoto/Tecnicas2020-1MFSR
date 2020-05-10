#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int checks = 0;
long long int swaps = 0;

void selectionSort(int *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (j =  i + 1; j < n; j++)
        {
            checks++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swaps++;
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main(int argc, char** argv)
{
    printf("Selection Sort\n==============\n");
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

    /*printf("Array: ");
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");*/

    selectionSort(arr, n);

    /*printf("Sorted: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");*/

    printf("Checks: %lld\n", checks);
    printf("Swaps: %lld\n", swaps);

    fclose(f);

    time(&endTime);
    clock_t end = clock();
    printf("End time is %s", ctime(&endTime));
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Difference is %lf seconds", timeSpent);

    return 0;
}