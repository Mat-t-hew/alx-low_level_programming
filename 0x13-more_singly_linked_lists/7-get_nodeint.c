#include"lists.h"
#include <stdio.h>

/**
 * get_nodeint_at_index - A function that returns the nth node of a linked list
 *
 * @head: pointer to node of head of linked list
 *
 * @index: is the index of the node, starting at 0
 *
 * Return: nth node of linked list, or NULL if it does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *present = head;
	unsigned int n = 0;

	while (n < index && present != NULL)
	{
		present = present->next;
		n++;
	}

	if (n == index && present != NULL)
	{
		return (present);
	}

	return (NULL);
}
