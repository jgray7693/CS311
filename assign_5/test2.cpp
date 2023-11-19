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

/**
 * Test BST class using numbers from standard input
 */
int main() {
    int nums[] = {12, -29, -1, 42, 43, -15, 27, 36, -35, 33};
    unsigned int size = sizeof(nums) / sizeof(nums[0]);

    BST bst;
    
    for(int num : nums) {
        cout << "Inserting " << num << endl;
        bst.insert(num);
        cout << "Height of BST: " << bst.height() << endl;
    }

    cout << "Leftmost value = " << bst.getLeftMostNode()->data << endl;

    // Inorder traversal of the BST
    cout << "Inorder traversal: ";
    bst.printInorder(bst.getRoot());
    cout << endl;
    cout << "BST tree size = " << bst.size() << endl;
    assert(bst.size() == size);
    // Preorder traversal of the BST
    cout << "Preorder traversal: ";
    bst.printPreorder(bst.getRoot());
    cout << endl;
    // check the height of the tree
    cout << "Height of the tree: " << bst.height() << endl;
}
