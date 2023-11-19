/**
 * @brief The implementation of the Linked List data structure
 */

//- Make sure description and PARAMETER comments are given in detail
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//  Add sufficient comments to your code body to describe what it does.
//      - Make sure all if-then-else are commented describing which case it is
//      - Make sure all local variables are described fully with their purposes

// ====================================================
//Your name: Jason Gray
//Complier:  g++
//File type: linkedList.cpp implementation file
//=====================================================

#include<iostream>
#include"linkedlist.h"

using namespace std;

/**
 * @brief Destructor to destroy all nodes and release memory
 */
LinkedList::~LinkedList() {
    Node* curNode = front;
    while(curNode){                         //while curNode does not point to a nullptr
        Node* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
}

/**
 * @brief Purpose: Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
bool LinkedList::isEmpty() const {
    return (this->count == 0);
} 

/**
 * @brief  Get the number of nodes in the list
 * @return int The number of nodes in the list
 */
int LinkedList::length() const{
    return count;
}

/**
 * @brief Convert the list to a string
 *
 */
string LinkedList::toString() {
    string str = "[";
    Node *ptr = front;
    if (ptr != nullptr) {
        // Head node is not preceded by separator
        str += to_string(ptr->val);
        ptr = ptr->next;
    }
    while (ptr != nullptr) {
        str += ", " + to_string(ptr->val);
        ptr = ptr->next;
    }
    str  += "]";
    return str;
}

/**
 * @brief Displays the contents of the list
 */
void LinkedList::displayAll() {
    cout << toString() << endl;
}

/**
 * @brief Adds a node to the end of the Linked List
 * @param val: value to assign to added Node
 */
void LinkedList::addRear(T val) {
    if(isEmpty()){                          //if list is empty, new node becomes front and rear
        Node* newNode = new Node(val);
        front = newNode;
        rear = newNode;
    }
    else{                                   //if list is not empty, new node only becomes new rear
        Node* newNode = new Node(val);
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

/**
 * @brief Adds a node to the front of the Linked List
 * @param val: value to assign to added Node
 */
void LinkedList::addFront(T val) {
    if(isEmpty()){                          //if list is empty, new node becomes front and rear
        Node* newNode = new Node(val);
        front = newNode;
        rear = newNode;
    }
    else{                                   //if list is not empty, new node only becomes new front
        Node* newNode = new Node(val);
        newNode->next = front;
        front = newNode;
    }
    count++;
} 

/**
 * @brief Deletes the node at the front of the Linked List
 * @param OldNum: set to the value of the Node to be deleted
 * @return true: if the node was deleted successfully
 * @return false: if the node was not deleted successfully because the list was already empty
 */
bool LinkedList::deleteFront(T &OldNum) {
    if(isEmpty()){                          //if list is empty, return false
        return false;
    }
    if(count==1){                           //if list has only 1 node, front and rear need to be reassigned
        Node* delNode = front;
        OldNum = front->val;
        delete delNode;
        front = nullptr;
        rear = nullptr;
    }
    else{                                   //if >1 node, only front pointer needs to be reassigned
        Node* delNode = front;
        OldNum = front->val;
        front = front->next;
        delete delNode;
    }
    count--;
    return true;
} 

/**
 * @brief Deletes the node at the rear of the Linked List
 * @param OldNum: set to the value of the Node to be deleted
 * @return true: if the node was deleted successfully
 * @return false: if the node was not deleted successfully because the list was already empty
 */
bool LinkedList::deleteRear(T &OldNum) {
    if(isEmpty()){                          //if list is empty, return false
        return false;
    }
    if(count==1){                           //if list has only 1 node, front and rear need to be reassigned
        Node* delNode = rear;
        OldNum = rear->val;
        delete delNode;
        front = nullptr;
        rear = nullptr;
    }
    else{                                   //if >1 node, only rear pointer needs to be reassigned
        Node* delNode = rear;
        Node* curNode = front;
        while(curNode->next->next != nullptr){
            curNode = curNode->next;
        }
        OldNum = rear->val;
        delete delNode;
        curNode->next = nullptr;
        rear = curNode;
    }
    count--;
    return true;
} 

/* --- harder ones for test 2 and 3 -- */

/**
     * @brief Delete a node at a given position from the list. The
     * node at position pos is deleted and the value of the deleted node is returned in val.
     * The valid range of pos is 0 to count-1. pos = 0 for the first node, and pos = count-1 for the last node.
     * @param pos: position of the node to be deleted
     * @param val: it is set to the value of the node to be deleted
     * @return true: if the node was deleted successfully
     * @return false: if the node was not deleted successfully because the position was out of range
    */
bool LinkedList::deleteAt(int pos, T &val) {
    // check if the pos is valid first, then move the ptr to the rigth positon
    // consider the special case of deleting the first node and the last node
    // Do not forget to set value.
    if(pos < 0 || pos > count-1){
        return false;
    }
    if(pos==0){
        deleteFront(val);
    }
    else if(pos==(count-1)){
        deleteRear(val);
    }
    else{
        Node* curNode = front;
        for(int i=0; i<pos-1; i++){
            curNode = curNode->next;
        }
        Node* delNode = curNode->next;
        curNode->next = delNode->next;
        val = delNode->val;
        delete delNode;
        count--;
    }
    return true;
}

/**
     * @brief Insert a value at a specified position in the list. The valid pos is in the range of 0 to count.
     * The value will be inserted before the node at the specified position. if pos = 0, the value will be inserted
     * at the front of the list. if pos = count, the value will be inserted at the rear of the list.
     * @param pos: position to insert the value at.
     * @param val: value to insert.
     * @return true: if the value was inserted.
     * @return false: if the value was not inserted because pos is out of the range.
     */
bool LinkedList::insertAt(int pos, T val) {
    if(pos < 0 || pos > count){               //check position in valid range
        return false;
    }
    if(pos==0){                               //if position is at front, use existing function addFront
        addFront(val);
    }
    else if(pos==count){                      //if position is at rear, use existing function addRear
        addRear(val);
    }
    else{                                     //for all other conditions, iterate through until position is reached
        Node* curNode = front;
        for(int i=1; i<pos; i++){
            curNode = curNode->next;
        }
        Node* newNode = new Node(val);
        newNode->next = curNode->next;
        curNode->next = newNode;
        count++;
    }
    return true;

}

/**
 * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
 * @param other LinkedList to be copied
 */
LinkedList::LinkedList(const LinkedList &other) {
    // Start with an empty list
    front = nullptr;
    rear = nullptr;
    count = 0;
    // Iterate through the other list and add a new node to this list
    // for each node in the other list. The new node should have the same value as the other node.
    Node* curNode = other.front;
    while (curNode != nullptr){
        this->addRear(curNode->val);
        curNode = curNode->next;
    }
}

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */
LinkedList &LinkedList::operator=(const LinkedList &other) {
    if(this != &other) {  
        Node* delNode = front;                          // check if the same object
        while(delNode != nullptr){                      //delete all nodes in this list
            front = front->next;
            delete delNode;
            delNode = front;
        }
        front = nullptr;
        rear = nullptr;
        count=0;
        Node* curNode = other.front;
        while (curNode != nullptr){                     //iterate through list to copy, creating new nodes
            this->addRear(curNode->val);                //to add to this list
            curNode = curNode->next;
        }
    }
    return *this;
}


/**
 * Implement the search function.
 * 
 * @return int: the position of the value in the list. If the value is not in the list, return -1.
 */
 int LinkedList::search(const T& val) const {
    int pos = 0;                            //position counter for return output
    Node* curNode = front;                  //assign curNode to first Node in LinkedList
    while(curNode!=nullptr){                //execute while curNode points to a valid node in LinkedList
        if (curNode->val == val){           //if val is found
            return pos;                     //return position of node containing val
        }
        pos++;                              //if val is not found, add 1 to position counter
        curNode = curNode->next;            //and iterate curNode once
    }
    return -1;                              //return -1 if val is not found in LinkedList
}

