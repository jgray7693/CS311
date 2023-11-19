/**
 * Implementation of BST class.
 */
//You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: Jason Gray
// Compiler:  g++
// File type: cpp file BST.cpp
// @brief This class implements a BST search tree
//=======================================================

#include "BST.h"
#include <vector>
#include <iostream>

/**
 * @brief BST default constructor. Set root Node to nullptr and numElements to 0. An empty BST.
 */ 
BST::BST() {   
    root = nullptr;
    numElements = 0;
}

/**
 * @brief BST Destructor, calls clear, deleting all nodes and deallocting them
 */
BST::~BST() {
    clear();
}

/**
 * @brief Return the number of elements in the BST
 * @return The number of elements in the BST
 */
unsigned int BST::size() const {
    return numElements;
}

/**
 * @brief Remove all elements from the BST and deallocate all nodes using Clear helper function
 */
void BST::clear() {
    clear(root);
    root = nullptr;
    numElements = 0;
}

/**
 * @brief Delete all nodes starting at the node called in the argument
 * @param node a pointer to a node in the BST
 */
void BST::clear(Node* node) {
    if(node == nullptr){
        return;
    }
    else{
        //recursively clear all left and right subtrees of node
        clear(node->leftChild);
        clear(node->rightChild);
    }
    delete node;
}
/**
 * @brief Find a query element in this BST
 * @param query The query element to find
 * @return true if query exists in this BST, otherwise false
 */
bool BST::find(const T &query) const {
    //start iteration at the root node
    Node* curNode = root;
    //iterate through BST until the nullptr is reached
    while(curNode != nullptr){
        //if query is found in a node, return true
        if(curNode->data == query){
            return true;
        }
        //if node data > query, progress down left subtree
        else if(curNode->data > query){
            curNode = curNode->leftChild;
        }
        //else, progress down right subtree
        else{
            curNode = curNode->rightChild;
        }
    }
    //if nullptr is reached, query was not found in BST, return false
    return false;
}

/**
 * @brief Return the maximum height of the BST using height helper function. Root is at height 0
 * @return The height of the BST
 */
int BST::height() const {
    return height(root);
}

/**
 * @brief Return the height of the BST starting at input node. input node is at height 0
 * @param node a pointer to a node in the BST
 * @return The height of the BST starting at node
 */
int BST::height(Node* node) const{
    if (node == nullptr) {
        return -1;
    }
    //recursively call height on left and right subtrees
    int leftHeight = height(node->leftChild);
    int rightHeight = height(node->rightChild);
    //return the max size of left and right subtrees + 1
    return 1 + std::max(leftHeight, rightHeight);
}

/**
 * @brief Return pointer to the root node of the BST
 * @return The root node of the BST. nullptr if the BST is empty
 */
BST::Node* BST::getRoot() {
    return root;
}

/**
 * @brief Print the subtree at node using inorder traversal
 * @param node a pointer to node in BST
 */
void BST::printInorder(Node* node) {
    //recursively iterate through left subtree, then visit the node, then recursively iterate through right subtree
    if(node != nullptr){
        printInorder(node->leftChild);
        std::cout << node->data << " ";
        printInorder(node->rightChild);
    }
}

/**
* @brief Print the subtree at node using preorder traversal
* @param node a pointer to node in BST
*/
void BST::printPreorder(Node* node) {
    //visit the node, then recursively iterate through left subtree, then recursively iterate through right subtree
    if(node != nullptr){
        std::cout << node->data << " ";
        printInorder(node->leftChild);
        printInorder(node->rightChild);
    }
}

/**
* @brief Print the subtree at node using postorder traversal
* @param node a pointer to node in BST
*/
void BST::printPostorder(Node* node) {
    //recursively iterate through left subtree, then recursively iterate through right subtree, then visit the node
    if(node != nullptr){
        printInorder(node->leftChild);
        printInorder(node->rightChild);
        std::cout << node->data << " ";
    }
}

/**
 * @brief Return pointer to the left-most node in this BST
 * @return The left-most node in this BST
 */
BST::Node* BST::getLeftMostNode(){
    return getLeftMostNode(root);
}

