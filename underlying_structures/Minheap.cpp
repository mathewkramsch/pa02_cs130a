// Minheap.cpp

#include "Minheap.h"
#include <iostream>  // delete
using namespace std;

Minheap::Minheap() {
	cout << "Minheap()" << endl;
	size = 20;
	heapArray = new node*[20]{nullptr};  // make heapArray point to an array on heap (array of node pointers)

	// IF I WANNA MAKE IT ON THE STACK
	// heapArray[size];
	// for (int i=0; i<20; i++) heapArray[i]=nullptr;
}

Minheap::~Minheap() {
	cout << "~Minheap()" << endl;
	for (int i=0; i<20; i++) {  // to delete the nodes on heap that each element in heapArray points to
		if (heapArray[i]!=nullptr) delete heapArray[i];
	}	
	delete [] heapArray;  // delete array on heap (array of node pointers)
}

node* Minheap::insert(int i) { 
	return nullptr;
}

int Minheap::lookup(int i) { return 0; }

int Minheap::deleteItem(int i) { return 0; }

pair<int,int> Minheap::deleteMin() { return pair<int,int>(0,0); }

void Minheap::print() {}

