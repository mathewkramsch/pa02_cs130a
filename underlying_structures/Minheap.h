// Minheap.h

#ifndef MINHEAP_H
#define MINHEAP_H
#include "Hashtable.h"
#include "node.h"
#include <utility>

class Hashtable;  // forward declaration

class Minheap {
	// Minheap implemented as array of nodes

	public:
		Minheap();
		~Minheap();
		Hashtable *hashLink;  // set = to Hashtable object created in Quash() (to use hashtable's lookup)

		// PUBLIC METHODS
		node* insert(int i);
		node* lookup(int i);
		int deleteItem(int i);
		std::pair<int,int> deleteMin();
		void print();
		void setLink(node *n);
	
		node* *heapArray;  // arary of pointers to nodes

	private:
		int numElements;  // # nodes in heapArray (ignoring count for each node)

		// HELPER METHODS
		void heapify_up(node *n);

};

#endif