/**
 * @brief Return the left-most node of a subtree rooted at the node
 * @param node a pointer to a node in the BST
 * @return a pointer to the leftmost node
 */
BST::Node *BST::getLeftMostNode(Node* node) {
    Node* curNode = node;
    //iterate through left subtree until the left child is nullptr then return that pointer
    while(curNode->leftChild != nullptr){
        curNode = curNode->leftChild;
    }
    return curNode;
}

/**
 * @brief Find the successor of this Node in the BST
 * @param node The node to find the successor of
 * @return Node* Pointer to the successor of this Node, or nullptr if none exists
 */
BST::Node *BST::successor(Node *node) {
    Node* curNode = node;
    //if node has a right subtree, return the leftmost node of the right subtree
    if(curNode->rightChild != nullptr){
        curNode = curNode->rightChild;
        return getLeftMostNode(curNode);
    }
    //else, return the furthest ancestor that has node in its right subtree
    else{
        while(curNode->parent != nullptr && curNode->parent->rightChild == curNode){
            curNode = curNode->parent;
        }
        return curNode->parent;
    }
}
/**
 * Implement insert() correctly. Rebalance the tree if necessary
 */
bool BST::insert(T element) {
    Node* node = new Node(element);
    // Check if tree is empty
    if (root == nullptr) {
        root = node;
    }
    else {
        // Step 1 - do a regular binary search tree insert.
        Node* currentNode = root;
        while (currentNode) {
            // Choose to go left or right
            if (element < currentNode->data) {
                // Go left. If left child is null, insert the new
                // node here.
                if (currentNode->leftChild == nullptr) {
                    currentNode->leftChild = node;
                    node->parent = currentNode;
                    currentNode = nullptr;
                }
                else {
                    // Go left and do the loop again.
                    currentNode = currentNode->leftChild;
                }
            }
            else {
                // Go right. If the right child is null, insert the
                // new node here.
                if (currentNode->rightChild == nullptr) {
                    currentNode->rightChild = node;
                    node->parent = currentNode;
                    currentNode = nullptr;
                }
                else {
                    // Go right and do the loop again.
                    currentNode = currentNode->rightChild;
                }
            }
        }

        // Step 2 - Rebalance along a path from the new node's parent up
        // to the root.
        node = node->parent;
        while (node) {
            rebalance(node);
            node = node->parent;
        }
    }
    numElements++;
    return true;
}

/**
 * Implement remove() correctly. Rebalance the tree if necessary
 */
bool BST::remove(T element) {
    Node* curNode = root;
    Node* node = nullptr;
    while(curNode != nullptr){
        if(element == curNode->data){
            node = curNode;
            curNode = nullptr;
        }
        else if(element < curNode->data){
            curNode = curNode->leftChild;
        }
        else{
            curNode = curNode->rightChild;
        }
    }
    if(node == nullptr){
        return false;
    }
    numElements--;
    return removeNode(node);
}

bool BST::removeNode(Node* node){
    // Parent needed for rebalancing.
    Node* parent = node->parent;

    // Case 1: Internal node with 2 children
    if (node->leftChild && node->rightChild) {
        // Find successor
        Node* successorNode = node->rightChild;
        while (successorNode->leftChild) {
            successorNode = successorNode->leftChild;
        }

        // Copy the value from the node
        node->data = successorNode->data;

        // Recursively remove successor
        removeNode(successorNode);

        // Nothing left to do since the recursive call will have rebalanced
        return true;
    }

    // Case 2: Root node (with 1 or 0 children)
    else if (node == root) {
        if (node->leftChild) {
            root = node->leftChild;
        }
        else {
            root = node->rightChild;
        }

        if (root) {
            root->parent = nullptr;
        }

        delete node;
        return true;
    }

    // Case 3: Internal with left child only
    else if (node->leftChild) {
        replaceChild(node, node->leftChild, parent);
    }

    // Case 4: Internal with right child only OR leaf
    else {
        replaceChild(node, node->rightChild, parent);
    }

    // nodeToRemove is removed from the tree and can be deleted
    delete node;

    // Anything that was below nodeToRemove that has persisted is already 
    // correctly balanced, but ancestors of nodeToRemove may need rebalancing.
    Node* nodeToRebalance = parent;
    while (nodeToRebalance) {
    rebalance(nodeToRebalance);         
        nodeToRebalance = nodeToRebalance->parent;
    }
    return true;
}

