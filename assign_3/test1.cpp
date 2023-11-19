/**
 * This driver file tests the basic implementations of insertion and quick sort for arrays
 */

#include "sorting.h"
#include "print_array.h"

int main() {
    int array[] = {6, 1, 2, 3, 4, 5, 0, -1, -2, -3, -4};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "Original: " ;
    printArray(array, 0, size-1);
    cout << "Insertion sort an array:" << endl;
    insertionSort(array, 0, size-1, false);
    printArray(array, 0, size-1);

    cout << "Insertion sort an array in descending order:" << endl;
    insertionSort(array, 0, size-1, true);
    printArray(array, 0, size-1);
    
    cout << "Quick sort an array: " << endl;
    int array2[] = {6, 1, 2, 3, 4, 5, 0, -1, -2, -3, -4};
    quickSort(array2, 0, size-1);
    printArray(array2, 0, size-1);

    int array3[] = {6, 1, 2, 3, 4, 5, 0, -1, -2, -3, -4};
    cout << "Quick sort an array in descending order:" << endl;
    quickSort(array3, 0, size-1, true);
    printArray(array3, 0, size-1);

    return 0;
}
