#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/*
typedef int Data;

struct Node
{
	Data data;
	struct Node * next;
	struct Node * prev;
};
*/

void list_init(struct Node* list)
{
	list -> prev = list;
	list -> next = list;
}


void list_insert(struct Node* list, struct Node *t)
{
	t->prev = list;
	t->next = list->next;
	list -> next -> prev = t;
	list -> next = t;
}

void list_insert_before(struct Node* list, struct Node* t)
{
	list_insert(list -> prev, t);
}

void list_remove(struct Node* t)
{
	struct Node* q = t -> prev;
	struct Node* p = t -> next;
	q -> next = p;
	p -> prev = q;
}

struct Node* list_push_front(struct Node* list, Data d)
{
	struct Node* rut = (struct Node*)calloc(1, sizeof(struct Node));
	rut -> data = d;

	rut->prev = list;
	rut->next = list->next;
	list -> next -> prev = rut;
	list -> next = rut;
	return rut;
}

struct Node* list_push_back(struct Node* list, Data d)
{
	return list_push_front(list -> prev, d);
}

Data list_pop_front(struct Node* list)
{
	return list_delete(list -> next);
}

Data list_pop_back(struct Node* list)
{
	return list_delete(list -> prev);
}

Data list_delete(struct Node * t)
{
	Data value;
	value = t -> data;
	list_remove(t);
	free(t);
	return value;
}

void list_print(struct Node* list)
{
	struct Node* t;
	for(t = (list -> next); t != list; t = t -> next)
	{
		printf("%d ", t -> data);
	}
	printf("\n");
}


int list_is_empty(struct Node * list)
{
	int flag = 0;
	if(list -> next == list)
		flag = 1;
	else
		flag = 0;
	return flag;
}

void list_clear(struct Node * list)
{
	while(!(list_is_empty(list)))
	{
		list_pop_front(list);
	}
}

