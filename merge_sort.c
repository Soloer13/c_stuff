/*
MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:
             middle m = (l+r)/2
     2. Call mergeSort for first half:
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
*/




#include<stdlib.h>
#include<stdio.h>


// min is for left index and max is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int min, int max)
{
    if (min < max)
    {
        // Same as (min+max)/2
        int mid = (min +(max - 1)) / 2;

        // Sort first and second halves
        mergeSort(arr, min, mid);
        mergeSort(arr, mid+1, max);

        merge(arr, min, mid, max);
    }
}


// Merges two sub-arrays of arr[].
void merge(int arr[], int min, int mid, int max)
{
    //define variables would be used in loops later
    int i, j, k;

    //define size of the sub-arrays (the left and right)
    int n1 = mid - min +1 ;
    int n2 =  max - mid;

    //create temp arrays
    int Left[n1], Right[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        Left[i] = arr[min + i];
    for (j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 +j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = min; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

	/* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}



/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
