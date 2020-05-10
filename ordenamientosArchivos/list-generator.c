#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void save(int arr[], int n, FILE* f)
{
    fwrite(&n, sizeof(int), 1, f);
    fwrite(arr, sizeof(int) * n, 1, f);
}

int main()
{
    srand(time(0));
    FILE *f1 = fopen("ordered.txt", "wb");
    FILE *f2 = fopen("unordered.txt", "wb");

    int n;
    printf("Size: ");
    scanf("%d", &n);
    
    int* orderedArr = malloc(sizeof(int) * n);
    int* unorderedArr = malloc(sizeof(int) * n);

    printf("Generating lists\n");
    int i;
    for (i = 0; i < n; i++)
    {
        orderedArr[i] = i + 1;
        unorderedArr[i] = i + 1;
    }

    printf("Shuffling\n");
    for (i = 0; i < n; i++)
    {
        int randIndex = rand() % n;
        int temp = unorderedArr[i];
        unorderedArr[i] = unorderedArr[randIndex];
        unorderedArr[randIndex] = temp;
    }

    save(orderedArr, n, f1);
    save(unorderedArr, n, f2);

    fclose(f1);
    fclose(f2);

    return 0;
}