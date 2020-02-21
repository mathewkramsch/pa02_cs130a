// Hashtable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Minheap.h"
#include "node.h"

class Hashtable {
	// Hash table using seperate chaining, implemented as array of nodes
	
	public:
		Hashtable();
		~Hashtable();

		// PUBLIC METHODS
		bool insert(int i);
		bool lookup(int i);
		bool deleteMin(int i);
		bool deleteItem(int i);
		void print();

	private:
		int size;
		node* *hashArray;  // array of pointers to the head of a linkedlist of nodes

};

#endif
