// Quash.h

#ifndef QUASH_H
#define QUASH_H
#include "Hashtable.h"
#include "Minheap.h"

class Quash {

	public:
		Quash();
		~Quash();
		
		// PUBLIC METHODS
		bool insert(int i);
		bool lookup(int i);
		bool deleteMin(int i);
		bool deleteItem(int i);
		void print();

	private:
		Minheap heap;  // minheap implemented as array of ints
		Hashtable hash;  // hashtable implemented as array of nodes

};

#endif
