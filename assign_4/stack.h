//CS311 stack.h
//INSTRUCTION:
//Stack class - header file template
//You should always comments to each function to describe its PURPOSE and PARAMETERS

// =======================================================
// Your name: Jason Gray
// Compiler:  g++
// File type: headher file stack.h
// @brief This file defines a Stack class that is implemented using an array
//=======================================================

#pragma once

#include <iostream>
using namespace std;

/**
 * A template Stack class
 */
template <typename T> 
class Stack {
private:
    // data array
    T* array;
    // Number of elements in use
    int count;
    // allocation size of the array, in number of elements
    int allocation_size;

    /**
     * @brief Resize the data array to double its allocation size
     * Make sure to release memory allocation correctly.
     */
    void resizeArray();
public:
    // Constructor
    Stack(int capacity = 4);

    // Destructor
    ~Stack();
    
    // Copy constructor
    Stack(const Stack<T>& stk);

    // Assignment operator
    Stack<T>& operator = (const Stack<T>& stk);

    /**
     * @brief Push a value to the stack.
     * The array will be resized if it reaches its capcity
     * @param val Value to be pushed onto the stack
     */
    void push(const T& val);

    /**
     * @brief If not empty, removes and gives back the top element;
     * @param val variable to receive the popped element (by ref)
     */
    void pop(T& val);

    /**
     * @brief Returns a reference to the top most element of the stack
     * @return reference to top element of the stack
     */
    T& top();

    /**
     * @brief Check if the stack is empty
     * @return true if stack is empty
     */
    bool isEmpty();

    /**
     * @brief Returns the number of elements in the stack
     * @return int the number of elements in the stack
     */
    int size();

    /**
     * @brief Display the content of the stack
     */
    void displayAll();

    /**
     * @brief Clear the stack to make it empty
     */
    void clearAll();
};

template <typename T>
Stack<T>::Stack(int capacity) {
    array = new T[capacity];                    //set array to size capacity
    count = 0;                                  //set count to 0, stack is empty
    allocation_size = capacity;                 //set allocation_size to capacity
}

template <typename T>
Stack<T>::~Stack() {
    delete[] array;                             //delete array allocated in memory
}

// @brief Copy constructor
template <typename T>
Stack<T>::Stack(const Stack<T>& stk) {
    count = stk.count;                          
    array = new T[count];                       //allocate a new array of size count
    allocation_size = count;                    
    for(int i=0; i<stk.count; i++){             //copy all elements of other array to this array
        array[i] = stk.array[i];
    }
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& stk) {
    if(this != &stk){                           //check that this Stack is not the same as other Stack
        delete[] array;                         //deallocate existing array
        count = stk.count;                      
        array = new T[count];                   //allocate a new array of size count
        allocation_size = count;                
        for(int i=0; i<stk.count; i++){         //copy all elements of other array to this array
            this->array[i] = stk.array[i];  
        }
    }
    return *this;                               //return this Stack
}

// : Add implementation of remaining Stack functions.
// For a template class, the implementation should be included in the header file.

/**
 * @brief Resize the data array to double its allocation size
 * Make sure to release memory allocation correctly.
 */
template <typename T>
void Stack<T>::resizeArray() {
    T* new_array = new T[allocation_size * 2];  //create a new array with double the capacity
    for (int i = 0; i <= count; i++) {          //copy all elements from existing array
        new_array[i] = array[i];
    }
    allocation_size *= 2;
    delete[] array;                             //deallocate existing array
    array = new_array;                          //reassign array to new array
}

/**
 * @brief Push a value to the stack.
 * The array will be resized if it reaches its capcity
 * @param val Value to be pushed onto the stack
 */
template <typename T>
void Stack<T>::push(const T& val) {
   if(allocation_size == count){                //if array is full, resize
    resizeArray();
   }
   array[count] = val;                          //add element to next open spot in array
   count++;                                     
}

/**
 * @brief If not empty, removes and gives back the top element;
 * @param val variable to receive the popped element (by ref)
 */
template <typename T>
void Stack<T>::pop(T& val) {
    if(!isEmpty()){                             //ensure Stack is not empty
        val = array[count-1];                   //update val argument with element to be removed
        count--;                                //decrement count, "removing" the top element
    }
}

/**
 * @brief Returns a reference to the top most element of the stack
 * @return reference to top element of the stack
 */
template <typename T>
T& Stack<T>::top() {
    return array[count-1];                      //return the element at the top of the Stack
}

/**
 * @brief Check if the stack is empty
 * @return true if stack is empty
 */
template <typename T>
bool Stack<T>::isEmpty() {
    return (count == 0);                        
}

/**
 * @brief Returns the number of elements in the stack
 * @return int the number of elements in the stack
 */
template <typename T>
int Stack<T>::size() {
    return count;
}

/**
 * @brief Display the content of the stack
 */
template <typename T>
void Stack<T>::displayAll() {
    if (count == 0) {
        cout << "Stack is empty" << endl;
    } else {
        for (int i = 0; i < count; i++) {       //iterate through array and print each element value
            cout << array[i] << " ";
        }
        cout << endl;
    }
}

/**
 * @brief Clear the stack to make it empty
 */
template <typename T>
void Stack<T>::clearAll() {
    count = 0;                                  //"remove" all elements by setting count to 0
}

