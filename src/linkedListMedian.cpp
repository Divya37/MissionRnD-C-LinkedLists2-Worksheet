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
	int count = 0,flag=0;
	struct node *temp;
	if (head == NULL)
		return -1;
	temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	temp = head;
	if (count % 2 == 0)
		flag = 1;
	
	count = count / 2;
	while (count > 0)
	{
		if (flag == 1 && count == 1)
			break;
		temp = temp->next;
		count--;
	}
	if (flag == 1)
		return (temp->num + temp->next->num) / 2;
	else
		return temp->num;
}
