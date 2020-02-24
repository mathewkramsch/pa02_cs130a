// node.cpp

#include "node.h"
#include <iostream>
using namespace std;

node& node::operator =(const node &right) {
	// assumes node has already been created on the heap
	// just changes that node's variable values

	if (this==&right) return *this;
	value = right.value;
	count = right.count;
	index = right.index;
	next = right.next;
	link = right.link;
	return *this;
}
