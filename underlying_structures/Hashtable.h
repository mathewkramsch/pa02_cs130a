// Hashtable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Minheap.h"
#include "node.h"
#include <utility>

class Minheap;

class Hashtable {
	// Hash table using seperate chaining, implemented as array of nodes
	
	public:
		Hashtable();
		~Hashtable();
		Minheap *heapLink;

		// PUBLIC METHODS
		node* insert(int i);
		node* lookup(int i);
		std::pair<int,int> deleteItem(int i);
		std::pair<int,int> deleteMin();
		void print();
		void setLink(node *n);
	
		node* *hashArray;  // array of pointers to the head of a linkedlist of nodes

	private:
		int size;

};

#endif
