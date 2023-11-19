// ====================================================
// Your name: Jason Gray
// Complier:  g++
// File type: htable.cpp implementation file
//=====================================================
#include <fstream>
#include "htable.h"

/**
 * @brief Constructor to create an empty hash table
 * @param size The number of buckets in the hash table
 */
HashTable::HashTable(int size){
	//set table size
	table_size = size;
	//initialize vector with empty Linked Lists
	for(int i=0; i<table_size; i++){
		LinkedList x;
		table.push_back(x);
	}
}

/**
 * @brief Destructor
 */
HashTable::~HashTable(){
	//iterate through every non empty Linked List, deleting all of the orders
	for(int i=0; i<table_size; i++){
		if (!table[i].isEmpty()){
			Order x;
			while(!table[i].isEmpty()){
				table[i].deleteFront(x);
			}
		}
	}
}
/**
 * @brief  Get the hash key of the order
 * @return int The hashed index of the order ID
 */
int HashTable::hash(int id){
	//hash id key based on modulus table size
	return id % table_size;
}

/**
 * @brief Find an order by its ID
 * @param id: the order ID
 * @param order: the reference to stored found order (if found)
 * @return true if found, false otherwise
 */
bool HashTable::findOrder(int id, Order &order){
	//get vector index by hashing id
	int index = hash(id);
	//if index is not empty, iterate through Linked List to find the order
	if(!table[index].isEmpty()){
		//use Node pointer as an iterator
		Node* node = table[index].getFront();
		//while node is not a nullptr, if it is the correct order, return true, otherwise
		//iterate to the next node
		while(node != nullptr){
			if (node->val.id == id){
				order = node->val;
				return true;
			}
			node = node->next;
		}
	}
	//if order not found, return false
	return false;
}

/**
 * @brief Insert an order into the hash table. The order ID is used as the key.
 * A order is inserted only if its ID isn't in the table
 * @return true if inserted, false otherwise
 */
bool HashTable::insertOrder(const Order& order) {
	//get the hash index
	int index = hash(order.id);
	Order temp;
	//if the order doesn't already exist in the hash table, insert the order and return true
	if(!findOrder(order.id, temp)){
		table[index].addRear(order);
		return true;
	}
	//if the order does exist, return false
	return false;
}

/**
 * @brief Load orders from a file
 * @param file_name The name of the file to load
 */
void HashTable::fillTable(string file_name) {
	// Open the file to read
	ifstream fin;
	fin.open(file_name.c_str());
	if (!fin) {
		cout << "Error opening file " << file_name << endl;
		return;
	}
	//make an order variable to gather the information from the file
	Order order;
	while(fin >> order){
		//insert all orders into the hash table
		insertOrder(order);
	}
	//close the file
	fin.close();
}

// 
/**
 * @brief Remove an order from the hash table. The order ID is used as the key.
 *        A order is removed only if its ID is in the table
 * @param id 
 * @return true if the order is removed, false otherwise
 */ 
bool HashTable::removeOrder(int id) {
	//get the hash index
	int index = hash(id);
	Order order;
	//if the order is found, delete the order and return true
	if (findOrder(id, order)){
		return table[index].deleteAt(table[index].search(order), order);
	}
	//otherwise return false
	return false;
	
}

// Display the hash table
void HashTable::printTable() {
	for (int i = 0; i < table_size; i++) {
		cout << "Bucket " << i << ": ";
		table[i].displayAll();
	}
}

/**
 * @brief Get the total number of orders in the hash table
 * @return int The number of orders in the hash table
 */
int HashTable::numOrders() const {
	//make an int variable to calculate the sum
	int sum = 0;
	//for all indexes in the hash table, add the length of the linked list to sum
	for(int i=0; i<table_size; i++){
		sum += table[i].length();
	}
	return sum;
}

/**
 * @brief Update a order in the hash table. The order ID is used as the key.
 * 		  A order is updated only if its ID is in the table
 * @param order the new order that is used to update the old order 
 * @return true if the order is updated, false otherwise
 */
bool HashTable::updateOrder(const Order& order) {
	//get the hash index
	int index = hash(order.id);
	//if the Linked List at index is not empty, iterate until the order is found
	if(!table[index].isEmpty()){
		//use a node pointer as an iterator
		Node* node = table[index].getFront();
		while(node != nullptr){
			//if the order matches, update the order information and return true
			if (node->val.id == order.id){
				node->val.name = order.name;
				node->val.amount = order.amount;
				return true;
			}
			node = node->next;
		}
	}
	//otherwise return false
	return false;
}

/**
 * @brief Rehash the hash table to a new size. The orders are rehashed to the new table
 * @param new_size The new number of buckets in the hash table
 */
void HashTable::rehash(int new_size) {
	//make a new temporary hash table of new_size
	HashTable temp(new_size);
	//go through all the indices of the original hash table
	for(int i=0; i<table_size; i++){
		//use a node pointer as an iterator
		Node* node = table[i].getFront();
		//while node is not null, make an order and add it to the new hash table
		while(node != nullptr){
			//Order order = Order(node->val.id, node->val.name, node->val.amount);
			temp.insertOrder(node->val);
			node = node->next;
		}
		
	}
	//set the original hash table to the newly built and hashed hash table
	table = temp.table;
	table_size = new_size;
}


