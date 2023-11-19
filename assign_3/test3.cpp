/**
 * This file tests the implementation of "optimized" quick sort.
 * It will compare its performance to that of a standard quick sort algorithm
 */
#include "sorting.h"
#include "print_array.h"
#include <chrono>

int main() {
    int array[] = {6, 1, 2, 3, 4, 5, 0, -1, -2, -3, -4};
    int size = sizeof(array) / sizeof(array[0]);
    cout << "Original: ";
    printArray(array, 0, size-1);
    cout << "Hybrid quick sort" << endl;
    hybridQuickSort(array, 0, size-1, false);
    printArray(array, 0, size-1);

    cout << "Reversed hybrid quick sort" << endl;
    hybridQuickSort(array, 0, size-1, true);
    printArray(array, 0, size-1);

    cout << "**** Run Time Tests ****" << endl;
    int array_size = 100000;
    cout << "Array size: " << array_size << endl;
    int* array1 = new int[array_size];
    int* array2 = new int[array_size];
    int* array3 = new int[array_size];
    for (int i = 0; i < array_size; i++) {
        array1[i] = rand() % array_size;
        array2[i] = array1[i];
        array3[i] = array1[i];
    }
    
    // Measure the time for insertion sort
    auto t1 = std::chrono::high_resolution_clock::now();
    insertionSort(array1, 0, array_size-1, false);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> runtime = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "Time for insertion sort: " << runtime.count() << " seconds" << std::endl;

    // Measure the time for quick sort
    t1 = std::chrono::high_resolution_clock::now();
    quickSort(array2, 0, array_size-1, false);
    t2 = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "Time for quick sort: " << runtime.count() << " seconds" << std::endl;

    // Measure the time for hybrid quick sort
    t1 = std::chrono::high_resolution_clock::now();
    hybridQuickSort(array3, 0, array_size-1, false);
    t2 = std::chrono::high_resolution_clock::now();
    runtime = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "Time for hybrid quick sort: " << runtime.count() << " seconds" << std::endl;

    delete[] array1;
    delete[] array2;
    delete[] array3;
}
