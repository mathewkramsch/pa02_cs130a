// node.h

#ifndef NODE_H
#define NODE_H

struct node {
	node(int v,int c): value(v),count(c),next(0),link(0) {}
	int value;
	int count;
	node *next;
	node *link;  // pointer to hashArray/heapArray's corresponding node
};

#endif
