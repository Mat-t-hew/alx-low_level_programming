#include"lists.h"
#include <stdio.h>

/**
 * print_listint - A function that prints all the elements of a listint_t list
 *
 * @h: A pointer to head of list_t list
 *
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)

{
	size_t nodes = 0;

	if (h == NULL)
	{
		return (nodes);
	}

	do {
		printf("%d\n", h->n);
		nodes++;
		h = h->next;
	} while (h != NULL);

	return (nodes);
}
