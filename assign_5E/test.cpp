/**
 * This file tests the implementation of BST data structure
 * 
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include <vector>
#include "BST.h"
using namespace std;

/**
 * Test BST class using numbers from standard input
 */
int main() {
    // randomly sample a bunch of integers
    //srand(time(NULL));
    srand(1);

    // Generate 20 random numbers
    unordered_set<int> nums;
    while(nums.size() < 20) {
        nums.insert((rand() % 100) - 50);
    } 

    // create and populate BST
    BST bst;
    unsigned int count = 0;
    for(int num : nums) {
        cout << "Inserting " << num << endl;
        bst.insert(num);
        //bst.printInorder(bst.getRoot());
        //cout << bst.size() << endl;
        if(bst.size() != ++count) {
            cout << "Incorrect tree size" << endl;
            return 1;
        }
        cout << "tree: ";
        bst.printInorder(bst.getRoot()); cout << endl;
        // print balance factor of nodes
        cout << "balance factor: ";
        bst.printBalanceFactors(bst.getRoot());
        cout << endl;
    }

    for(int num : nums) {
        // remove a node
        cout << "Removing " << num << endl;
        bst.remove(num);
        //bst.printInorder(bst.getRoot());
        //cout << bst.size() << endl;
    
        cout << "tree: ";
        bst.printInorder(bst.getRoot());
        cout << endl;
        cout << "balance factor: ";
        bst.printBalanceFactors(bst.getRoot());
        cout << endl;
    }
 
    // if it didn't fail yet, success!
    cout << endl << "Success" << endl;
    return 0;
}
