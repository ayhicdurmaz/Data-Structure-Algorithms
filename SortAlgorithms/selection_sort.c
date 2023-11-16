#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateRandomArray(int size);
int *selectionSort(int arr[], int size);
void printArray(int arr[], int size);
void arrCpy(int arr1[], int arr2[], int size);

int main()
{
    srand(time(NULL));

    int *arr = generateRandomArray(10);
    int *sorted = selectionSort(arr, 10);

    printArray(arr, 10);
    printArray(sorted, 10);

    return 0;
}

int *generateRandomArray(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    return arr;
}

int *selectionSort(int arr[], int size)
{
    int *sorted = (int *)malloc(size * sizeof(int));
    arrCpy(sorted, arr, size);

    int i, j, temp, tempIndex;

    for (i = 0; i < size; i++)
    {
        temp = sorted[i];
        for (j = i; j < size; j++)
        {
            if (sorted[j] < temp)
            {
                temp = sorted[j];
                tempIndex = j;
            }
        }
        sorted[tempIndex] = sorted[i];
        sorted[i] = temp;
    }

    return sorted;
}

void arrCpy(int arr1[], int arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr1[i] = arr2[i];
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