/**
 * Implement the rebalance() function correctly
 */
void BST::rebalance(Node *node) {
    updateHeight(node);
    if(balanceFactor(node) == -2){
        if(balanceFactor(node->rightChild) == 1){
            rotateRight(node->rightChild);
        }
        rotateLeft(node);
    }
    else if(balanceFactor(node) == 2){
        if(balanceFactor(node->leftChild) == -1){
            rotateLeft(node->leftChild);
        }
        rotateRight(node);
    }
}

/**
 * Implement the rotateLeft() function correctly
 */
void BST::rotateLeft(Node *node) {
    // Define a convenience pointer to the right child of the 
    // left child.
    Node* rightLeftChild = node->rightChild->leftChild;

    // Step 1 - the right child moves up to the node's position.
    // node is temporarily detached from the tree, but will be reattached
    // later.
    if (node->parent) {
        replaceChild(node, node->rightChild, node->parent);
    }
    else { // node is root
        root = node->rightChild;
        root->parent = nullptr;
    }

    // Step 2 - the node becomes the left child of what used
    // to be node's right child, but is now node's parent. This will
    // detach rightLeftChild from the tree.
    setChild(true, node, node->rightChild);

    // Step 3 - reattach rightLeftChild as the right child of node.
    setChild(false, rightLeftChild, node);
}

/**
 * Implement the rotateRight() function correctly
 */
void BST::rotateRight(Node *node) {
    // Define a convenience pointer to the left child of the 
    // right child.
    Node* leftRightChild = node->leftChild->rightChild;

    // Step 1 - the left child moves up to the node's position.
    // node is temporarily detached from the tree, but will be reattached
    // later.
    if (node->parent != nullptr) {
        replaceChild(node, node->leftChild, node->parent);
    }
    else { // node is root
        root = node->leftChild;
        root->parent = nullptr;
    }

    // Step 2 - the node becomes the right child of what used
    // to be node's left child, but is now node's parent. This will
    // detach leftRightChild from the tree.
    setChild(false, node, node->leftChild);

    // Step 3 - reattach leftRightChild as the right child of node.
    setChild(true, leftRightChild, node);
}

// Compute the balance factor of a node
int BST::balanceFactor(Node *node) {
    int leftHeight = -1;
    int rightHeight = -1;
    if(node->leftChild){
        leftHeight = node->leftChild->height;
    }
    if(node->rightChild){
        rightHeight = node->rightChild->height;
    }
    return (leftHeight - rightHeight);
}

// Print the balance factor of each node in the subtree rooted at node
void BST::printBalanceFactors(Node *node) {
    if (node == nullptr) {
        return;
    }
    printBalanceFactors(node->leftChild);
    std::cout << balanceFactor(node) << " ";
    printBalanceFactors(node->rightChild);
}

void BST::updateHeight(Node* node){
    int leftHeight = -1;
    int rightHeight = -1;
    if(node->leftChild){
        leftHeight = node->leftChild->height;
    }
    if(node->rightChild){
        rightHeight = node->rightChild->height;
    }
    node->height = 1 + std::max(leftHeight, rightHeight);
}

bool BST::setChild(bool left, Node* child, Node* node) {
    // Assign the left or right data member.
    if (left) {
        node->leftChild = child;
    }
    else {
        node->rightChild = child;
    }

    // Assign the parent data member of the new child,
    // if the child is not null.
    if (child) {
        child->parent = node;
    }

    // Update the node's height, since the subtree's structure
    // may have changed.
    updateHeight(node);
    return true;
}

bool BST::replaceChild(Node* currentChild, Node* newChild, Node* node){
    if (node->leftChild == currentChild) {
        return setChild(true, newChild, node);
    }
    else if (node->rightChild == currentChild) {
        return setChild(false, newChild, node);
    }
    // If neither of the above cases applied, then the new child
    // could not be attached to this node.
    return false;
}