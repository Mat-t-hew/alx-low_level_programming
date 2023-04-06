#include"lists.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * @print_listint: A function that prints all the elements of a listint_t list
 *
 * @h: A pointer to head of list_t list
 *
 * Return: Always s (Success)
 */

size_t print_listint(const listint_t *h)

{
	size_t s;

	s = 0;

	do {
		printf("%d\n", h->n);
		s++;
		h = h->next;
	} while (h != NULL);
	return (s);
}
