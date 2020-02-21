// Quash.cpp

#include "Quash.h"
#include <iostream>
using namespace std;

Quash::Quash() { heap.hashLink = &hash; }  // Hashtable/Minheap hash/heap constructors called automatically

Quash::~Quash() {}

int Quash::insert(int i) {
	// insert i in heapArray & hashArray, link the two nodes
	// return count of i after insert (1 if not already in table, count>1 if already in table)
	node *heapNode = heap.insert(i);  // creates new node in heapArray w/ value=i, returns a pointer to node created
	node *hashNode = hash.insert(i);  // creates new node in hashArray, sets newHashNode = node created
		// both insert methods for heap/hash each create new node in correct index in each array
		// then set that node's value=i, the method returns a pointer to the new node created

	if (hashNode==0 || heapNode==0) return 0;  // means something went wrong, didnt insert

	// link nodes
	heap.heapArray[heapNode->index]->link = hash.hashArray[hashNode->index];
	hash.hashArray[hashNode->index]->link = heap.heapArray[heapNode->index];

	return heapNode->count;  // return count of i after insertion
}

int Quash::lookup(int i) { 
	// returns count of i in Quash
	node *n = hash.lookup(i);  // get node, if nullptr count==0
	if (n) return n->count;
	return 0; 
}

int Quash::deleteItem(int i) { return 0; }

pair<int,int> Quash::deleteMin() { return pair<int,int>(0,0); }

void Quash::print() { cout << "printed" << endl;}

