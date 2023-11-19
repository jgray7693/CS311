// You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//

#include <iostream>
#include "linkedlist.h"
#include <stdlib.h>

using namespace std;

//PURPOSE of the Program: to test the union and merge functions of LinkedList
int main() {
    cout << "Test the union and merge operations on linked lists" << endl;
    LinkedList L1, L2; // two lists needed
    

    //1. Create a 4 element list with  [3, 5, 8, 11] (L1)
    L1.addRear(3);
    L1.addRear(5);
    L1.addRear(8);
    L1.addRear(11);
    cout << "L1: ";
    L1.displayAll();

    //2. Create a 6 element list with [2, 6, 8, 9, 22, 24]
    L2.addRear(2);
    L2.addRear(6);
    L2.addRear(8);
    L2.addRear(9);
    L2.addRear(22);
    L2.addRear(24);
    cout << "L2: ";
    L2.displayAll();


    //3. Test the union function
    cout << "-- Testing the union function ---" << endl;
    LinkedList L3 = unionLinkedList(L1, L2);
    cout << "Union: ";
    L3.displayAll();

    //4. Test the merge function
    cout << "-- Testing the union function ---" << endl;
    cout << "Merged: ";
    LinkedList L4 = mergeLinkedList(L1, L2);
    L4.displayAll();

}


