/**
 * @brief You will implement the insertion sort and merge sort algorithms for a linked list in this file
 */
//You should always comments to each function to describe its PURPOSE and PARAMETERS

#include "sorting.h"
/**
 * @brief Insertion sort algorithm for linked lists
 * 
 * @param list Input linked list
 * @param reversed if reversed = true, the list should be sorted in descending order, otherwise in ascending order
 * @return LinkedList Sorted linked list
 */
LinkedList insertionSortLL(const LinkedList& list, bool reversed){
    LinkedList sorted;                                                          
    Node* curNode = list.front;                                                 //Node to traverse unsorted list
    int pos = 0;                                                                //position counter to find appropriate position
    sorted.addFront(curNode->val);                                              //add first node from unsorted list to sorted list
    Node* compareNode = sorted.front;                                           //Node to traverse sorted list
    curNode = curNode->next;
    while(curNode != nullptr){
        if(reversed){                                                           //descending order desired
            while(compareNode != nullptr && compareNode->val > curNode->val){   //sorted Node > unsorted Node
                compareNode = compareNode->next;                                //increment sorted Node
                pos++;                                                          //increment position count
            } 
        }
        else{                                                                   //ascending order desired
            while(compareNode != nullptr && curNode->val > compareNode->val){   //unsorted Node > sorted Node
                compareNode = compareNode->next;                                //increment sorted Node
                pos++;                                                          //increment position counter
            }
        }
        sorted.insertAt(pos, curNode->val);                                     //insert unsorted Node at appropriate position in sorted list
        curNode = curNode->next;                                                //increment unsorted Node
        pos = 0;                                                                //reset position count to 0
        compareNode = sorted.front;                                             //reset sorted Node to front
    }
    return sorted;
}

/**
 * @brief Merge sort algorithm for linked lists
 * 
 * @param list Input linked list
 * @param reversed if reversed = true, the list should be sorted in descending order, otherwise in ascending order
 * @return LinkedList Sorted linked list
 */
LinkedList mergeSortLL(const LinkedList& list, bool reversed){
    if(list.length() == 1){                                 //base case
        return list;
    }
    int midpoint = list.length() / 2;                       //find midpoint
    Node* curNode = list.front;                             //Node traversal for list   
    LinkedList lh;                                          //first half of list after split
    LinkedList rh;                                          //second half of list after split
    while(midpoint > 0){                                    //track midpoint to split list in half
        lh.addRear(curNode->val);                           //add each node to lh
        curNode = curNode->next;                            //traverse through list
        midpoint--;
    }
    while(curNode != nullptr){                              //traverse rest of list
        rh.addRear(curNode->val);                           //add each node to rh
        curNode = curNode->next;                            
    }

    LinkedList left = mergeSortLL(lh, reversed);            //recursively call mergeSort until lists of size 1 are returned
    LinkedList right = mergeSortLL(rh, reversed);

    LinkedList sorted;                                      //final sorted LinkedList

    Node* lhNode = left.front;                              //left traversal Node
    Node* rhNode = right.front;                             //right traversal Node
    while(lhNode != nullptr && rhNode != nullptr){          //both traversal Nodes pointing to valid Nodes
        if(reversed){
            if(lhNode->val > rhNode->val){                  
                sorted.addRear(lhNode->val);                //add lhNode to sorted List
                lhNode = lhNode->next;                      //increment lhNode
            }
            else{
                sorted.addRear(rhNode->val);                //add rhNode to sorted List
                rhNode = rhNode->next;                      //increment rhNode
            }
        }
        else{
            if(lhNode->val < rhNode->val){                  
                sorted.addRear(lhNode->val);                //add lhNode to sorted List
                lhNode = lhNode->next;                      //increment lhNode
            }
            else{
                sorted.addRear(rhNode->val);                //add rhNode to sorted List
                rhNode = rhNode->next;                      //increment rhNode
            }
        }
    }
    while(lhNode != nullptr){                               //add remaining Nodes from left to sorted List
        sorted.addRear(lhNode->val);                
        lhNode = lhNode->next;                        
    }   
    while(rhNode != nullptr){                               //add remaining Nodes from right to sorted List
        sorted.addRear(rhNode->val);                    
        rhNode = rhNode->next;   
    }
    return sorted;
}