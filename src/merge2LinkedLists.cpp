/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *a, struct node *b) {
	struct node* result = NULL;
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	else if (a->num >= b->num)
	{
		result = b;
		result->next = merge2LinkedLists(a, b->next);
	}
	else
	{
		result = a;
		result->next = merge2LinkedLists(a->next, b);
	}
	return result;
}
