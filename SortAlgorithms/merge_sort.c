#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateRandomArray(int size);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void printArray(int arr[], int size);
void arrCpy(int arr1[], int arr2[], int size);

int main()
{
    srand(time(NULL));

    int *arr = generateRandomArray(10);
    int *sorted = (int *)malloc(10 * sizeof(int));
    arrCpy(sorted, arr, 10);

    mergeSort(sorted, 0, (10 - 1));

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

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + (r - 1)) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, (m + 1), r);
        merge(arr, l, m , r);
    }
}

void merge(int arr[], int l, int m, int r){
    
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    i = 0; 
  
    j = 0; 
  
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
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
