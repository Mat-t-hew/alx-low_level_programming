#include"lists.h"
#include <stdio.h>

/**
 * delete_nodeint_at_index - function that deletes node at index idx of
 * listint_t linked list
 *
 * @head: pointer to the head node
 *
 * @idx: index of node that should be deleted. Index starts at 0
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int idx)
{
	listint_t *last, *present;
	unsigned int a;

	if (*head == NULL)
	{
		return (-1);
	}

	if (idx == 0)
	{
		present = *head;
		*head = (*head)->next;
		free(present);
		return (1);
	}

	last = *head;
	for (a =  0; a < idx - 1 && last != NULL; a++)
		last = last->next;

	if (last == NULL || last->next == NULL)
	{
		return (-1);
	}

	present = last->next;
	last->next = present->next;
	free(present);

	return (1);
}
