#include <stdio.h>
#include <stdlib.h>

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
        if (left[leftIndex] < right[rightIndex])
            finalArr[mainIndex++] = left[leftIndex++];
        else
            finalArr[mainIndex++] = right[rightIndex++];
    }

    if (leftIndex < leftN)
    {
        while (leftIndex < leftN)
            finalArr[mainIndex++] = left[leftIndex++];
    }
    if (rightIndex < rightN)
    {
        while (rightIndex < rightN)
            finalArr[mainIndex++] = right[rightIndex++];
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

int main()
{
    int arr[] = {4, 3, 1, 5, 2, 7, 6};
    int n = 7;
    int* sortedArr = mergeSort(arr, n);

    int i;
    for (i = 0; i < n; i++)
        printf("%d ", sortedArr[i]);
    printf("\n");

    return 0;
}