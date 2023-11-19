// You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

#include <iostream>
#include "linkedlist.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "*** Test 1: Basic functions *** " << endl;
    LinkedList L;   // creat a new empty list
    int x;     // to hold a removed element

    //1 check empty and report the result
    cout << "Step 1: check empty and report the result" << endl;
    if (L.isEmpty()) cout << "It is empty" << endl;
    else cout << "It is not empty" << endl;

    //2 display the list
    cout << "Step 2: display the list" << endl;
    L.displayAll();

    //3 add 4 integers to rear 1,2,3,4
    cout << "Step 3: " << " adding 1 2 3 4" << endl;
    L.addRear(1);
    L.addRear(2);
    L.addRear(3);
    L.addRear(4);

    //4 display the list
    cout << "Step 4: " << "display the list" << endl;
    L.displayAll();

    //5 remove from front twice using x (and display the elements removed)
    cout << "Step 5: " << " delete Front twice" << endl;
    L.deleteFront(x);
    cout << "Removed: " << x << endl;
    L.deleteFront(x);
    cout << "Removed: " << x << endl;

    //6 display the list
    cout << "Step 6: " << "display the list" << endl;
    L.displayAll();

    //7 check empty and report the result
    cout << "Step 7: " << "check empty and report the result" << endl;
    if (L.isEmpty()) cout << "It is empty" << endl;
    else cout << "It is not empty" << endl;

    //8 remove from the rear twice using x (display the elements removed)
    cout << "Step 8: " << " deleteRear twice" << endl;
    L.deleteRear(x);
    cout << "Removed: " << x << endl;
    L.displayAll();  // this is needed to make sure your end is NULL
    L.deleteRear(x);
    cout << "Removed: " << x << endl;

    //9 check empty again and report the result
    cout << "Step 9: " << "check empty again and report the result" << endl;
    if (L.isEmpty()) cout << "It is empty" << endl;
    else cout << "It is not empty" << endl;

    // 10 add to front 4 times (elements 9, 8, 6, 5)
    cout << "Step 10: " << "add to front 4 times (elements 9, 8, 6, 5)" << endl;
    L.addFront(9);
    L.addFront(8);
    L.addFront(6);
    L.addFront(5);

    // 11.display the list
    cout << "Step 11: " << "display the list" << endl;
    L.displayAll();

    // 12.remove from the rear 4 times (display the elements removed)
    cout << "Step 12: " <<  "remove from the rear 4 times (display the elements removed)" << endl;
    L.deleteRear(x);
    cout << "Removed: " << x << endl;
    L.deleteRear(x);
    cout << "Removed: " << x << endl;
    L.deleteRear(x);
    cout << "Removed: " << x << endl;
    L.deleteRear(x);
    cout << "Removed: " << x << endl;

    //  13.display the list again
    cout << "Step 13: " << "display the list again" << endl;
    L.displayAll();

}//end of test case 1 

