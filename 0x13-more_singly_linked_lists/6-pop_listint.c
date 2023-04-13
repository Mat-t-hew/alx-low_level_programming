#include"lists.h"
#include <stdio.h>

/**
 * pop_listint - function that delete head node of listint_t linked list
 * & returns head node data
 *
 * @head: pointer to node of head of linked list
 *
 * Return: if the linked list is empty return 0
 */

int pop_listint(listint_t **head)
{
	int x = 0;
	listint_t *present = NULL;

	if (*head != NULL)
	{
		x = (*head)->n;
		present = *head;
		*head = (*head)->next;
		free(present);

		return (x);
	}
	else
		return (0);
}
