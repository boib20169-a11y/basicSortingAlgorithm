
#include "mySort.h"
#include <limits.h>

/* Helper function to merge two halves of the array */
void merge(int array[], unsigned int first, unsigned int mid, unsigned int last)
{
    unsigned int n1 = mid - first + 1;
    unsigned int n2 = last - mid;

    int L[MAX_SIZE_N_TO_SORT];
    int R[MAX_SIZE_N_TO_SORT];

    /* Fill left array */
    for (unsigned int i = 0; i < n1; i++) {
        myCopy(&array[first + i], &L[i]);
    }

    /* Fill right array */
    for (unsigned int j = 0; j < n2; j++) {
        myCopy(&array[mid + 1 + j], &R[j]);
    }

    /* Sentinel values (∞) */
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    unsigned int i = 0;
    unsigned int j = 0;

    /* Merge with a for loop */
    for (unsigned int k = first; k <= last; k++) {
        if (myCompare(L[i], R[j]) <= 0   ) {
            myCopy(&L[i], &array[k]);
            i++;
        } else {
            myCopy(&R[j], &array[k]);
            j++;
        }
    }
}

/* Recursive merge sort */
void mySort(int array[], unsigned int first, unsigned int last)
{
    if (first < last) {
        unsigned int mid = first + (last - first) / 2;

        mySort(array, first, mid);
        mySort(array, mid + 1, last);
        merge(array, first, mid, last);
    }
}
