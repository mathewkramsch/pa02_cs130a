// Minheap.h

#ifndef MINHEAP_H
#define MINHEAP_H
#include "Hashtable.h"
#include "node.h"
#include <utility>

class Minheap {
	// Minheap implemented as array of nodes

	public:
		Minheap();
		~Minheap();

		// PUBLIC METHODS
		int insert(int i);
		int lookup(int i);
		int deleteItem(int i);
		std::pair<int,int> deleteMin();
		void print();

	private:
		int size;
		node* *heapArray;  // arary of pointers to nodes

};

#endif
