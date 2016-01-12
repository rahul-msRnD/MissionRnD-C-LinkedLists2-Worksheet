/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * insertAtEveryKthNode(struct node *head, int k) {
	if (head == NULL || k<1) return NULL;
	int count;
	struct node *p1 = head, *p2 ;
	while (p1 != NULL)
	{
		count = 1;
		while (count < k)
		{
			if (p1 == NULL || p1->next == NULL)
				return head;
			p1 = p1->next;
			count++;
		}
		struct node *n = createNode(k);
		p2 = p1->next;
		p1->next = n;
		n->next = p2;
		if (p1 != NULL)
			p1 = p2;
			
	}
	return head;
}
