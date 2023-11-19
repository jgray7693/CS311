// You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.
//

#include <iostream>
#include "linkedlist.h"
#include <stdlib.h>

using namespace std;

//@brief to test copy constructor which gets called automatically when passed as a parameter.
// Adds 6 to the rear of the copiedList and displays the list.
//PARAMETER: list passed by value becomes copiedList via your copy constructor
void CopyTest(LinkedList copiedList) {
    cout << "In copy test function, an element 6 is added to the copied list" << endl;
    copiedList.addRear(6);
    copiedList.displayAll();
    //cout << "finished" << endl;
}

//PURPOSE of the Program: to test LinkedList thoroughly
int main() {
    cout << "Test 3: ------- Copy Constructor and assignment operator = -------" << endl;
    LinkedList L1, L2; // two lists needed
    int x;        // local for removed element
    int counter=1;  // local for counter

    //1. Create a 5 element list with  [1,2,3,4,5] (L1)
    cout << "Step 1: " << "Create a 5 element list L1 = [1,2,3,4,5] " << endl;
    for(int i = 1; i <= 5; i++) {
        L1.addRear(i);
    }
    cout << "L1: ";
    L1.displayAll();   // 1 2 3 4 5

    //2. Simply pass L1  to a client function called CopyTest to
    //test your copy constructor.
    cout << "Step 2: " << "pass L1  to a client function called CopyTest to test your copy constructor" << endl;
    CopyTest(L1);

    cout << "After copytest, the original shouldn't change " << endl;

    //3. Display L1 (this should still be a 5 element list)
    cout << "Step 3: " << "Display L1 (this should still be a 5 element list)" << endl;
    counter++;
    cout << "L1: ";
    L1.displayAll();

    //cout << "-- Testing operator overloading ---" << endl;

    //4. Do L1 = L1;
    cout << "Step 4: " << " Assigning a list to itself shouldn't change it" << endl;
    L1 = L1;
    cout << "L1: ";
    L1.displayAll();

    //5. Create a 4 element list L2 with 7,8,9,10.
    cout << "Step 5: " << "Create a 4 element list L2 with 7,8,9,10." << endl;
    for(int i = 7; i <= 10; i++) {
        L2.addRear(i);
    }
    cout << "L2: ";
    L2.displayAll();

    //6. Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
    cout << "Step 6: " << " L2 = L1, (L2 becomes 5 elements 1,2,3,4,5)" << endl;
    L2 = L1;
    cout << "L2: ";
    L2.displayAll();

    //7. Remove a rear node from L1. (This should not affect L2).
    cout << "Step 7: " << "Remove a rear node from L1. (This should not affect L2)" << endl;
    L1.deleteRear(x);
    cout << "L1 :";
    L1.displayAll();
    cout << "L2: ";
    L2.displayAll();

    // 8. Test copy constructor
    cout << "Step 8: " << "Test the copy constructor" << endl;
    cout << "L1 :";
    L1.displayAll();
    // L3 is copy of L1 and should have the same content
    LinkedList L3(L1);
    cout << "L3: ";
    L3.displayAll();
}


