/* Merge Sort
    Type: Divide and Conquer Algorithm

    Algorithm:
    Divide the array two sections.
    low-mid and mid-high
    Make a new array of size 
    Iterate:
        Compare first element of section 1 and 2
        Put the lower/higher (ascending/descending) element in the second array
    Iterate:
        Put remaining elements from section 1 and 2 into the second array
    Copy elements of second array into the first array.

    Time Complexity:
        Best/Worst/Avg. Case = O(nlog(n))
    Space Complexity:
        O(n)
*/
#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    { // There are atleast 2 elements in the array.
        mid = (low + high) / 2;
        mergeSort(A, low, mid); // tree left side
        mergeSort(A, mid + 1, high); // tree right side
        merge(A, mid, low, high); //Final tree gets merged.
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, 6);
    printArray(A, n);
    return 0;
}
