// Minheap.cpp

#include "Minheap.h"
#include <iostream>  // DELETE
using namespace std;

Minheap::Minheap() {
	heapArray = new node*[20]{nullptr};  // make heapArray point to an array on heap (array of node pointers)

	numElements = 0;
	// IF I WANNA MAKE IT ON THE STACK
	// heapArray[size];
	// for (int i=0; i<20; i++) heapArray[i]=nullptr;
}

Minheap::~Minheap() {
	for (int i=0; i<20; i++) {  // to delete the nodes on heap that each element in heapArray points to
		if (heapArray[i]!=nullptr) { 
			delete heapArray[i];
		}
	}	
	delete [] heapArray;  // delete array on heap (array of node pointers)
}

node* Minheap::insert(int i) {
	// create node in correct index of heapArray with value=i or increment count of already existing node
		// use lookup to determine if node exists already 
	// returns a pointer to the new node created
	
	cout << "\n\t\t[INSERT]: " << i << endl;
	
	if (numElements >= 20) cout << "overload error" << endl;  // DELETE


	node *n = lookup(i);  // this returns the node in hashArray (n is a hashNode)
	if (n) {  // if node exists, increment both counts
		int indexOfLinkedHeapNode = n->index;  // hashNodes(n) store the index of their linked heapNode in index field
		cout << "[indexOfLinkedHeapNode]: " << indexOfLinkedHeapNode << endl;
		heapArray[indexOfLinkedHeapNode] = n->link;  // increment node in heapArray linked with node in hashArray
		heapArray[indexOfLinkedHeapNode]->count += 1;
		// n = minHeapNode;  // now make n = to minHeapNode so can return n at the end
		return heapArray[indexOfLinkedHeapNode];
	}
	else {  // if node != exist, make a new node in correct place in heapArray
		// leave node's next=nullptr bc not a linkedlist
		// leave link=nullptr, link is set in Quash::insert
		heapArray[numElements] = new node(i,1,numElements);  // add node to end of array, then increment numElements
		n = heapify_up(heapArray[numElements++]);  // restore heap property to heapArray
	}
	return n;
}

node* Minheap::lookup(int i) { 
	cout << "Minheap::lookup\n";
	// returns node pointer to correct element in heapArray, nullptr if not found
	// use Hashitable's lookup to return pointer (quicker)

	return hashLink->lookup(i);
}

int Minheap::deleteItem(node *n) {  // this is only called with item actually needs to be deleted
	// node n is a pointer to the node in heapArray that needs to be deleted
	cout << "Minheap::deleteItem\n";

	int index = n->index;
	if (n->value==heapArray[numElements-1]->value) { 
		cout << "delete n\n"; 
		delete n;
		numElements--;
		cout << "wont get past here\n";
	}
	else {
		heapArray[index] = heapArray[numElements-1];
		delete heapArray[--numElements];
		heapify_down(heapArray[index]);  // restore heap property
	}
	return 0; 
}

pair<int,int> Minheap::deleteMin() { return pair<int,int>(0,0); }

void Minheap::print() {
	for (int i=0; i<numElements; i++) 
		cout << heapArray[i]->value << "," << heapArray[i]->count << " ";
	cout << endl;
	
}

node* Minheap::heapify_up(node *n) {
	// restores heap property to array after insertion
	// if new key > parent dont do anything, otherwise use bubble-up swaps till fixed
		// recursive method: assumes everything heapified except for last element
		// initial node* n should be at the end of heapArray	

	cout << "heapify_up" << endl;

	// int prevci;
	int prevci;

	int ci = n->index;  // current index
	int pi = (ci-1)/2;  // parent of current's index
	if (ci==0) return n;  // this means heapArray only has 1 node, so satisfies heap property

	while (heapArray[pi]->value > n->value) {  // if parent < current, swap
		node *tmp = heapArray[pi];
		heapArray[pi] = n;  // set node @ parent index = n
		heapArray[ci] = tmp;  // set n = to temporary copy of parent
		tmp=nullptr;
		// prevci=ci;
		prevci=ci;
		ci = pi;
		pi = (ci-1)/2;

			cout << "\t[VALUE SWAPPED UP]: " << heapArray[ci]->value << endl;
			cout << "\t[INDEX STORED IN VALUE]: " << heapArray[ci]->index << endl;
		heapArray[prevci]->index = prevci;
		if (heapArray[prevci]->link) heapArray[prevci]->link->index = prevci;
		heapArray[ci]->index = ci;
		if (heapArray[ci]->link) heapArray[ci]->link->index = ci;
			cout << "\t[NEW INDEX STORED IN VALUE]: " << heapArray[ci]->index << endl;
			cout << "\t[NEW INDEX STORED IN SWAPPED VALUE]: " << heapArray[prevci]->index << endl;
	}
	return heapArray[ci];
}

void Minheap::heapify_down(node *n) {
	cout << "heapify_down\n";
	// restores heap property to array after deletion
	int ci = n->index;  // current index
	int li;  // left child index
	int ri;  // right child index
	node *tmp;

	while (2*ci < numElements) {  // while n has a child node (1 or 2)
		li = 2*ci;
		ri = 2*ci;
		if (ri < numElements) {  // if n has 2 children
			if (heapArray[ci] < heapArray[li] && heapArray[ci] < heapArray[ri]) break;  // this satisfies minheap
			else if (heapArray[li] < heapArray[ri]) {  // swap with left child
				tmp = new node(0,0);
				tmp = heapArray[li];
				heapArray[li] = n;
				heapArray[ci] = tmp;
				ci = li;
			} else {  // swap with right child
				tmp = new node(0,0);
				tmp = heapArray[ri];
				heapArray[ri] = n;
				heapArray[ci] = tmp;
				ci = ri;
			}
		}
		else {  // n has 1 child (left child)
			if (heapArray[ci] < heapArray[li]) break;  // this satisfies minheap
			else {  // left child is smaller, swap with n
				tmp = new node(0,0);
				tmp = heapArray[li];
				heapArray[li] = n;
				heapArray[ci] = tmp;
				ci = li;
			}
		}
	}
}
