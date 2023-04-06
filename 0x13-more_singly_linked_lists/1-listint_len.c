#include"lists.h"
#include <stdio.h>

/**
 * listint_len - a function that returns number of elements in listint_t list
 *
 * @h: A pointer to head of list_t list
 *
 * Return: the number of elements
 */

size_t listint_len(const listint_t *h)

{
	size_t nodes = 0;

	if (h == NULL)
	{
		return (nodes);
	}

	do {
		nodes++;
		h = h->next;
	} while (h != NULL);

	return (nodes);
}
