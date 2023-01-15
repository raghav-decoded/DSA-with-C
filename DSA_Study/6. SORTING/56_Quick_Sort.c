/* Quick Sort
    Idea: Elements on the left of pivot are smaller and on its right are larger
    Algorithm:
        We put elements lower than pivot on its left and higher than pivot on its right.
        Partition:
            We pick the low element.
            We pick a high element.
            Pivot = Low
            Until i<j repeat:
                i++ until element greater than pivot is found (L->R)
                j-- until element less than pivot is found (L<-R)
                Swap ith and jth 
            Swap Pivot and A[j]

    Time Complexity:
        Best Case = O(nlog(n))
        Avg. Case = O(nlog(n))
        Worst Case = O(n^2)
    Space Complexity:
        Best Case = O(log(n))
        Worst Case = O(n)
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

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    printf("%d %d %d %d\n", i, j, low, high);
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition
    //for j at the end the condition will be false
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        // printf("%d %d %d\n", partitionIndex, low, high);
        quickSort(A, low, partitionIndex - 1);  // sort left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    // (9) i4 4 8 7 5 j6 Start
    // (9) 4 i4 8 7 5 j6 i++
    // (9) 4 i6 8 7 5 j4 Swap
    // (9) 4 6 i8 7 5 j4 i++
    // (9) 4 6 i4 7 5 j8 Swap
    // (9) 4 6 4 i7 5 j8 i++
    // (9) 4 6 4 i8 5 j7 Swap
    // (9) 4 6 4 8 i5 j7 i++
    // (9) 4 6 4 8 i7 j5 Swap
    // (9) 4 6 4 8 7 ij5 i++
    // (5) 4 6 4 8 7 ij9 Final, return j=7
    // Sort [5 4 6 4 8 7] and [9]
              
    int n = 9;
    n = 7;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}
