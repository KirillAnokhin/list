#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void list_init(struct Node * list);

void list_insert(struct Node * list, struct Node * t);
void list_insert_before(struct Node * list, struct Node * t);
void list_remove(struct Node * t);

struct Node * list_push_front(struct Node * list, Data d);
struct Node * list_push_back(struct Node * list, Data d);

Data list_pop_front(struct Node * list);
Data list_pop_back(struct Node * list);
Data list_delete(struct Node * t);

void list_print (struct Node * list);
int list_is_empty(struct Node * list);

void list_clear(struct Node * list);

int main()
{
    int i = 0;
	struct Node x[10];
	struct Node * a = malloc(sizeof(struct Node));
	struct Node * b = malloc(sizeof(struct Node));

	list_init(a);
	list_init(b);
	// End of test 1

	for(i=0; i<10; i++) {
		x[i].data = i;
		list_insert(a, &x[i]);
	}
	list_print(a);   // 9 8 7 6 5 4 3 2 1 0
	// End of test 2

	list_remove(&x[5]);
	list_print(a);
	list_remove(&x[0]);
	list_print(a);
	list_remove(&x[9]);
	list_print(a);
	// End of test 3

	list_insert_before(a, &x[0]);
	list_print(a);
	list_insert(a, &x[9]);
	list_print(a);
	list_insert(&x[6], &x[5]);
	list_print(a);
	// End of test 4

	while(!list_is_empty(a))
		list_remove(a->next);
	list_print(a);
	// End of test 5

	for(i=0; i<10; i++)
		list_push_back(a, i);
	list_print(a);

	// End of test 6

	for(i=0; i<10; i++)
		list_push_front(b, list_pop_back(a));
	list_print(b);
	// End of test 7

	for(i=0; i<10; i++) {
		list_push_front(a, i);
		list_pop_front(b);
	}
	list_print(a);
	// End of test 8

	for(i=0; i<10; i++)
		list_push_back(b, list_pop_front(a));
	list_print(b);
	// End of test 9

	list_clear(a);
	list_clear(b);
	// End of test 10

	return 0;
}
