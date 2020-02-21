// Hashtable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Minheap.h"
#include "node.h"
#include <utility>

class Hashtable {
	// Hash table using seperate chaining, implemented as array of nodes
	
	public:
		Hashtable();
		~Hashtable();

		// PUBLIC METHODS
		int insert(int i);
		int lookup(int i);
		int deleteItem(int i);
		std::pair<int,int> deleteMin();
		void print();

	private:
		int size;
		node* *hashArray;  // array of pointers to the head of a linkedlist of nodes

};

#endif
