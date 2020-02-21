// node.h

#ifndef NODE_H
#define NODE_H

struct node {
	node(int v,int c=0,int i=-1,node *n=0, node *l=0): value(v),count(c),index(i),next(n),link(l) {}
	int value;
	int count;
	int index;  // used only in Minheap to keep track of what index in heapArray node is in
	node *next;  // pointer to next node in linkedlist (points to nullptr in heapArray nodes)
	node *link;  // pointer to hashArray/heapArray's corresponding node
	node& operator =(const node &right);
};

#endif
