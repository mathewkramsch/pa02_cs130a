// Hashtable.cpp

#include "Hashtable.h"
#include <iostream>
using namespace std;

Hashtable::Hashtable() {
	size = 43;  // size 43 bc hash function is mod 43
	hashArray = new node*[43]{nullptr};
}

Hashtable::~Hashtable() {
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

node* Hashtable::insert(int i) { 
	// create new node in correct index in hashArray (use hash function mod 43)
		// if node already exists, increment count
	// set that node's value=i, return a pointer to new node created
	
	cout << "Hashtable::insert\n";
	
	int index = i%43;
	if (i<0) index += 43;

	node *n = lookup(i);  // returns node w/ value=i or nullptr if node != exist
	while (n) {  // traverse through linkedlist until correct node found
		if (n->value==i) {  		
			hashArray[index]->count++;  // increment node in hashArray;
			break;
		}
		else n=n->next;  // else go to next node in linkedlist
	}
	if (!n) {
		n = new node(i,1);  // if node != exist add new node to end of linkedlist at hashArray[index]
			// n must be either head of empty or tail of linkedlist
		hashArray[index] = n;
	}
	
	return n; 
}

node* Hashtable::lookup(int i) { 
	cout << "Hashtable::lookup\n";
	int index = i%43;
	if (i<0) index += 43;

	node *n = hashArray[index];
	while (n) {  // traverse through linkedlist at hashArray[index], search for node w/ value;
		if (n->value == i) { 
			if (!n->link) cout << "link not set\n"; 
			return n;
		}
		n = n->next;
	}
	return nullptr; 
}

int Hashtable::deleteItem(int i) { 
	// delete i from hashArray (use lookup)
		// if in table, decrement
			// if count after delete > 1
				// decrement both
			// else 
				// set = nullptr
				// call heap delete
		// if not in table, return -1
	// return count after delete

	cout << "Hashtable::deleteItem\n";

	node *n = lookup(i);
	if (n) {
		if (n->count>1) {  // decrement both
			n->count--;
			n->link->count--;
			return n->count;
		}
		else {  // count==1, delete both
			int index = n->value%43;
			if (n->value<0) index += 43;
			heapLink->deleteItem(n->link);  // call Minheap's delete method
			n = hashArray[index];  // set n = to head of list
			if (!n->next) delete n;
			else while (n->next) {
				node *rm = n->next;
				if (rm->value==i) {
					n->next = rm->next;
					delete rm;
				}
				n=n->next;
			}
			return 0;
		}
	}
	return -1;  // count==0, so not in table. return -1
}

pair<int,int> Hashtable::deleteMin() { return pair<int,int>(0,0); }

void Hashtable::print() {
	for (int i=0; i<43; i++)
		if (hashArray[i]!=nullptr) cout << hashArray[i]->value << "," << hashArray[i]->count << " ";
	cout << endl;
}
	

