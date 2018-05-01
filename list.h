#ifndef _list_h_
#define _list_h_

typedef int Data;

struct Node
{
	Data data;
	struct Node * next;
	struct Node * prev;
};

#endif
