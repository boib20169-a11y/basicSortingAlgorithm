#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
{
    unsigned int j;
    int i;
    int key;

    for (j = first + 1; j <= last; j++) {

        myCopy(&array[j], &key);   // copy array[j] into key
        i = j - 1;

        while (i >= (int)first && myCompare(array[i], key) > 0) {
            myCopy(&array[i], &array[i + 1]);  // shift right
            i--;
        }

        myCopy(&key, &array[i + 1]); // insert key
    }
}
