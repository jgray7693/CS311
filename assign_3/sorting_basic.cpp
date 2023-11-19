/**
 * Implemention of selected sorting algorithms
 * @file sorting.cpp
 */

#include "sorting.h"

/**
 * @brief Insertion sort algorithm
 * @param array Array to be sorted. The array is modified in place.
 * @param lowindex Lowest index of the array
 * @param highindex Highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 */
void insertionSort(int array[], int lowindex, int highindex, bool reversed) {
    if (reversed){                                          //descending order desired
        int j = highindex - 1;
        int temp = 0;
        for(int i = highindex-1; i >= lowindex; i--){       //traverse array backwards
            j=i;
            while(j < highindex && array[j] < array[j+1]){  //while array elements are "unsorted"
                temp = array[j];                            //swap numbers in array[j] and array[j+1]
                array[j] = array[j+1];
                array[j+1] = temp;
                j++;
            }
        }
    }
    else{                                                   //ascending order desired
        int j = lowindex + 1;
        int temp = 0;
        for(int i = lowindex+1; i <= highindex; i++){       //traverse array forwards
            j=i;
            while(j>lowindex && array[j] < array[j-1]){     //while array elements are "unsorted"
                temp = array[j];                            //swap numbers in array[j] and array[j-1]
                array[j] = array[j-1];
                array[j-1] = temp;
                j--;
            }
        }
    }
}

/**
 * @brief The partition function used by quick sort 
 * 
 * @param array Array to be partitioned.
 * @param lowindex lowest index of the array
 * @param highindex highest index of the array
 * @param reversed If reversed = true, the array should be sorted in descending order, otherwise in ascending order
 * @return int The pivot index
 */
int partition(int array[], int lowindex, int highindex, bool reversed) {
    int pivot = array[lowindex];                //set pivot to first element in array
    bool done = false;
    int temp = 0;
    while(!done){       
        if(reversed){                           //descending order desired
            while(array[lowindex] > pivot){     //while low elements are > pivot
                lowindex++;                     //increment lowindex
            }
            while(array[highindex] < pivot){    //while high elements are < pivot
                highindex--;                    //decrement highindex
            }
        }       
        else{                                   //ascending order desired
            while(array[lowindex] < pivot){     //while low elements are < pivot
                lowindex++;                     //increment lowindex
            }
            while(array[highindex] > pivot){    //while high elements are > pivot
                highindex--;                    //decrement highindex
            }
        }
        if(lowindex >= highindex){              //perform until lowindex >= highindex
            done = true;
        }
        else{                                   
            temp = array[lowindex];             //swap low and high index elements
            array[lowindex] = array[highindex];
            array[highindex] = temp;
            lowindex++;
            highindex--;
        }
    }
    return highindex;                           
}

/**
 * @brief Insertion sort algorithm for linked lists
 * 
 * @param list Input linked list
 * @param reversed if reversed = true, the list should be sorted in descending order, otherwise in ascending order
 * @return LinkedList Sorted linked list
 */
void quickSort(int array[], int lowindex, int highindex, bool reversed) {
    if(lowindex < highindex){                                               //base case
        int lowendindex = partition(array, lowindex, highindex, reversed);  //find partition
        quickSort(array, lowindex, lowendindex, reversed);                  //recursively call quicksort, splitting
        quickSort(array, lowendindex+1, highindex, reversed);               //array in 2 halves each time
    }
}