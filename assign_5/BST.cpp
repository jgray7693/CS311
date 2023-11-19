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
 * @brief Insert a new element to this BST
 * @param element The new element to insert
 * @return true if the insertion was successful, otherwise false (e.g. duplicate)
 */
bool BST::insert(T element) {
    //allocate new node with data 'element'
    Node* node = new Node(element);
    //if tree is empty, assign new node as the root and increment numElements
    if(root == nullptr){
        root = node;
        numElements++;
        return true;
    }
    Node* curNode = root;
    //iterate through BST until the nullptr is reached
    while(curNode != nullptr){
        if(element < curNode->data){
            //if left subtree is empty, add new node as left child
            if(curNode->leftChild == nullptr){
                curNode->leftChild = node;
                node->parent = curNode;
                numElements++;
                return true;
            }
            else{
                //else, progress down the left subtree
                curNode = curNode->leftChild;
            }
        }
        else{
            //if right subtree is empty, add new node as right child
            if(curNode->rightChild == nullptr){
                curNode->rightChild = node;
                node->parent = curNode;
                numElements++;
                return true;
            }
            else{
                //else, progress down the right subtree
                curNode = curNode->rightChild;
            }
        }
    }
    return false;
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

