// Minheap.cpp

#include "Minheap.h"
#include <iostream>  // DELETE
using namespace std;

Minheap::Minheap() {
	numElements = 0;
	heapArray = new node*[20]{nullptr};  // make heapArray point to an array on heap (array of node pointers)

	// IF I WANNA MAKE IT ON THE STACK
	// heapArray[size];
	// for (int i=0; i<20; i++) heapArray[i]=nullptr;
}

Minheap::~Minheap() {
	for (int i=0; i<20; i++) {  // to delete the nodes on heap that each element in heapArray points to
		if (heapArray[i]!=nullptr) delete heapArray[i];
	}	
	delete [] heapArray;  // delete array on heap (array of node pointers)
}

node* Minheap::insert(int i) {
	// create node in correct index of heapArray with value=i or increment count of already existing node
		// use lookup to determine if node exists already 
	// returns a pointer to the new node created
	
	if (numElements >= 20) cout << "overload error" << endl;  // DELETE

	node *n = lookup(i);  // this returns the node in hashArray
	if (n) {  // if node exists, increment both counts
		node *minHeapNode = n->link;  // increment node in heapArray linked with node in hashArray
		minHeapNode->count++;
		n = minHeapNode;  // now make n = to minHeapNode so can return n at the end
	}
	else {  // if node != exist, make a new node in correct place in heapArray
		// leave node's next=nullptr bc not a linkedlist
		// leave link=nullptr, link is set in Quash::insert
		n = new node(i,1,numElements);
		heapArray[numElements++] = n;  // add node to end of array, then increment numElements
		heapify_up(n);  // restore heap property to heapArray
	}

	cout << "\tinserted " << i << " to minheap at index: " << numElements-1 << endl;
	return n;
}

node* Minheap::lookup(int i) { 
	// returns node pointer to correct element in heapArray, nullptr if not found
	// use Hashitable's lookup to return pointer (quicker)

	return hashLink->lookup(i);
}

int Minheap::deleteItem(int i) { return 0; }

pair<int,int> Minheap::deleteMin() { return pair<int,int>(0,0); }

void Minheap::print() {}

void Minheap::heapify_up(node *n) {
	// restores heap property to arrray after insertion/deletion
	// if new key > parent dont do anything, otherwise use bubble-up swaps till fixed
		// recursive method: assumes everything heapified except for last element
		// initial node* n should be at the end of heapArray	

	int ci = n->index;  // current index
	int pi = (ci-1)/2;  // parent of current's index
	if (ci==0) return;  // this means heapArray only has 1 node, so satisfies heap property

	node *tmp_pn = heapArray[pi];  // temporary copy of parent node
	if (tmp_pn->value < n->value) {  // if parent < current, swap
		cout << "\theapify_up" <<endl;
		heapArray[pi] = n;  // set node @ parent index = n
		n = tmp_pn;  // set n = to parent
		heapify_up(n);
	}  // else, heap property is restored, do nothing
}
