// Quash.cpp

#include "Quash.h"
#include <iostream>
using namespace std;

Quash::Quash() { 
	heap.hashLink = &hash; 
}  // Hashtable/Minheap hash/heap constructors called automatically

Quash::~Quash() {}

int Quash::insert(int i) {
	// insert i in heapArray & hashArray, link the two nodes
	// return count of i after insert (1 if not already in table, count>1 if already in table)

	int hashIndex = i%43;
	if (i<0) hashIndex+= 43;
	
	node *heapNode = heap.insert(i);  // creates new node in heapArray w/ value=i, returns a pointer to node created
	node *hashNode = hash.insert(i);  // creates new node in hashArray, sets newHashNode = node created
		// both insert methods for heap/hash each create new node in correct index in each array
		// then set that node's value=i, the method returns a pointer to the new node created

	if (hashNode==0 || heapNode==0) return 0;  // means something went wrong, didnt insert

	// link nodes
	heap.heapArray[heapNode->index]->link = hash.hashArray[hashIndex];
	hash.hashArray[hashIndex]->link = heap.heapArray[heapNode->index];
	hash.hashArray[hashIndex]->index = heapNode->index;  // store the heapNode's index in each hashNode


	return hashNode->count;  // return count of i after insertion
}

int Quash::lookup(int i) { 
	// returns count of i in Quash
	node *n = hash.lookup(i);  // get node, if nullptr count==0
	if (n) return n->count;
	return 0; 
}

int Quash::deleteItem(int i) { 
	// delete i from both Minheap and Hashtable
	// return count of item after delete, -1 if item not found (0 if removed completely)
	
	// call hash.deleteItem first
		// if item in table count>1: decrements count for heap and hash w/ link
		// if item in table count==1: deletes from hashArray, returns index of link heapNode
		// if item in table count==0: returns -1, this means not found
	// if hashCount==1: return 1
	// if hashCount==-1: return -1
	// else hashCount == the index of heapNode to delete in heapArray

	pair<int,int> hashCount = hash.deleteItem(i);  // .first = count after delete, .second = index of heapNode
	if (hashCount.first>0) return hashCount.first;
	if (hashCount.first==-1) return -1;
	else if (hashCount.first==0) heap.deleteItem(hashCount.second);  // now just delete that item completely from heapArray
	return 0;  // means item completely removed from hashArray and heapArray
}

pair<int,int> Quash::deleteMin() { 
	// .first = min item deleted
	// .second = count of min item after deletion (-1 if not in table)
	
	// lookup item in heap table, return -1 if not present
		// if n==nullptr
			// p.first = -1
			// p.second = -1
		// p.first = n->value
		// if n->count >1, decrement from hash/heap
			// p.second = n->count-1
		// if n->count==1, deleteHeap to actually delete
			// p.second = 0

	pair<int,int> p(-1,-1);

	if (heap.heapArray[0]==nullptr) return p;
	p.first = heap.heapArray[0]->value;
	if (heap.heapArray[0]->count > 1) {
		cout << "here" << endl;
		// decrement from hash/heap
		heap.heapArray[0]->count--;
		heap.heapArray[0]->link->count--;
		p.second = heap.heapArray[0]->count;
	} else if (heap.heapArray[0]->count==1) {
		// deleteItem to actually delete
		hash.deleteMin(p.first);  // deletes min from hashArray
		heap.deleteMin();  // deletes min from heapArray
		p.second = 0;
	}
	return p; 
}

void Quash::print() { 
	heap.print();
}

void Quash::debugPrint() {
	heap.debugPrint();
	hash.print();
}
