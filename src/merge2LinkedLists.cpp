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

struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{
	struct node *temp, *head;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL)
		head = head2;
	else if (head2 == NULL)
		head = head1;
	else
	{
		if (head1->num < head2->num)
		{
			head = head1;
			head1 = head1->next;
			temp = head;
		}
		else
		{
			head = head2;
			head2 = head2->next;
			temp = head;
		}
		while (head1 != NULL && head2 != NULL)
		{
			if (head1->num < head2->num)
			{
				temp->next = head1;
				head1 = head1->next;
				temp = temp->next;
			}
			else
			{
				temp->next = head2;
				head2 = head2->next;
				temp = temp->next;
			}
		}
		while (head1 != NULL)
		{
			temp->next = head1;
			head1 = head1->next;
			temp = temp->next;
		}
		while (head2 != NULL)
		{
			temp->next = head2;
			head2 = head2->next;
			temp = temp->next;
		}
	}
	return head;
}
