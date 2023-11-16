#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateRandomArray(int size);
int *insertionSort(int arr[], int size);
void printArray(int arr[], int size);
void arrCpy(int arr1[], int arr2[], int size);

int main()
{
    srand(time(NULL));

    int* arr = generateRandomArray(10);
    int* sorted = insertionSort(arr, 10);

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

int *insertionSort(int arr[], int size)
{
    int* sorted = (int*) malloc(size * sizeof(int));
    arrCpy(sorted, arr, size);
    

    int i, j, key = 0;

    for (i = 0; i < size; i++)
    {
        key = sorted[i];
        for (j = i - 1; j >= 0 && key <= sorted[j]; j--)
        {
            sorted[j + 1] = sorted[j];
        }
        sorted[j + 1] = key;
    }
    return sorted;
}

void arrCpy(int arr1[], int arr2[], int size){
    for(int i = 0; i < size; i++){
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
