/**
* @brief Header file for various sorting functions
*/

#ifndef ASSIGN_3_SORTING_H
#define ASSIGN_3_SORTING_H

#include "linkedlist.h"

/**
 * @brief Insertion sort algorithm
 * @param array Array to be sorted. The array is modified in place.
 * @param lowindex Lowest index of the array
 * @param highindex Highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed = false);

/**
 * @brief The partition function used by quick sort 
 * 
 * @param array Array to be partitioned.
 * @param lowindex lowest index of the array
 * @param highindex highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 * @return int The pivot index
 */
int partition(int array[], int lowindex, int highindex, bool reversed);

/**
 * @brief Quick sort algorithm
 * 
 * @param array Array to be sorted. The array is modified in place.
 * @param lowindex Lowest index of the array
 * @param highindex Highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void quickSort(int array[], int lowindex, int highindex, bool reversed = false);

/**
 * @brief Insertion sort algorithm for linked lists
 * 
 * @param list Input linked list
 * @param reversed if reversed = true, the list should be sorted in descending order, otherwise in ascending order
 * @return LinkedList Sorted linked list
 */
LinkedList insertionSortLL(const LinkedList& list, bool reversed = false);

/**
 * @brief Merge sort algorithm for linked lists
 * 
 * @param list Input linked list
 * @param reversed if reversed = true, the list should be sorted in descending order, otherwise in ascending order
 * @return LinkedList Sorted linked list
 */
LinkedList mergeSortLL(const LinkedList& list, bool reversed = false);

/**
 * @brief A hybrid of insertion sort and quick sort algorithm. The algorithm is based on the idea that if the array is short, it is better to use insertion sort.
 * It uses quicksort until the list gets small enough, and then uses insertion sort or another sort to sort the small lists
 * 
 * @param array The array to be sorted. The array is modified in place.
 * @param lowindex The lowest index of the array
 * @param highindex The highest index of the array
 * @param reversed if reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void hybridQuickSort(int array[], int lowindex, int highindex, bool reversed = false);

#endif //ASSIGN_3_SORTING_H
