/**
 * @brief You will implement the "optimized" quick sort algorithms for a linked list in this file
 */
//You should always comments to each function to describe its PURPOSE and PARAMETERS
#include "sorting.h"

/**
 * Implement a hybrid of insertion sort and quick sort algorithm. The algorithm is based on the idea that if the array is short,
 * it is better to use insertion sort.
 * It uses quicksort until the list gets small enough, and then uses insertion sort or another sort to sort the small lists
 *
 */
void hybridQuickSort(int array[], int lowindex, int highindex, bool reversed) {
    if(lowindex < highindex){                                                   //base case
        if(highindex - lowindex < 10){                                          //if array is small, use
            insertionSort(array, lowindex, highindex, reversed);                //insertionSort
        }
        else{
            int lowendindex = partition(array, lowindex, highindex, reversed);  //if array is larger, recursively
            hybridQuickSort(array, lowindex, lowendindex, reversed);            //call hybridQuickSort
            hybridQuickSort(array, lowendindex+1, highindex, reversed);         //to use quickSort method
        }
    }
}