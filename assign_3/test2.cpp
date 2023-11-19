/**
 * This driver file tests the implementation of insertion and merge sort for linked lists
 */

#include "sorting.h"
#include "print_array.h"


int main() {
    LinkedList list;/*
    list.addRear(1);
    list.addRear(2);
    list.addRear(3);
    list.addRear(4);
    list.addRear(5);
    list.addRear(0);
    list.addRear(-1);
    list.addRear(-2);
    list.addRear(-3);
    list.addRear(-4);
    */
    list.addRear(6);
    list.addRear(3);
    list.addRear(2);
    list.addRear(4);
    list.addRear(5);
    list.addRear(0);
    list.addRear(-2);
    list.addRear(-3);
    list.addRear(-5);
    list.addRear(-4);
    cout << "Original: " << endl;
    list.displayAll();
    cout << "Insertion sort linked list: " << endl;
    LinkedList sortedList1 = insertionSortLL(list);
    sortedList1.displayAll();

    cout << "Insertion sort linked list in descending order: " << endl;
    sortedList1 = insertionSortLL(list, true);
    sortedList1.displayAll();

    cout << "\noriginal: ";
    list.displayAll();
    cout << "Merge sort linked list: " << endl;
    LinkedList sortedList2 = mergeSortLL(list);
    sortedList2.displayAll();

    cout << "merge sort linked list in descending order: " << endl;
    sortedList2 = mergeSortLL(list, true);
    sortedList2.displayAll();
    return 0;
}
