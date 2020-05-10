#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int checks = 0;
long long int swaps = 0;

int* slice(int* arr, int start, int end)
{
    int* subArr = malloc(sizeof(int) * (end - start));
    int index = 0;

    int i;
    for (i = start; i < end; i++)
        subArr[index++] = arr[i];

    return subArr;
}

int* merge(int* left, int* right, int leftN, int rightN)
{
    int *finalArr = malloc(sizeof(int) * (leftN + rightN));

    int mainIndex = 0;
    int leftIndex = 0;
    int rightIndex = 0;
    while (leftIndex < leftN && rightIndex < rightN)
    {
        checks++;
        swaps++;
        if (left[leftIndex] < right[rightIndex])
            finalArr[mainIndex++] = left[leftIndex++];
        else
            finalArr[mainIndex++] = right[rightIndex++];
    }

    if (leftIndex < leftN)
    {
        while (leftIndex < leftN)
        {
            swaps++;
            finalArr[mainIndex++] = left[leftIndex++];
        }
    }
    if (rightIndex < rightN)
    {
        while (rightIndex < rightN)
        {
            swaps++;
            finalArr[mainIndex++] = right[rightIndex++];
        }
    }

    return finalArr;
}

int* mergeSort(int* arr, int n)
{
    int mid = n / 2;
    int* left = slice(arr, 0, mid);
    int* right = slice(arr, mid, n);

    if (n > 1)
    {
        left = mergeSort(left, mid);
        right = mergeSort(right, n - mid);
        return merge(left, right, mid, n - mid);
    }
    else
        return arr;
}

int main(int argc, char** argv)
{
    printf("Merge Sort\n==============\n");
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

    arr = mergeSort(arr, n);

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