#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checks = 0;
int swaps = 0;

int isSorted(int* arr, int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        checks++;
        if (arr[i] > arr[i + 1])
            return 0;
    }

    return 1;
}

void shuffle(int* arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        swaps++;
        int randIndex = rand() % n;
        int temp = arr[i];
        arr[i] = arr[randIndex];
        arr[randIndex] = temp;
    }
}

void bogoSort(int* arr, int n)
{
    while(!isSorted(arr, n))
        shuffle(arr, n);
}

int main()
{
    srand(time(0));

    printf("Bogo Sort\n==============\n");
    time_t startTime = time(0);
    time_t endTime;
    clock_t begin = clock();
    printf("Starting time is %s", ctime(&startTime));

    FILE *f = fopen("data.txt", "rb");
    int n;
    fread(&n, sizeof(int), 1, f);

    int orderedArr[n];
    int unorderedArr[n];
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
    bogoSort(orderedArr, n);

    printf("Sorted: ");
    for (i = 0; i < n; i++)
        printf("%d ", orderedArr[i]);
    printf("\n");

    printf("Checks: %d\nSwaps: %d\n", checks, swaps);

    checks = 0;
    swaps = 0;

    printf("\nSorting unordered array\n");
    bogoSort(unorderedArr, n);

    printf("Sorted: ");
    for (i = 0; i < n; i++)
        printf("%d ", unorderedArr[i]);
    printf("\n");

    printf("Checks: %d\nSwaps: %d\n", checks, swaps);

    fclose(f);

    time(&endTime);
    clock_t end = clock();
    printf("End time is %s", ctime(&endTime));
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Difference is %lf seconds", timeSpent);

    return 0;
}