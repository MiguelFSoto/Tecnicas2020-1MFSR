#include <stdio.h>
#include <time.h>

int checks = 0;
int swaps = 0;

void cocktailSort(int *arr, int n)
{
    int start = 0;
    int end = n - 1;
    int swapped = 1;
    int i;
    while (swapped)
    {
        swapped = 0;
        for(i = 0; i < end; i++)
        {
            checks++;
            if (arr[i] > arr[i + 1])
            {
                swaps++;
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                swapped = 1;
            }
        }
        
        end--;
        if (!swapped)
            break;

        //printf("Backwards\n");
        for (i = end - 2; i > 0; i--)
        {
            checks++;
            if (arr[i] > arr[i + 1])
            {
                swaps++;
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
    printf("Cocktail Shaker Sort\n==============\n");
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
    cocktailSort(orderedArr, n);

    printf("Sorted: ");
    for (i = 0; i < n; i++)
        printf("%d ", orderedArr[i]);
    printf("\n");

    printf("Checks: %d\nSwaps: %d\n", checks, swaps);

    checks = 0;
    swaps = 0;

    printf("\nSorting unordered array\n");
    cocktailSort(unorderedArr, n);

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