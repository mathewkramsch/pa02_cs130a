// node.h

#ifndef NODE_H
#define NODE_H

struct node {
	node(int v,int c=0,int i=-1): value(v),count(c),index(i),next(0),link(0) {}
	int value;
	int count;
	int index;  // used only in Minheap to keep track of what index in heapArray node is in
	node *next;  // pointer to next node in linkedlist (points to nullptr in heapArray nodes)
	node *link;  // pointer to hashArray/heapArray's corresponding node
};

#endif
