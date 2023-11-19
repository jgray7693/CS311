/**
 * @brief Implementation of unionLinkedList and mergeLinkedList functions
 */

#include "linkedlist.h"

/**
    * @brief Assume two linked lists that represent Set A and Set B respectively.
    * Compute the union A U B and return the result as a new linked list.
    *
    * @param LA Input linkedlist A as a set (no duplicated element)
    * @param LB Input linkedlist B as a set (no duplicated element)
    * @return LinkedList return the unioned linkedlist 
    */
LinkedList unionLinkedList(const LinkedList& LA, const LinkedList& LB) {
    LinkedList c(LA);                               //copy LinkedList LA into new LinkedList c
    Node* curNode = LB.front;                       //assign curNode to first Node in LB
    while(curNode != nullptr){                      //execute while curNode does not point to nullptr
        if(c.search(curNode->val) == -1){           //if c does not contain the value of curNode
            c.addRear(curNode->val);                //append curNode to c
        }
        curNode = curNode->next;                    //iterate curNode once
    }
    return c;                                       //return unioned LinkedList c
}

/**
     * @brief Assume two input linked lists, LA and LB, whose elements are both in the non-descending order.
     * This function merges LA and LB into a new linked list (as the return value).
     * The elements in the new list should still be in the non-descending order.
     *
     * @param LA
     * @param LB
     * @return LinkedList
     */
LinkedList mergeLinkedList(const LinkedList& LA, const LinkedList& LB) {
    LinkedList c;                                   //create a new empty LinkedList c
    Node* aNode = LA.front;                         //assign aNode to first Node in LA
    Node* bNode = LB.front;                         //assign bNode to first Node in LB
    while(aNode != nullptr && bNode != nullptr){    //execute while aNode or bNode does not point to nullptr
        if(aNode->val <= bNode->val){               //if value of aNode <= value of bNode
            c.addRear(aNode->val);                  //append aNode to c
            aNode = aNode->next;                    //iterate aNode once
        }
        else{
            c.addRear(bNode->val);                  //if bNode < aNode, append bNode to c
            bNode = bNode->next;                    //iterate bNode once
        }
    }                                               //at conclusion, either LA or LB will be fully traversed

    while(aNode != nullptr){                        //execute while aNode does not point to nullptr
        c.addRear(aNode->val);                      //append aNode to c
        aNode = aNode->next;                        //iterate aNode once
    }   

    while(bNode != nullptr){                        //execute while bNode does not point to nullptr
        c.addRear(bNode->val);                      //append bNode to c
        bNode = bNode->next;                        //iterate bNode once
    }
    return c;                                       //return merged LinkedList c
}