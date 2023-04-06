#include"lists.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * listint_len - a function that returns number of elements in listint_t list
 *
 * @h: A pointer to head of list_t list
 *
 * Return: the number of elements
 */

int main(void)

{
	size_t listint_len(const listint_t *h)
	{

	size_t node;

	node = 0;

	do {
		printf("%d\n", h->n);
		node++;
		h = h->next;
	} while (h != NULL);
	return (node);
	}
}
