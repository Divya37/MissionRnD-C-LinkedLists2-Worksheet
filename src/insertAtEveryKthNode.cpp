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

struct node * insertAtEveryKthNode(struct node *head, int K)
{
	struct node *temp, *new_node, *prev;
	int count = 0;
	if (K <= 0 || head == NULL)
		return NULL;
	temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	
	if (K > count)
		return head;
	
	prev = head;
	temp = prev->next;
	for (int i = 1; i <= count; i++)
	{
		if (i%K == 0)
		{
			new_node = (struct node*)malloc(sizeof(struct node));

			prev->next = new_node;
			new_node->num = K;
			new_node->next = temp;
		}
		prev = temp;
		if (temp->next == NULL)
			break;
		temp = temp->next;
	}
	if (K == 1)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		temp->next = new_node;
		new_node->num = K;
		new_node->next = NULL;
	}

	return head;
}
