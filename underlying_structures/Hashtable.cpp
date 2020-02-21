// Hashtable.cpp

#include "Hashtable.h"
#include <iostream>
using namespace std;

Hashtable::Hashtable() {
	cout << "Hashtable()" << endl;
	size = 43;  // size 43 bc hash function is mod 43
	hashArray = new node*[43]{nullptr};
}

Hashtable::~Hashtable() {
	cout << "~Hashtable()" << endl;
	// each element in hashArray points to the head of a linkedlist on heap
	for (int i=0; i<43; i++) {  // to delete the linkedlist on heap
		node *n = hashArray[i];  // now n points to same node (head) that element i in hashArray points to
		while(n) {  // delete every node in linked list
			node *tmp = n;
			n = n->next;
			delete tmp;
		}
	}  // now each element in hashArray is a pointer to nullptr
	delete [] hashArray;  // but you still gotta delete hashArray bc that shits on the heap bruh
}

int Hashtable::insert(int i) { return 0; }

int Hashtable::lookup(int i) { return 0; }

int Hashtable::deleteItem(int i) { return 0; }

pair<int,int> Hashtable::deleteMin() { return pair<int,int>(0,0); }

void Hashtable::print() {}

