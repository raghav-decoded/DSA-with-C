/* Count Sort
    Algorithm:
        Find the largest element in array 1
        Make an array 2 of size = largest element + 1
        Initialize each block with the value of array 2 as 0
        Iterate on array 1:
            We obtain a value at every iteration
            We increment the index == value in array2[value]++;
        Iterate on array 1:
            When array2 has a value > 0
            Copy [index] in array 1

    Time complexity:
        Size of array = n
        Maximum element(Range) = m
            O(m+n)
        when n>>m
        then, O(n)
    Space complexity:
        O(m)
*/
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}


int maximum(int A[], int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i]){
            max = A[i];
        }
    }
    return max;
    
}
void countSort(int * A, int n){
    int i, j;
    // Find the maximum element in A
    int max = maximum(A, n); 

    // Create the count array
    int* count = (int *) malloc((max+1)*sizeof(int));

    // Initialize the array elements to 0
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0; 
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1; 
    }

    i =0; // counter for count array
    j =0; // counter for given array A

    while(i<= max){
        if(count[i]>0){
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    } 
}

int main(){
    /*
    9 1 4 14 4 15 6
    Largest element = 15
    00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    
    00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15
    00 01 00 00 02 00 01 00 00 01 00 00 00 00 01 01

    9=1 1=4 4=4 14=6 4=9 15=14 6=15
    1 4 4 6 9 14 15
    */ 
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n); 
    return 0;
}
