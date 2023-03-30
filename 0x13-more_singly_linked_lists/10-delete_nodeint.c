#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index
 * @head: head of linked list
 * @index: index of the list where the node
 * is deleted
 * Return: 1 if successful, -1 if it fails
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev, *next;
	unsigned int i;

	prev = *head;

	if (index != 0)
	{
		for (i = 0; i < index - 1 && prev != NULL; i++)
			prev = prev->next;
	}

	if (prev == NULL || (prev->next == NULL && index != 0))
		return (-1);
	next = prev->next;

	if (index != 0)
	{
		prev->next = next->next;
		free(next);
	}
	else
	{
		free(prev);
		*head = next;
	}
	return (1);
}

