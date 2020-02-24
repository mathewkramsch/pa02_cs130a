// Quash.h

#ifndef QUASH_H
#define QUASH_H
#include "underlying_structures/Hashtable.h"
#include "underlying_structures/Minheap.h"
#include <utility>

class Quash {

	public:
		Quash();
		~Quash();
		
		// PUBLIC METHODS
		int insert(int i);  // returns count of i in quash after insert
		int lookup(int i);  // returns count of i in quash
		int deleteItem(int i);  // returns count of i in quash after delete, -1 if not found
		std::pair<int,int> deleteMin();  // .first=(the item deleted) .second=(new count of min item, -1 if empty table)
		void print();  // prints Minheap array with elements seperated by whitespace

		void debugPrint();

	private:
		Minheap heap;  // minheap implemented as array of ints
		Hashtable hash;  // hashtable implemented as array of nodes

};

#endif
