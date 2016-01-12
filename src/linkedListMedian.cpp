/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL) return -1;
	struct node* p1 = head->next;
	struct node* p2 = head;
	//LLnode* p=NULL;
	while (p1 != NULL && p1->next != NULL)
	{
		p2 = p2->next;
		p1 = p1->next->next;
	}
	if (p1 == NULL)
	{
		return p2->num;
	}
	return (p2->num + p2->next->num) / 2;
}
