/**
 * This file tests the implementation of BST data structure
 * 
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include "BST.h"
#include "assert.h"
using namespace std;

int main() {
    // Initialize a set of random numbers
    int nums[] = {12, -29, -1, 42, 43, -15, 27, 36, -35, 33};
    //unsigned int size = sizeof(nums) / sizeof(nums[0]);
    
    // Insert the random numbers into a BST
    BST bst;
    for(int num : nums) {
        cout << "Inserting " << num << endl;
        bst.insert(num);
    }
    cout << "BST size = " << bst.size() << endl;

   
   // Print out the successors of BST tree nodes
   // staring at the left most node
    BST::Node * node = bst.getLeftMostNode();
    while(node != nullptr) {
        cout << node->data << " has ";
        node = bst.successor(node);
        
        if (node != nullptr) {
            cout << "successor " << node->data << endl;
        } else {
            cout << "no sucessor" << endl;
        }
    }
}