#include <stddef.h>

/**
 * dlistint_len - computes the number of nodes in a list
 * @h: pointer to head node of the list
 * Return: number of nodes
*/

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return count;
}
