// Minheap.h

#ifndef MINHEAP_H
#define MINHEAP_H
#include "Hashtable.h"
#include "node.h"

class Minheap {
	// Minheap implemented as array of nodes

	public:
		Minheap();
		~Minheap();

		// PUBLIC METHODS
		bool insert(int i);
		bool lookup(int i);
		bool deleteMin(int i);
		bool deleteItem(int i);
		void print();

	private:
		int size;
		node* *heapArray;  // arary of pointers to nodes

};

#endif
