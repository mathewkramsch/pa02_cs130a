// node.h

#ifndef NODE_H
#define NODE_H

struct node {
	node(int v,int c): value(v),count(c),next(0),link(0) {}
	int value;
	int count;
	node *next;  // pointer to next node in linkedlist (points to nullptr in heapArray nodes)
	node *link;  // pointer to hashArray/heapArray's corresponding node
};

#endif
