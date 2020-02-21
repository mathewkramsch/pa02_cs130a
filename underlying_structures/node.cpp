// node.cpp

#include "node.h"
#include <iostream>
using namespace std;

node& node::operator =(const node &right) {
	if (this==&right) return *this;
	value = right.value;
	count = right.count;
	index = right.index;
	next = right.next;
	link = right.link;
	return *this;
}
