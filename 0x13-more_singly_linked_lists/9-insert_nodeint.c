#include"lists.h"
#include <stdio.h>

/**
 * insert_nodeint_at_index - a function that inserts new node at given position
 *
 * @head: pointer to the head node
 *
 * @idx: index of the list where new node should be added
 *
 * @n: interger to be added in new node
 *
 * Return: address of new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new__x, *present;
	unsigned int a = 0;

	if (head == NULL)
	{
		return (NULL);
	}

	new__x = malloc(sizeof(listint_t));

	if (new__x == NULL)
	{
		return (NULL);
	}

	new__x->n = n;
	present = *head;

	if (idx == 0)
	{
		new__x->next = *head;
		*head = new__x;
		return (new__x);
	}

	do {
		if (a == idx - 1 && present != NULL)
		{
			new__x->next = present->next;
			present->next = new__x;
			return (new__x);
		}

		present = present->next;
		a++;
	} while (present != NULL);

	free(new__x);
	return (NULL);
}
