/* Insertion Sort
    Based on our choice(ascending/descending) we check if key if smaller/greater than the elements in the first section.

    Algorithm: 
        The array is divided into two parts.
        The first element of the second section is the key.
        The first section is sorted by default.
        Iterate:
        In the first array :
            We start iterating from left-to-right
            if key is smaller than the element: 
                we copy its value to the index(shifting) following the element
            else if the key is greater than the element
                we place key at index of the element

    Stable = Yes
    Recursive = No
    Adaptive = Yes
    Intermediate Result is not useful.

    Total Passes = n-1
    Total comparisons = 1+2+3+...+(n-1) = n(n-1)/2 = (n^2/2)-(n/2) = O(n^2)
    Time Complexity:
    Worst Case = O(n^2)
    Best Case: O(n)
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

void insertionSort(int *A, int n)
{
    int key, j;
    // Loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i]; // The key element starts from 1-n
        j = i - 1;  // j index is behind key

        // Loop for each pass
        while (j >= 0 && A[j] > key) // Is the key smaller than A[j] ?
        {
            A[j + 1] = A[j]; // if yes then the A[j] gets copied to the location next to it
            j--;             // Looking for other elements smaller than A[j]
        }

        A[j + 1] = key; // Putting key behind the element greater in value 
    }
}

int main()
{
    // -1   0    1   2   3   4   5
    //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
    //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

    //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
    //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

    //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
    //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
    //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
    //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
    //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

    // Fast forwarding and 4th and 5th pass will give:
    //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
    //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

    //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
    //      07, 09, 12, 23, 54, 65| --> After the 5th pass

    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n);
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}
