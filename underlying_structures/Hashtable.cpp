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

	int index = i%43;
	if (i<0) index += 43;

	node *n = hashArray[index];
	while (n) {  // traverse through linkedlist at hashArray[index], search for node w/ value;
		if (n->value == i) return n;
		n = n->next;
	}
	return nullptr; 
}

pair<int,int> Hashtable::deleteItem(int i) { 
	// i = value of node to be deleted
	// p.first = count after deletion 
	// p.second = index of node in heapArray that needs to be deleted completely

	// delete i from hashArray (use lookup)
		// if in table, decrement
			// if count after delete > 1
				// decrement both
			// else 
				// set = nullptr
				// call heap delete
		// if not in table, return -1
	// return count after delete

	node *n = lookup(i);
	pair<int,int> p;
	p.second = -1;

	if (!n) p.first = -1;  // not in table}
	else if (n->count>1) {  // decrement both
		n->count--;
		n->link->count--;
		p.first = n->count;
	}
	else if (n->count==1) {  // count==1, delete completely
		int index = i%43;
		if (i<0) index += 43;

		node *n2 = hashArray[index];

		if (n2->next) {
			while (n2->next) {
				if (n2->next->value==i) {
					p.second = n2->next->index;
					node *tmp = n2->next;
					n2->next = tmp->next;
					delete tmp;
				}
				n2=n2->next;
			}
		} else {  // then n2 is the head of a 1 node linked list
			p.second = n2->index;
			hashArray[index] = n2->next;
			delete n2;
		}
		p.first = 0;  // count after deletion =0, aka deleted
	}
	return p;
}

void Hashtable::deleteMin(int i) {
	// i is the value of the node to be deleted, deletes node completely from hashtArray
		
	deleteItem(i);	
}

void Hashtable::print() {
	cout << "hashArray (val,count,index): ";
	for (int i=0; i<43; i++) {
		node *n = hashArray[i];
		while (n) {
			cout << hashArray[i]->value << "," << hashArray[i]->count << ",";
			cout << hashArray[i]->index << " ";
			n=n->next;
		}
	}
	cout << endl;
}
	

