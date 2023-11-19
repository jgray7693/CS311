#include "heap.h"

// @brief gets the maximum value in the heap
// @return the highest value integer in the heap
T Heap::getMax() const {
    return heaparray[0];
}


// @brief default constructor. Construct an empty heap with initial capacity
Heap::Heap(int capacity) {
    count = 0;
    this->capacity = capacity;
    heaparray = new T[capacity];
}

// @brief destructor
Heap::~Heap() {
    //deallocate heaparray
    delete[] heaparray;
    count = 0;
    capacity = 0;
}

/**
 * @brief constructor to build a heap from an array of values
 * @param values array of values to be added to the heap
 * @param length the size of the array
 */
Heap::Heap(T *values, int length) {
    count = 0;
    //allocate a new array of size length
    heaparray = new T[length];
    capacity = length;
    //copy all elements from input array into heaparray
    for(int i=0; i<length; i++){
        heaparray[i] = values[i];
        count++;        
    }
    //heapify all elements of the heaparray
    heapify();
}

 /**
 * @brief Copy constructor
 * @param other the heap to be copied
 */
Heap::Heap(const Heap &other) {
    capacity = other.capacity;
    count = other.count;
    //allocate new array of size capacity
    heaparray = new T[capacity];
    //copy all elements from other array to this array
    for(int i=0; i<count; i++){
        heaparray[i] = other.heaparray[i];
    }
}

/**
* @brief Assignment operator
* @param other the heap to be copied
* @return Heap& a reference to the heap
*/
Heap & Heap::operator=(const Heap &other) {
    if(this != &other){
        //deallocate current array
        delete[] heaparray;
        this->capacity = other.capacity;
        this->count = other.count;
        //allocate new array of size capacity
        heaparray = new T[capacity];
        //copy all elements from other array to this array
        for(int i=0; i<count; i++){
            heaparray[i] = other.heaparray[i];
        }
    }
    return *this;
}


/**
 * @brief   organizes the values in the heap to satisfy heap property.
 */
void Heap::heapify() {
    //starting at lowest internal node, percolateDown and move up the array to the root
    for(int i=(count/2) - 1; i>=0; i--){
        percolateDown(i);
    }
}

/**
 * @brief  Runs percolate down on the heap for the node stored in index.
 * @param index the index of the item to percolateDown
 */
void Heap::percolateDown(int index) {
    //initialize lChild, rChild, and current indices for comparison
    int lChild = (index * 2) + 1;
    int rChild = (index * 2) + 2;
    int largeIndex = index;

    //Verify lChild index is not out of bounds, and check if lChild value > largeIndex value
    if(lChild < count && heaparray[lChild] > heaparray[largeIndex]){
        largeIndex = lChild;
    }
    //verify rChild index is not out of bounds, and check if rChild value > largeIndex value
    if(rChild < count && heaparray[rChild] > heaparray[largeIndex]){
        largeIndex = rChild;
    }
    //if index == largeIndex, percolateDown is complete
    //otherwise, swap index and largeIndex and recursively call percolateDown
    if(index != largeIndex){
        swap(index, largeIndex);
        percolateDown(largeIndex);
    }
}

/**
 * @brief  Runs percolate up on the heap for the node stored in index.
 * @param index the index of the item to percolateUp
 */
void Heap::percolateUp(int index) {
    //Base Case: if index is the root, percolateUp is complete
    if(index == 0){
        return;
    }
    int parent = (index - 1) / 2;
    //if index value > parent value, swap and recursively call percolateUp
    if(heaparray[index] > heaparray[parent]){
        swap(index, parent);
        percolateUp(parent);
    }
}

/**
 * @brief  inserts a value into the heap
 * @param value the value of the element to be added
 */
void Heap::insert(T value) {
    //if array is full, resize array to *2 capacity
    if(count == capacity){
        capacity = capacity * 2;
        //initialize a new array with double the capacity
        T* temp = new T[capacity];
        //copy old array into the new array
        for(int i=0; i<count; i++){
            temp[i] = heaparray[i];
        }
        //deallocate old array from memory
        delete[] heaparray;
        //assign new array
        heaparray = temp;
    }
    //insert the new element at next available slot in the array, and percolate up
    heaparray[count] = value;
    percolateUp(count);
    count++;
}

/**
 * @brief  Removes the max value from the heap
 * @return the value that was removed
 */
T Heap::removeMax() {
    //store Max element to return
    T max = heaparray[0];
    count--;
    //swap first and last elements in the array
    swap(0,count);
    //percolate down the newly replaced root
    percolateDown(0);
    return max;
}

//@brief converts the heap into a string
string Heap::toString()
{
    string s = "[ ";
    for (int i = 0; i < count; i++)
    {
        s += to_string(heaparray[i]) + " ";
    }
    s += "]";
    return s;
}

/**
 * @brief  Prints the values in the heap
 */
void Heap::printHeap() {
    cout << toString() << endl;
}

/**
 * @brief  Prints the values in an array
 */
void printArray(int values[], int length) {
    int i;
    cout << "[ ";
    for (i = 0; i < length; i++) {
        cout << values[i] << " ";
    }
    cout << "]\n";
}

/**
 * @brief  Swaps the values in the heap at index1 and index2
 * @param index1 index of the first value to be swapped
 * @param index2 index of the second value to be swapped
 */
void Heap::swap(int index1, int index2) {
    T temp = heaparray[index1];
    heaparray[index1] = heaparray[index2];
    heaparray[index2] = temp;
}

/**
 * @brief  Sorts the values of an array by using the heap
 * @param values an array of unsorted elements
 * @param length the length of the values array
 */
void heapSort(T values[], int length) {
    cout << "Array Before Sorting: \n";
    printArray(values, length);
    //initialize a new Heap using the given array
    //this accomplishes the task of heapifying the array
    Heap heap = Heap(values, length);
    //remove every max element from the heap, and add them to the array in reverse order
    for(int i=length-1; i>=0; i--){
        values[i] = heap.removeMax();
    }

    cout << "Array After Sorting: \n";
    printArray(values, length);

    return;
}

/**
     * @brief Change the key of the element at position i to the new value. 
     * It maintains the heap property.
     * @param i the position of the element to be decreased
     * @param value the new value
     */
void Heap::changeKey(int i, T new_val) {
    //obtain old value for comparison use
    T oldVal = heaparray[i];
    heaparray[i] = new_val;
    //if new value is smaller, only need to check downwards
    if(new_val < oldVal){
        percolateDown(i);
    }
    //otherwise, check upwards
    else{
        percolateUp(i);
    }
}
